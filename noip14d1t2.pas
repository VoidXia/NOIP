
type edge = record
    u,v:longint;
end;
var 
    w,max1,max2:array[1..200000] of longint;
    s:array[1..200000] of longint;
    a:array[1..200000] of edge;
    n,i,u,v,ans1,ans2:longint;
procedure work(s:longint;var a,b:longint);
begin
    if s>a then
        begin
            b:=a;
            a:=s;
        end
    else
        if s>b then b:=s;
end;
begin
    readln(n);
    for i:=1 to n-1 do
        readln(a[i].u,a[i].v);
    for i:=1 to n do
        read(w[i]);
    for i:=1 to n do
        s[i]:=0;
    ans1:=0;
    ans2:=0;
    for i:=1 to n-1 do
        begin
            u:=a[i].u;
            v:=a[i].v;
            s[u]:=s[u]+w[v];
            s[v]:=s[v]+w[u];
            work(w[v],max1[u],max2[u]);
            work(w[u],max1[v],max2[v]);
        end;
    for i:=1 to n do
        if ans1<max1[i]*max2[i] then ans1:=max1[i]*max2[i];
    for i:=1 to n-1 do
        begin
            u:=a[i].u;
            v:=a[i].v;
            ans2:=(ans2+((s[u]-w[v])*w[v])mod 10007)mod 10007;
            ans2:=(ans2+((s[v]-w[u])*w[u])mod 10007)mod 10007;
        end;
    writeln(ans1,' ',ans2);
end.
