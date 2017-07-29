type arrl = array[0..200] of integer;
var a,b,c:arrl;
    i,j,k:integer;
    s1,s2:string;
procedure minus(a,b:arrl; var c:arrl);
var i:integer;
begin
    for i:=1 to 100 do
        c[i]:=0;
    for i:=1 to 100 do
        begin
            c[i]:=a[i]-b[i]+c[i];
            if c[i]<0 then
                begin
                    c[i]:=c[i]+10;
                    dec(c[i+1]);
                end;
        end;
end;

begin
    readln(s1);
    for i:=1 to length(s1) do
        val(s1[i],a[length(s1)-i+1]);
    for i:=length(s1) downto 1 do
        write(a[i]);
    writeln;
    readln(s2);
    for i:=1 to length(s2) do
        val(s2[i],b[length(s2)-i+1]);
    for i:=length(s2) downto 1 do
        write(b[i]);
    writeln;
    minus(a,b,c);
    j:=100;
    while c[j]<=0 do
        dec(j);
    writeln(j);
    i:=0;
    for i:=j downto 1 do
        write(c[i]);
end.
