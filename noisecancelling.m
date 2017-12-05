%% 谱减法去噪
% 内容：用最简单的谱减法，去除噪声
% 作者：qcy
% 版本：v1.0
% 【注意】谱减完以后，拼接在一起的时候，要去除重复的部分！
% 因为分帧时有可能是有重叠的！！！
% 时间：2016年11月3日19:40:35

clear; clc; close all;
%% 导入音频

filedir='/Users/Administrator/Downloads/';                             % 指定文件路径
filename='Crazy33.m4a';                % 指定文件名
fle=[filedir filename];                 % 构成路径和文件名的字符串
[xx,fs]=audioread(fle);                 % 读入数据文件
xx=xx-mean(xx);                         % 消除直流分量
x=xx/max(abs(xx));                      % 幅值归一化

%% 预先设置参数
IS = 1.6;      % 设置前导无话段长度 [s]
wlen = 200;    % 务必设置为偶数个点
inc = 80;
win = hamming(wlen); % 用矩形窗，也会有问题-_-!
% boxcar 矩形窗
% hamming 汉明窗

N=length(x);                            % 信号长度
time=(0:N-1)/fs;                        % 设置时间
overlap=wlen-inc;                       % 求重叠区长度
NIS=fix((IS*fs-wlen)/inc +1);           % 求前导无话段帧数
Nframe = floor( (length(x) - wlen) / inc) + 1; % 一共多少帧

%% 分帧
% 1) 测量环境噪声的平均能量谱（只需计算非负频率的部分）
k_pos_freq = wlen/2+1; % 非负频率范围
X_noise_engergy_sum = zeros(k_pos_freq,1);

for k = 1 : NIS
    idx = (1:wlen) + (k-1) * inc;
    x_temp = x(idx).*win;
    X_temp = fft(x_temp);
    X_noise_engergy_sum = X_noise_engergy_sum + abs(X_temp(1:k_pos_freq)).^2;
end
X_noise_engergy_avg = X_noise_engergy_sum / NIS;

% 2) 对之后语音每一帧进行谱减
% 3) 注意：重构的时候要重叠相加-_-!
a = 10;
b = 0.002;

Y_ = zeros(wlen,1);
x_subspec = [];

sig=zeros((Nframe-1)*inc+wlen,1);

for k = 1 : Nframe
    idx = (1:wlen) + (k-1) * inc;
    x_temp = x(idx).*win;
    X_temp = fft(x_temp);
    phase_k = angle(X_temp(1:k_pos_freq)); % 1. 先保留信号的相位
    X_energy = abs(X_temp(1:k_pos_freq)).^2;
    
    X_subspec_energy_pos_freq = zeros(k_pos_freq,1); % 谱减以后，非负频率分量的能量
    for m = 1:k_pos_freq % 对每一个频点进行谱减
       if  X_energy(m) >= a * X_noise_engergy_avg(m)
           X_subspec_energy_pos_freq(m) = X_energy(m) - a * X_noise_engergy_avg(m);
       else
           X_subspec_energy_pos_freq(m) = b * X_noise_engergy_avg(m);
       end
    end
    
    X_subspec_abs_pos_freq = sqrt(X_subspec_energy_pos_freq);
    X_subspec_pos_freq = X_subspec_abs_pos_freq .* exp(1j*phase_k); % A = |A|exp(1j*angle(A))
    % 构造Hermitian对称的序列
    X_subspec_at_frame_k = [X_subspec_pos_freq ; conj(X_subspec_pos_freq(end-1:-1:2))];
    x_subspec_at_frame_k = real(ifft(X_subspec_at_frame_k));

%     x_subspec = [x_subspec ; x_subspec_at_frame_k ]; % 直接接上是不行的

      % 重叠相加 -_-! 为什么要重叠相加!!才不会有嘶哑的声音!!!!
      % 由频域重构 -_-! 难道是说，加窗以后变到频域，再变回来，重构，需要重叠相加抵消xx效应?

    start=(k-1)*inc+1;    
    sig(start:start+wlen-1)=sig(start:start+wlen-1) + x_subspec_at_frame_k; % 重叠相加
end

%%
figure;
subplot(211);
plot(x);
title('去噪前');
subplot(212);
plot(sig);
title('去噪后');
sound(sig,fs);