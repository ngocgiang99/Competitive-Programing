const
   tfi='maxrec.inp';
   tfo='maxrec.out';
   maxn=1001;

var
   m, n: longint;
   h: array[0..maxn] of longint;
   s: array[0..maxn] of longint;
   sn: longint;
   f: array[0..maxn] of int64;
   res: int64;

procedure CountRec;
var i, j: longint;
begin
   sn:=0; // init stack
   for i:=1 to n do
   begin
      if h[i]>=h[i-1] then
         begin
            f[i]:=f[i-1]+h[i];
         end
      else
         begin
            while (sn>0) and (h[s[sn]]>=h[i]) do dec(sn);
            f[i]:=f[s[sn]]+(i-s[sn])*h[i];
         end;
      res:=res+f[i];
      inc(sn);
      s[sn]:=i;
   end;
end;

procedure main;
var i, j: longint;
    u: char;
begin
   assign(input,tfi); reset(input);
   assign(output,tfo); rewrite(output);
   readln(m,n);
   res:=0;
   for i:=1 to m do
      begin
         // xay dung mang do cao
         for j:=1 to n do
            begin
               read(u);
               if u='1' then inc(h[j]) else h[j]:=0;
            end;
         readln;
         CountRec;
      end;
   writeln(res);
   close(input); close(output);
end;

BEGIN
   main;
END.
