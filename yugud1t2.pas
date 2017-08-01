const maxn=1000000007;
var n,m,i,j,{a1,a2,b1,b2,}ans:longint;
    a:array[1..501,1..501]of char;


function judge(a1,a2,b1,b2:longint):boolean;
begin
judge:=false;
if (m+n)mod 2=1 then begin
if a[a1,a2]=a[b1,b2] then begin
if (a1=b1) and(a2+1=b2) then judge:=true;
if (a2=b2)and(a1+1=b1) then judge:=true;
end;
end;
end;

procedure dfs(a1,a2,b1,b2:longint);
begin
    
    if (a1=a2)and(b1=b2)and((m+n)mod 2=0) then inc(ans);
    if ans>maxn then ans:=ans mod maxn;
    if (a1<=b1)and(a2<=b2) then begin
        inc(a1); dec(b1);
        if (judge(a1,a2,b1,b2)=true) then inc(ans);
        if (a[a1,a2]=a[b1,b2])and(a[a1,a2]<>'0') then dfs(a1,a2,b1,b2);
        inc(b1); dec(b2);
        if (judge(a1,a2,b1,b2)=true) then inc(ans);
        if (a[a1,a2]=a[b1,b2])and(a[a1,a2]<>'0') then dfs(a1,a2,b1,b2);
        dec(a1); inc(a2);
        if (judge(a1,a2,b1,b2)=true) then inc(ans);
        if (a[a1,a2]=a[b1,b2])and(a[a1,a2]<>'0') then dfs(a1,a2,b1,b2);
        inc(b2); dec(b1);
        if (judge(a1,a2,b1,b2)=true) then inc(ans);
        if (a[a1,a2]=a[b1,b2])and(a[a1,a2]<>'0') then dfs(a1,a2,b1,b2);
        inc(b1); dec(a2);

        end;
    end;


{procedure judge(a1,a2,b1,b2:integer):boolean;
begin
judge:=false;
if a[a1,a2]=a[b1,b2] then begin
if (a1=b1) and(a2+1=b2) then judge:=true;
if (a2=b2)and(a1+1=b1) then judge:=true;
end;
end;
}

    





begin
    readln(n,m);
    fillchar(a,sizeof(a),'0');
    for i:=1 to n do begin
        for j:=1 to m do read(a[i,j]);
        readln;
    end;
    dfs(1,1,n,m);
    ans:=ans mod maxn;
    writeln(ans);


end.
