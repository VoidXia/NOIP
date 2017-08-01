{var a,b,c,m:int64;
begin
    readln(a,b);
    
    c:=1;
    while (a<>b)and(a<>0)and(b<>0) do begin
        c:=c+1;
        if a>b then a:=a-b else b:=b-a;
        
        end;
    
    writeln(c);
end.
}
var a,b,c,m:int64;
begin
    readln(a,b);
    if a=b then c:=1;
    if a<b then begin
    c:=a;
    a:=b;
    b:=c;
    end;
    c:=0;
    while (a<>b)and(a<>0)and(b<>0) do begin
        c:=c+(a div b);
        a:=a mod b;
        m:=a;
        a:=b;
        b:=m;
        end;
    
    writeln(c);
end.