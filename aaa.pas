var 
    a:array[0..100000] of char;
    ch:char;
    t,i,x,y:longint;
begin
    t:=0;
    repeat
        read(ch);
        if (ch='W') or (ch='L') then
            begin
                inc(t);
                a[t]:=ch;
            end;
    until ch='E';
    x:=0;
    y:=0;
    for i:=1 to t do
        begin
            if a[i]='W' then inc(x);
            if a[i]='L' then inc(y);
            if abs(x-y)>=2 then
                if (x>=11) or (y>=11) then
                    begin
                        writeln(x,':',y);
                        x:=0;
                        y:=0;
                    end;
        end;
    writeln(x,':',y);
    writeln;
    x:=0;
    y:=0;
    for i:=1 to t do
        begin
            if a[i]='W' then inc(x);
            if a[i]='L' then inc(y);
            if abs(x-y)>=2 then
                if (x>=21) or (y>=21) then
                    begin
                        writeln(x,':',y);
                        x:=0;
                        y:=0;
                    end;
        end;
    writeln(x,':',y);
end.
