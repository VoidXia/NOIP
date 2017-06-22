var a,b:array[1..1000]of integer;
    i,j,k,ans,l:integer;
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
i:=random(1000);
writeln(i);
for j:=1 to i do begin
//randomize;
a[j]:=random(10000);
write(a[j],' ');
end;
writeln;
writeln;
qs(1,i);
for j:=1 to i do write(a[j],' ');
end.

{begin
ans:=0;
readln(k);
for i:=1 to k do 
read(a[i]);
qs(1,k);
//for i:=1 to k do writeln(a[i]);
for i:=1 to k-1 do
for j:=i+1 to k do
for l:=1 to k do begin
if (a[i]+a[j]=a[l])and(b[l]=0) then begin
//write(a[i],' ',a[j],' ');
//write(a[l]);
//writeln;
ans:=ans+1;
b[l]:=1;
end;
end;
write(ans);
end.}