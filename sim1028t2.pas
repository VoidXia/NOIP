const tab:array[0..4,0..4]of integer=((0,-1,1,1,-1),(1,0,-1,1,-1),(-1,1,0,-1,1),(-1,-1,1,0,1),(1,1,-1,-1,0));
var n,na,nb,i,j,k:integer;
    a,b:array[0..200]of integer;
begin
    assign(input,"rps.in");
    assign(output,"rps.out");
    reset(input);
    rewrite(output);
    readln(n,na,nb);
    fillchar(a,sizeof(a),0);
    fillchar(b,sizeof(b),0);
    for i:=0 to na-1 do read(a[i]);
    for j:=0 to nb-1 do read(b[j]);
    i:=0;
    j:=0;
    for k:=0 to n-1 do begin
       // writeln(k,'#',a[k mod na],'#',b[k mod nb],'#',tab[(a[k mod na]),(b[k mod nb])]);
        if tab[(a[k mod na]),(b[k mod nb])]=1 then inc(i); 
        if tab[(a[k mod na]),(b[k mod nb])]=-1 then inc(j); 
    end;
    writeln(i,' ',j);
    close(input);
    close(output);
end.