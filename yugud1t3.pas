const maxn=1000000007;
var a:array[1..100000]of longint;
m,n,num,l,r,x,i,j,ans:longint;

function ksm(q,o:longint):longint;
var base,m:longint;
begin
ksm:=1;
base:=q;
m:=o;
base:=base mod maxn;
while m>0 do begin
if (m mod 2=1) then ksm:=(ksm*base)mod maxn;
m:=m div 2;
base:=(base*base)mod maxn;
end;
end;


begin
    read(n,m);
    ans:=0;
    for i:=1 to n do read(a[i]);
    for i:=1 to m do begin
    read(num,l,r,x);
    if num=1 then for j:=l to r do inc(a[j],x);
    if num=2 then for j:=l to r do a[j]:=x;
    if num=3 then for j:=l to r do ans:=(ans+ksm(a[j],x))mod maxn;
    if num=3 then writeln(ans);
    end;
end.