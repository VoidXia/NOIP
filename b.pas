const max=32767;
type arrl=array[0..max]of int64;
var a,b:arrl;
    c,d,f,u:arrl;
    s1,s2:string;
    i,k,j:int64;
    

{
procedure check(var a:arrl);
var i:integer;
begin
for i:=1 to max do begin 
    a[i]:=a[i-1] div 10 +a[i];
    a[i-1]:=a[i-1] mod 10;
    end;}
{
    while a[i]<0 do begin
        a[i]:=a[i]+10;
        a[i+1]:=a[i+1]-1;
        end;
    while a[i]>9 do begin
        a[i]:=a[i]-10;
        a[i+1]:=a[i+1]+1;
        end;
        }
   // end;
//end;

//鬼知道为什么check死循环
//who tm cares

procedure print(a:arrl);
var i,j:int64;
begin
i:=max;
while a[i]=0 do dec(i);
   //     writeln(i,' digit(s)');
for j:=i downto 1 do write(a[j]);
//writeln;
end;
//打印有误我吃屎好吧


procedure minus(a,b:arrl; var c:arrl);
var i,j,k:int64;
begin
    k:=max;
    j:=max;
    while a[j]=0 do dec(j);
    while b[k]=0 do dec(k);
    if j>k then k:=j;
    for i:=0 to max do c[i]:=0;
    for i:=1 to k+1 do 
        begin
        c[i]:=a[i]-b[i]+c[i];
        if c[i]<0 then begin
            c[i+1]:=c[i+1]-1;
            c[i]:=c[i]+10;
            end;
        end;
    //    for i:=1 to max do if c[i]<0 then c[1]:=-1;

     //   check(c);
        
end;

//减法有误我吃屎好吧
//有一点点小尴尬 17.5.20.sat.22:00

procedure plus(a,b:arrl; var c:arrl);
var i,j,k:int64;
begin
 //   k:=max;
//    j:=max;
//    while a[j]=0 do dec(j);
 //   while b[k]=0 do dec(k);
 //   if j>k then k:=j;
    for i:=0 to max do c[i]:=0;
    for i:=1 to max do 
        begin
        c[i]:=a[i]+b[i]+c[i];
        if c[i]>9 then begin
            c[i+1]:=c[i+1]+1;
            c[i]:=c[i]-10;
            end;
        end;
      //  for i:=1 to max do if c[i]<0 then c[1]:=-1;

     //   check(c);
        
end;
{procedure modmod(var a:arrl);
var i:integer;
    b:arrl;
    boo:boolean;
begin
for i:=1 to max do b[i]:=a[i];
i:=max;
boo:=false;
while a[i]=0 do dec(i);
if (a[6]=1)and(a[5]=0)and(a[4]=0)and(a[3]=0)and(a[2]=0)and(a[1]<3)and(i=6) then boo:=true;
 if i<6 then boo:=true;
 while boo=false do begin
    minus(b,u,a);
   // print(a);
    if a[1]=-1 then begin
        for i:=1 to max do a[i]:=b[i];
        boo:=true;
        end;
    for i:=1 to max do b[i]:=a[i];
    if (a[6]=1)and(a[5]=0)and(a[4]=0)and(a[3]=0)and(a[2]=0)and(a[1]<3)and(i=6) then boo:=true;
    if i<6 then boo:=true;
end;
end;}

procedure modmod(var a:arrl);
var i,j:int64;
    ans:int64;
begin
j:=max;
while a[j]=0 do dec(j);
ans:=a[j];
a[0]:=0;
//if a[j]>0 then 
for i:=j downto 1 do
ans:=(ans mod 100003)*10+a[i-1];
//if a[j]<0 then 
for i:=1 to max do a[i]:=0;
for i:=0 to 6 do begin
    a[i]:=ans mod 10;
    ans:=ans div 10;
    end;
end;





procedure mult(a,b:arrl; var c:arrl);
var i,j,k,sa,sb:int64;
begin
    for i:=0 to max do c[i]:=0;
    sa:=max;
    sb:=max;
    while a[sa]=0 do dec(sa);
    while b[sb]=0 do dec(sb); 
    for i:=sa downto 1 do
        for j:=sb downto 1 do
            begin
            c[i+j-1]:=c[i+j-1]+a[i]*b[j];
            for k:=i+j-1 to max do
            if c[k]>9 then begin
                            c[k+1]:=c[k+1]+c[k] div 10;
                            c[k]:=c[k] mod 10;
                            end;
                        
            end;
end;
  //  k:=max;
          //  inc(c[i+j-1],a[i]*b[j]);
    //while c[k]=0 do dec(k);
    {for i:=1 to k do
        begin
           c[i]:=c[i]+c[i-1] div 10;
           c[i-1]:=c[i-1] mod 10;
        end;}
   // check(c);  inc



//乘法无误


procedure half(a:arrl; var b:arrl);
var i:int64;
begin
b[0]:=0;
for i:=1 to max do b[i]:=a[i];
for i:=max downto 1 do begin
    if b[i] mod 2=0 then b[i]:=b[i] div 2
            else
            begin
            b[i]:=b[i] div 2;
            b[i-1]:=b[i-1]+10;
            end;
  end;
end;
// proc half is right

//快速幂 rubbish rubbish rubbish
procedure power(a,b:arrl; var c:arrl);
var ha,t,te,a1,b1:arrl;
    i:int64;
    boo:boolean;
begin
    for i:=0 to max do a1[i]:=a[i];
    for i:=0 to max do b1[i]:=b[i];
    for i:=0 to max do c[i]:=0;
    boo:=true;
    for i:=max downto 2 do if b[i]<>0 then boo:=false;
    if b[1]<>1 then boo:=false;
    if boo=true then begin
        for i:=1 to max do c[i]:=a[i];
        exit;
        end;
    if boo=false then begin
        c[1]:=1;
     //   for i:=max downto 1 do ha[i]:=b[i];
        half(b,ha);
      //  writeln;
           // print(ha);
        //    writeln('still');
          
            if ha[0]=0 then begin
       
                           modmod(a1);
                            power(a1,ha,t);
                      //      print(t);
                          modmod(t);
                       //   print(t);
                      //      writeln(' before ^2');
                         //   modmod(t);
                            mult(t,t,c);
                           // print(c);
                         modmod(c);
                      //   writeln;
                         //   print(c);
                          //  writeln(' after ^2');
                         
                            end
                        else begin
                            modmod(a1);
                            power(a1,ha,t);
                       //     print(t);
                            modmod(t);
                   //         print(t);
                 //           writeln(' before^2');
                  //          modmod(t);
                            mult(t,t,te);
                  //          print(te);
                            modmod(te);
                  //          print(te);
                        //    writeln(' after^2');
                       
                            mult(a1,te,c);
                        //    print(c);
                           modmod(c);
                         //  writeln;
                         //  print(c);
                            end;
           {if ha[0]<>0 then begin
                            modmod(a1);
                            power(a1,ha,t);
                            modmod(t);}



                            
    end;
end;



begin
    for i:=1 to max do u[i]:=0;
    u[1]:=3;
    u[6]:=1;
    readln(s1);
    for i:=1 to length(s1) do val(s1[i],a[length(s1)-i+1]);
    readln(s2);
    for i:=1 to length(s2) do val(s2[i],b[length(s2)-i+1]);
 {  mult(a,b,c);
    check(c);
    writeln;
    print(c);

    writeln;
    half(b,c);
    writeln;
    print(c);
    writeln;

    power(a,b,c);
    writeln;
    print(c);
    writeln;
    halt;}


    power(a,b,c);
  //  print(c);
  //  writeln;
 //   writeln;
  //  modmod(c);
    a[1]:=a[1]-1;
    b[1]:=b[1]-1;
    if a[1]<0 then begin a[2]:=a[2]-1; a[1]:=a[1]+10; end;
    if b[1]<0 then begin b[2]:=b[2]-1; b[1]:=b[1]+10; end;
    power(a,b,d);
 //   print(d);
 //   writeln;
 //   writeln;
 //   modmod(d);
  //  check(d);
   // print(d);
    a[1]:=a[1]+1;
    if a[1]>9 then begin a[2]:=a[2]+1; a[1]:=a[1]-10; end;
    for k:=1 to max do f[k]:=d[k];
   // print(f);
    mult(a,f,d);
  //  modmod(d);
 //   check(d);
  //  print(d);
  //  writeln;
  //  writeln;
  //  writeln;
    for k:=1 to max do f[i]:=d[i];
    
    minus(c,d,f);

    
 //   check(d);

  //  while d[i]=0 do i:=i-1;
 //   check(d);
   { writeln(d[6]);
    writeln(d[5]);
    writeln(d[4]);
    writeln(d[3]);
    writeln(d[2]);
    writeln(d[1]);}
 //   for j:=i downto 1 do write(d[j]);
 {boo:=false;
 i:=max;

 if (f[6]=1)and(f[5]=0)and(f[4]=0)and(f[3]=0)and(f[2]=0)and(f[1]<3)and(i=6) then boo:=true;
 if i<6 then boo:=true;
while boo=false do begin
      for j:=1 to max do c[i]:=f[i];
      minus(c,d,f);while f[i]=0 do dec(i);
       if (f[6]=1)and(f[5]=0)and(f[4]=0)and(f[3]=0)and(f[2]=0)and(f[1]<3)and(i=6) then boo:=true;
      if i<6 then boo:=true;
end;}
// print(f);
 //modmod(f);
 //minus(u,f,f);
 modmod(f);
 //print(f);
 i:=max;
 while f[i]=0 do dec(i);
 if f[i]<0 then begin
 for j:=1 to i-1 do 
 f[i]:=-f[i];
 plus(u,f,f);
 //print(f);
 modmod(f);
 end;
 print(f);
end.