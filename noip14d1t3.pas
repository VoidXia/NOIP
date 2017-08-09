const maxn=1000001;
var a,dp:array[-1..10000,0..1000]of longint;
    x,y:array[0..10000]of longint;
    have:array[0..10000]of boolean;
    n,m,k,i,j,p,l,h,ans,v:longint;
    ok:boolean;

function min(a,b,c:longint):longint;
begin
min:=a;
if min>b then min:=b;
if min>c then min:=c;
end;


begin
    readln(n,m,k);
    for i:=-1 to n do
        for j:=0 to m do begin 
            a[i,j]:=0;
            dp[i,j]:=maxn;
        end;
    ans:=maxn;
    fillchar(have,sizeof(have),false);
    for i:=1 to n do readln(x[i],y[i]);
    for i:=1 to k do begin
        readln(p,l,h);
        have[p]:=true;
        for j:=0 to l do a[p,j]:=maxn;
        for j:=h to m do a[p,j]:=maxn;
    end;
    for i:=0 to m do a[-1,i]:=maxn;
    for i:=0 to n do a[i,0]:=maxn;
    for i:=1 to m do if a[0,i]<>maxn then dp[0,i]:=0;
    
    for i:=0 to n do begin
        ok:=false;
        for j:=x[i] to m do 
            dp[i,j]:=min(dp[i,j],dp[i,j-x[i]]+1,dp[i-1,j-x[i]]+1);
        for j:=m downto m-x[i] do 
          //  if a[i,m]<maxn then
            dp[i,m]:=min(dp[i,m],dp[i-1,j]+1,dp[i,j]+1);
        for j:=m-y[i] downto 1 do 
            dp[i,j]:=min(maxn,dp[i,j],dp[i-1,j+y[i]]);
        for j:=0 to m do 
            if dp[i,j]>maxn then dp[i,j]:=maxn;
        for j:=0 to m do 
            if a[i,j]>=maxn then dp[i,j]:=maxn;
        for j:=0 to m do 
            if dp[i,j]<>maxn then ok:=true;
        if ok=false then begin
            v:=i;
            break;
        end;
    end;
    ans:=0;
    if ok=false then begin
        for j:=0 to v-1 do 
            if have[j]=true then inc(ans);
        writeln('0');
        writeln(ans);
    end;

    if ok=true then begin
        ans:=maxn;
        for j:=0 to m do
            ans:=min(ans,maxn,dp[n,j]);
        writeln('1');
        writeln(ans);
    end;
    {for i:=0 to m do begin
        for j:=0 to n do
            write(dp[i,j],' ');
        writeln;
    end;}
end.

{1000001 0 0 0 0 0 0 0 0 0 0
1000001 1000001 1000001 1000001 1 1 1 1000001 1000001 1000001 1000001
1000001 1000001 1000001 1000001 1000001 1000001 1000001 1000001 1000001 1000001 2
1000001 1000001 1000001 1000001 1000001 1000001 1000001 1000001 3 1000001 3
1000001 1000001 1000001 1000001 1000001 4 1000001 4 1000001 4 4
1000001 1000001 1000001 5 1000001 1000001 1000001 1000001 1000001 1000001 1000001
1000001 1000001 1000001 1000001 6 1000001 1000001 1000001 1000001 1000001 1000001
1000001 1000001 1000001 1000001 1000001 1000001 7 1000001 1000001 1000001 1000001
1000001 1000001 1000001 1000001 1000001 1000001 1000001 1000001 8 1000001 1000001
1000001 1000001 9 1000001 1000001 1000001 1000001 1000001 1000001 1000001 1000001
1000001 1000001 1000001 1000001 10 1000001 11 1000001 12 1000001 13}