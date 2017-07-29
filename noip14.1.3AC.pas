

program P1907;

uses math;

const maxn = 100000001;

var a,dp:array[-1..10000,0..1000] of longint;
    x,y:array[0..10000] of longint;
    k,m,p,l,h,i,j,ans,n,v:longint;
    ok:boolean;
    have:array[1..10000] of boolean;
begin
    //main
    read(n,m,k);
    fillchar(a,sizeof(a),0);
    fillchar(dp,sizeof(dp),0);
    ans:=maxn;
    fillchar(have,sizeof(have),false);
    for i:=0 to n-1 do
        read(x[i],y[i]);
    for i:=1 to k do
        begin
            read(p,l,h);
            have[p]:=true;
            for j:=0 to l do
                a[p,j]:=maxn;
            for j:=h to m do
                a[p,j]:=maxn;
        end;
    for i:=0 to 1000 do
        a[-1,i]:=maxn;
    for i:=-1 to 10000 do
        a[i,0]:=maxn;
    for i:=-1 to 10000 do
        for j:=0 to 1000 do
            dp[i,j]:=maxn;
    for i:=0 to m do
        if a[0,i]<>maxn then
            dp[0,i]:=0;

    //以上是读入和初始化，注意游戏界面边缘的一些处理哦！
    for i:=1 to n do
        begin
            ok:=false;
            //记录是否还能继续游戏
            for j:=x[i-1]+1 to m do
                //向上飞的完全背包
                begin
                    dp[i,j]:=min(dp[i,j],min(dp[i,j-x[i-1]]+1,dp[i-1,j-x[i-1]]+1));
                    if dp[i,j]>maxn then
                        dp[i,j]:=maxn;
                end;
            for j:=m downto m-x[i-1] do
                //顶部特判
                if a[i,m]<maxn then
                    dp[i,m]:=min(min(dp[i,m],dp[i-1,j]+1),dp[i,j]+1);
            for j:=m-y[i-1] downto 1 do
                //向下掉
                if a[i,j]<maxn then
                    dp[i,j]:=min(dp[i,j],dp[i-1,j+y[i-1]]);
            for j:=1 to m do
                //有水管的地方要改成无限大哦~
                if a[i,j]=maxn then
                    dp[i,j]:=maxn;
            for j:=m downto 1 do
                if dp[i,j]<>maxn then
                    ok:=true;
            if ok=false then
                begin
                    v:=i;
                    break;
                end;
            //已经无解了
        end;
    if ok=false then //无解的答案输出
        begin
            writeln('0');
            ans:=0;
            for i:=1 to v-1 do
                if have[i]=true then
                    inc(ans);
            writeln(ans);
            exit;
        end;
    for i:=m downto 1 do
        //计算有解时候的答案
        begin
            if dp[n,i]<ans then
                ans:=dp[n,i];
        end;
    writeln('1');
    writeln(ans);
    for i:=0 to m do begin
        for j:=0 to n do
            write(dp[i,j],' ');
        writeln;
    end;
    //有解
end.


100000001 0 0 0 0 0 0 0 0 0 0
100000001 100000001 100000001 100000001 1 1 1 100000001 100000001 100000001 100000001
100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001 2
100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001 2 100000001 3
100000001 100000001 100000001 100000001 100000001 2 100000001 3 100000001 3 4
100000001 100000001 100000001 2 100000001 100000001 100000001 100000001 100000001 100000001 100000001
100000001 100000001 100000001 100000001 3 100000001 100000001 100000001 100000001 100000001 100000001
100000001 100000001 100000001 100000001 100000001 100000001 4 100000001 100000001 100000001 100000001
100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001 5 100000001 100000001
100000001 100000001 5 100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001
100000001 100000001 100000001 100000001 6 100000001 7 100000001 8 100000001 9