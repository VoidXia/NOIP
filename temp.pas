var ans:array[1..10000]of integer;
    w:array[1..200000]of integer;
    conn:array[0..200000,0..200000]of [0..1];
    n,sum,i,j,k,u,v:integer;
begin
    readln(n);
    fillchar(conn,sizeof(conn),0);
    fillchar(ans,sizeof(ans),0);
    fillchar(w,sizeof(w),0);
    for i:=1 to n-1 do begin 
        readln(u,v); 
        conn[u,v]:=1; 
        end;
    for i:=1 to n do read(w[i]);
    
end;
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