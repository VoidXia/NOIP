type arr=array[1..10000]of integer;

var a,

function turn(a:integer;var t:integer; var c:arr):integer;
var i:integer;
begin
    inc(t);
    i:=t;
    if (a=1) or (a=0) then turn:=a
    else
        begin
            c[i]:=turn(a div 2,t,c);
            // writeln(i,c[i]);
            turn:=(a mod 2);
        end;

end;