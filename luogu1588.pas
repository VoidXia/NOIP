var n,i,a,b,ans,t:integer;
begin
    readln(n);
    for i:=1 to n do begin
        ans:=0;
        readln(a,b);
        while a<b do begin a:=a*2; inc(ans); end;
        if a-b>b-a div 2-1 then ans:=ans+a-b else ans:=ans+b-a div 2-1;
        writeln(ans);
    end;
end.