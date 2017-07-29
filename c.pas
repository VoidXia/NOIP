const max=200;
type arrl=array[0..200]of int64;
var a,b,c:arrl;
    i,j,k:integer;
    s1,s2:string;
{
procedure half(a:arrl; var b:arrl);
var i:integer;
begin
for i:=1 to max do b[i]:=0;
for i:=max downto 1 do begin
    if a[i] mod 2=0 then b[i]:=a[i] div 2+b[i];
    if a[i] mod 2 = 1 then begin
       b[i]:=a[i] div 2 +b[i];
       b[i-1]:=b[i-1]+10;
      end;
  end;
end;
}

procedure half(a:arrl; var b:arrl);
var i:integer;
begin
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
{
procedure mult(a,b:arrl; var c:arrl);
var i,j,k:integer;
begin
    for i:=0 to 200 do c[i]:=0;
    for i:=length(s1) downto 1 do
        for j:=length(s2) downto 1 do
            inc(c[i+j-1],a[i]*b[j]);
    while c[k]<>0 do inc(k);
    for i:=1 to k do
        begin
           inc(c[i],c[i-1]div 10);
           c[i-1]:=c[i-1] mod 10;
        end;

end;
}
procedure mult(a,b:arrl; var c:arrl);
var i,j,k:integer;
begin
    for i:=0 to max do c[i]:=0;
    for i:=length(s1) downto 1 do
        for j:=length(s2) downto 1 do
            begin
            c[i+j-1]:=c[i+j-1]+a[i]*b[j];
            for k:=i+j-1 to max do
            if c[k]>9 then begin
                            c[k+1]:=c[k+1]+c[k] div 10;
                            c[k]:=c[k] mod 10;
                            end;
                        
            end;
end;

procedure power(a,b:arrl; var d:arrl);
var c:arrl;
    e:arrl;
    f:arrl;
i,k:integer;
boo:boolean;
begin
    for i:=0 to max do d[i]:=0;
    boo:=true;
    for i:=2 to max do
        if b[i]<>0 then boo:=false;
    if (b[1]<>1) and (b[1]<>2) then boo:=false;
    if (b[1]=1)and(boo=true) then begin
        for i:=1 to max do d[i]:=a[i];
    end;
    if (b[1]=2)and(boo=true) then mult(a,a,d);
    if boo=false then begin
    //从这里开始死活不对 although i thought it was right
    //must be wrong somewhere else
        for i:=1 to max do c[i]:=b[i];
        for i:=max downto 1 do begin
            if c[i] mod 2 = 0 then c[i]:=c[i] div 2
                              else begin
                                    c[i]:=c[i] div 2;
                                    c[i-1]:=c[i-1]+10;
                                  end;
        end;
       // check(c);
        //should be right at present
         if b[1] mod 2 = 0 then begin
                               power(a,c,e);
                            //  check(e);
                               mult(e,e,d);
                            //   check(d);
                                end;
         if b[1] mod 2 = 1 then begin
                                power(a,c,e);
                            //    check(e);
                                for k:=1 to max do f[i]:=e[i];
                               mult(f,f,e);
                           //    check(e);
                              mult(e,a,d);
                           //   check(d);
                                   end;
                                   //这里结束大垃圾
    end;


        
end;
//快速幂是大魔王

{

procedure power(a,b:arrl; var c:arrl);
var half:arrl;
    i,j,k,l:integer;
begin
    for i:=max downto 1 do half[i]:=b[i]
    for i:=max downto 1 do  
        
end;

}
begin
    readln(s1);
    for i:=1 to length(s1) do val(s1[i],a[length(s1)-i+1]);
   // for i:=length(s1) downto 1 do write(a[i]);
   // writeln;
    readln(s2);
    for i:=1 to length(s2) do val(s2[i],b[length(s2)-i+1]);
  //  for i:=length(s2) downto 1 do write(b[i]);
  //  writeln;
    power(a,b,c);
 //repeat
 //     half(b,c);
    j:=100;
    while c[j]<=0 do dec(j);
    writeln(j);
    i:=0;
    k:=k+1;
    for i:=j downto 1 do write(c[i],' ');
  //  writeln; 
  //  for i:=1 to max do b[i]:=c[i];
 //until (k=100);
 
end.

