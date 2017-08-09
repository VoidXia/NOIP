uses math;
var 
    a,s:array[0..202]of longint;//两倍空间，用来将环变成线
    f1,f2:array[0..202,0..202]of longint;//f1找最大，f2找最小
    l,i,j,k,n,max1,min1:longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    a[i+n]:=a[i];//将4 9 5 4 变为4 9 5 4 4 9 5 4
  end;
  //for i:=1 to 2*n do write(a[i],' ');writeln;//测试
  for i:=1 to 2*n do s[i]:=s[i-1]+a[i];//把前i堆石子全加起来，存放在s[i]里，备用
  //for i:=1 to 2*n do write(s[i],' ');writeln;//测试
  for l:=2 to n do//l表示区间长度，从两个两个的试，最后到n个n个的试
   for i:=1 to 2*n-l+1 do//i为起点
   begin
     j:=i+l-1;//j为终点
     f1[i,j]:=-maxlongint;f2[i,j]:=maxlongint;//初始化，f1定得特别小，f2定得特别大
     for k:=i to j-1 do//k在i和j之间游走，把区间分成两份
     begin
       f1[i,j]:=max(f1[i,j],f1[i,k]+f1[k+1,j]+s[j]-s[i-1]);//比较原f1[i,j]与f1[i,k]+f1[k+1,j]+s[j]-s[i-1]的大小，存比较大的。f数组存之前算好的得分，s[j]-s[i-1]可以得出本次得分
       f2[i,j]:=min(f2[i,j],f2[i,k]+f2[k+1,j]+s[j]-s[i-1]);//类似上一条
       //writeln(i,' ',j,' ',k,' ',f1[i,j],' ',f2[i,j],' ',f1[i,k],' ',f1[k+1,j]);
       //writeln(f1[i,k]+f1[k+1,j]-s[j]+s[i-1]);
     end;
   end;
  max1:=-maxlongint;min1:=maxlongint;//初始化
  for i:=1 to n do
  begin
    max1:=max(max1,f1[i,i+n-1]);//4 9 5 4 的环，可以分为4 9 5 4，9 5 4 4，5 4 4 9，4 4 9 5，现在是寻找这四种情况那个最大
    min1:=min(min1,f2[i,i+n-1]);//类似上一条
  end;
  writeln(min1);
  writeln(max1);//看清顺序，输出
end.
{
var a:array [0..200000,0..200000] of longint;
b:array [1..200000] of longint;
i,j,k,n,x,y:longint;
sum,max,now:longint;
begin
  max:=0;
  sum:=0;
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
   begin
     readln(x,y);
     inc(a[x,0]);
     a[x,a[x,0]]:=y;
     inc(a[y,0]);
     a[y,a[y,0]]:=x;
   end;
   for i:=1 to n do
     read(b[i]);
   for i:=1 to n do
     for j:=1 to a[i,0] do
       for k:=1 to a[a[i,j],0] do
         if i<>a[a[i,j],k] then
           begin
           now:=b[i]*b[a[a[i,j],k]];
           sum:=(sum+now)mod 10007;
           if max<now then max:=now;
           end;
  write(max,sum);
end.}