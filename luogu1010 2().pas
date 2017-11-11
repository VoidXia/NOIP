type arr=array[1..15]of integer;
var i,a,u,q,l,o:integer;
    c,t:arr;
    y:array[1..100]of arr;
    s:string;

function turn(a:integer;var t:integer; var c:arr):integer;
var i:integer;
begin
    inc(t);
    i:=t;
    if (a=1) or (a=0) then turn:=a else begin
    c[i]:=turn(a div 2,t,c);
   // writeln(i,c[i]);
    turn:=(a mod 2);
    end;

end;

procedure qq(a:integer;var t:integer; var c:arr);
var i:integer;
begin
    t:=1;   c[1]:=turn(a,t,c); dec(t);
    //for i:=t downto 1 do write(c[i]); writeln;
end;

procedure make(tt:integer; yy:arr);
var i:integer;
begin  
inc(l);
 
  //  if tt>=3 then
    for i:=tt downto 1 do begin
        if yy[i]=1 then begin
            s:=concat(s,'2(');
            {for o:=1 to l do write('-'); write(i-1);
            if i-1>2 then write('//'); writeln;}
            //if (i<>0) and (i<>1) then begin
                //y[u] stores the binary form of a
                //t[u] stores the num of bits of the no.u num
                if i-1=0 then s:=concat(s,'0');
                if i-1=1 then s:=concat(s,'');
                if i-1=2 then s:=concat(s,'2');
                if (i-1<>0) and (i-1<>1) and (i-1<>2) then begin
                inc(u);
                qq(i-1,t[u],y[u]);
                make(t[u],y[u]); 
            end;
            s:=concat(s,')+');
        end
    {end
    else begin
    if (yy[2]=1) and (yy[1]=0) then s:=concat(s,'+2+');
    if (yy[1]=0) and (yy[2]=0) then s:=concat(s,'+2(0)+'); 
    if (yy[1]=1) and (yy[2]=1) then s:=concat(s,'+2(2+2(0))+') }
   end;
dec(l);
end;


procedure jjj(a:integer);
begin
    if (a=0) or (a=1) then exit; 
    inc(u);//y[u] stores the binary form of a
    //t[u] stores the num of bits of the u num
    qq(a,t[u],y[u]);
    make(t[u],y[u]);
end;
    

begin
    readln(a);
    l:=0;
    u:=0;
    jjj(a);
    for q:=1 to length(s)-2 do begin 
        if (s[q+1]='+') and (s[q+2]=')') then delete(s,q+1,1);
        if (s[q]='(') and (s[q+1]='+') then delete(s,q+1,1);
        if (s[q+1]='(') and (s[q+2]=')') then delete(s,q+1,2); 
        if (s[q+1]='+') and (s[q+2]=')') then delete(s,q+1,1);
        if (s[q]='(') and (s[q+1]='+') then delete(s,q+1,1);
        if (s[q+1]='(') and (s[q+2]=')') then delete(s,q+1,2);
    end;
    {for q:=1 to length(s)-1 do begin 
        if (s[q]='+') and (s[q+1]=')') then delete(s,q,1);
        if (s[q]='(') and (s[q+1]='+') then delete(s,q+1,1);
        if (s[q]='(') and (s[q+1]=')') then delete(s,q,2); 
    end;}
    if s[length(s)]='+' then delete(s,length(s),1);
    writeln(s);

end.