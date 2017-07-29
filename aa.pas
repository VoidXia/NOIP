var a:array[1..100]of integer;
i,j,ans:integer;

procedure find(i,l,r:integer);
var o:integer;
begin
//    write(l,' ',r);
  //  writeln;
    o:=(l+r)div 2;
    if r-l>1 then begin
        if i>=a[o] then find(i,o,r);
        if i<a[o] then find(i,l,o);
        end;
    if r-l<=1 then writeln(l);
end;

function part(l,r:integer):integer;
var i,j,k,q:integer;
begin
i:=l-1;
k:=a[r];
for j:=l to r-1 do
begin
    if a[j]<k then begin
        inc(i);
        q:=a[j];
        a[j]:=a[i];
        a[i]:=q;
        end;
end;
    q:=a[i+1];
    a[i+1]:=a[r];
    a[r]:=q;
    part:=i+1;
end;

procedure qs(l,r:integer);
var i:integer;
begin
if l<r then begin
i:=part(l,r);
qs(l,i-1);
qs(i+1,r);
end;
end;


begin
randomize;
for i:=1 to 100 do begin a[i]:=random(100); write(a[i],' '); end;
qs(1,100);
writeln;
i:=random(100);
writeln(i);
for j:=1 to 100 do write(a[j],' ');
writeln;
find(i,1,100);

end.