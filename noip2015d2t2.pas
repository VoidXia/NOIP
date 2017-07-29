var a,b:ansistring;
    i,ans,n,m,k,z:integer;

procedure dfs(x,o:integer);
var i:integer;
begin
    for i:=o to n do
    if a[i]=b[x] then begin
    if i<>o then inc(z);

    writeln(a[i],' ',i,' ',z);
        if x<m then dfs(x+1,i+1);
        if (x=m)and(z>=k) then inc(ans);
    if i<>o then dec(z);
        end;
    
    
end;

begin
    readln(n,m,k);
    readln(a);
    readln(b);
    dfs(1,1);
    writeln(ans);
    end.