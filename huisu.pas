const
    stacksize=64;
type 
    tstate=array[1..3]of integer;
    tstackstruc=record
          state:tstate;
          branchcode:integer;
    end;
var 
    a,b:tstate;
    stack:array[1..stacksize]of tstackstruc;
    stacktop:integer;
    foundnewstate:boolean;
    i:integer;

function equal(state1,state2:Tstate):boolean;
begin
    equal:=false;
    if state1[1]=state2[1] and state1[2]=state2[2] and state1[3]=state2[3] then equal= true;
end;

procedure push (astate:tstate; acode:integer);
begin  
    inc(stacktop);
    stack[stacktop].state:=astate;
    stack[stacktop].branchcode:=acode;
end;

procedure pop(var astate:tstate; var acode:integer);
begin
    astate:=stack[stacktop].state;
    acode:=stack[stacktop].branchcode;
    dec(stacktop);
end;

procedure createnewstate(state:tstate; var newstate:tstate; code:integer);
begin
    newstate:=state;
    case code of
    1:  if state[1]>=(5-state[2]) then begin
        newstate[1]:=state[1]-