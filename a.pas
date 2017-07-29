
type arr = array[1..16] of int64;
    //  arrr=array[1..4,0..2143]of [0..1];

var a: arr;
    i,k: int64;
    //  ha:arrr;

function fact(a:int64): int64;

var i: int64;
begin
    fact := 1;
    for i:=1 to a do
        fact := fact*i;
end;

function encr(a:arr): int64;

var t,nn: int64;
    i,j: int64;
    aa: array[1..16] of int64;
begin
    for i:=1 to 16 do
        aa[i] := i;
    encr := 0;
    i := 0;
    j := 0;
    t := 0;
    nn := 0;
    for i:=1 to 16 do
        begin
            t := aa[a[i]-1]*fact(16-i);
            writeln(t);
            encr := encr+t;
            t := 0;
            for j:=a[i] to 16 do
                dec(aa[j]);
        end;
    //  encr:=encr mod 388211;
end;

function dist(a:arr): int64;

var i: int64;
begin
    dist := 0;
    for i:=1 to 16 do
        if a[i]<>0 then dist := dist+abs(((a[i]-1) div 4)-((i-1) div 4))+abs((a[
                               i]
                               mod 4)-(i mod 4));
end;

begin
    for i:=1 to 16 do
        read(a[i]);
    writeln;
    writeln(1+2+4+1+4+0+3+);
end.
