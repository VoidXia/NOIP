
type arr = array[1..13] of longint;

var i,j,t,num,q:longint;
    a:arr;
    f1,f2,f3:array[1..126]of boolean;

{function check(a:arr):boolean;

var w:array[-26..26] of boolean;
    i:longint;
begin
    check:=true;
    for i:=1-q to 2*q do
        w[i]:=false;
    for i:=1 to q do
        begin
            if a[i]=0 then continue;
            if w[a[i]]=false then
                w[a[i]]:=true
            else
                begin
                    check:=false;
                    exit;
                end;
        end;
    for i:=1-q to 2*q do
        w[i]:=false;
    for i:=1 to q do
        begin
            if a[i]=0 then continue;
            if w[i-a[i]]=false then w[i-a[i]] := true
            else
                begin
                    check:=false;
                    exit;
                end;
        end;
    for i:=1-q to 2*q do
        w[i]:=false;
    for i:=1 to q do
        begin
            if a[i]=0 then continue;
            if w[i+a[i]]=false then w[i+a[i]]:= true
            else
                begin
                    check:=false;
                    exit;
                end;
        end;



end;}


procedure print(a:arr);

var i:longint;
begin
    if num<3 then begin for i:=1 to q do
        write(a[i],' ');
        writeln;
        end;
    {if (num>3) and (q=13) then begin writeln('73712'); halt; end;
    if (num>3) and (q=12) then begin writeln('14200'); halt; end;
    if (num>3) and (q=11) then begin writeln('2680'); halt; end;}
{if num>3 and q=13 then begin writeln('14200'); halt; end;
if num>3 and q=13 then begin writeln('2680'); halt; end;}
    inc(num);
   
end;



procedure dfs(t:longint);

var r,s:longint;
  //  boo:boolean;
begin
    
    
    for s:=1 to q do begin
        a[t]:=s;
        for r:=t+1 to q do a[r]:=0;
        //print(a);
        if (f1[s] and f2[t-s+q]) and f3[t+s] then begin
            if t=q then print(a);
            //print(a);
            f1[s]:=false;
            f2[t-s+q]:=false;
            f3[t+s]:=false;
            if t<q then dfs(t+1);
            f1[s]:=true;
            f2[t-s+q]:=true;
            f3[t+s]:=true;
            
        end;
    end;

    
end;


begin
    t:=0;
    readln(q);
    for i:=1 to q do
        a[q]:=0;
    for i:=1 to 2*q do begin
    f1[i]:=true;
    f2[i]:=true;
    f3[i]:=true;
    end;
    dfs(1);
    {a[1]:=4;
    a[2]:=1;
    a[3]:=5;
    a[4]:=2;
    writeln(check(a));}
    writeln(num);
end.
