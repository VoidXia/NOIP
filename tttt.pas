Const
SIZE = 100;
var
n, i, sum, x : integer;
a : array[1..SIZE] of integer;
begin
readln(n);
fillchar(a, sizeof(a), 0); for i:= 1 to n do
begin
read(x);
   inc(a[x]);
  end;
i := 0;
sum := 0;
while sum < (n div 2 + 1) do begin
inc(i);
   sum :=sum + a[i];
  end;
writeln(i); end.
