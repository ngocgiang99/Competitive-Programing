{**********************************************************************
PROBLEMS : Du chat
GROUP    : CTDL (IT)

Copyright (c) 2010/03/03 by Le Thanh Binh
**********************************************************************}

Program FOOT;

Const
   InputFile    =       'test17\foot.inp';
   OutputFile   =       'foot.out';
   maxn=100001;
   vc=1000000000;

var
   N, M: longint;
   c: array[1..maxn] of longint;
   IT: array[1..5*maxn] of longint;
   Finish: longint;
   x: array[1..maxn] of int64;
   ans: int64;

// Cap nhat cay IT vao nut la
Procedure UPdate(r,k,l,u,value: longint);
var g: longint;
begin
   if (u<k) or (u>l) then exit;
   if (u=k) and (k=l) then
      begin
         IT[r]:=value;
         exit;
      end;
   g:=(k+l) div 2;
   Update(2*r,k,g,u,value);
   Update(2*r+1,g+1,l,u,value);
   It[r]:=IT[2*r];
   if IT[r]>IT[2*r+1] then IT[r]:=IT[2*r+1];
end;

Function Get(r,k,l,u,v: longint): longint;
var g, t1, t2: longint;
begin
   if(v<k) or (u>l) then exit(vc);
   if (u<=k) and (l<=v) then exit(IT[r]);
   g:=(k+l) div 2;
   t1:=Get(2*r,k,g,u,v);
   t2:=Get(2*r+1,g+1,l,u,v);
   if t1<t2 then exit(t1) else exit(t2);
end;

// Doc va khoi tao IT
procedure Doc;
var i: longint;
begin
   read(N,M);
   for i:=1 to 5*N do IT[i]:=vc;
   for i:=1 to N do
      begin
         read(c[i]);
         Update(1,1,n,i,c[i]);
      end;
end;

Procedure Process;
var i, t, u: longint;
begin
   Finish:=0; // ngay cuoi cung con thuc an
   for i:=1 to n do
      begin
         if Finish>=n then break;
         if Finish>=i then // co the mua hoac khong
            begin
               t:=Get(1,1,n,i,Finish);
               if t>=c[i] then // co the mua
                  begin
                     u:=finish+1;
                     while (u<=N) and (u<=i+M-1) and (c[u]>c[i]) do
                        begin
                           inc(x[i],2);
                           inc(u);
                        end;
                     dec(u);
                     Finish:=u;
                  end;
               continue;
            end;
         // Bat buoc phai mua
         Finish:=i;
         while (Finish<=N) and (Finish<=i+M-1) and (c[Finish]>=c[i]) do
            begin
               inc(x[i],2);
               inc(Finish);
            end;
         Dec(Finish);
      end;
end;

procedure Viet;
var i: longint;
begin
   Ans:=0;
   for i:=1 to N do Ans:=Ans+x[i]*c[i];
   writeln(ans);
   for i:=1 to n do write(x[i],' ');
end;

Procedure Main;
Begin
   assign(Input,InputFile); reset(Input);
   assign(Output,OutputFile); rewrite(Output);
   Doc;
   Process;
   Viet;
   close(Input); Close(Output);
End;


BEGIN
   Main;
END.

