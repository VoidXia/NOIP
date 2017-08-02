var ans,n,l,k,rrr,i:int64;
function power(a,b:int64):int64;
var i:integer;
begin
power:=1;
for i:=1 to b do power:=power*a;
end;

function shizhishuma(a:int64):boolean;
var i:int64;
begin
    shizhishuma:=true;
    for i:=2 to trunc(sqrt(a)) do
        if a mod i=0 then shizhishuma:=false;
end;

begin
readln(n);
//writeln(shizhishuma(n));
for i:=1 to n do begin
readln(l,k);
ans:=0;
repeat
    inc(ans);
    rrr:=power(2,l);
    if shizhishuma(ans*rrr+1)=true then begin
    dec(k);
   // writeln(ans*rrr);
    end;
until (k=0);
ans:=ans*rrr;
writeln(ans+1);
end;
end.