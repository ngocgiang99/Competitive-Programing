{**************************************************************************
  Program   :    CHUONG TRINH CHAM EXTERNAL CUA AMM2
  Problems  :    FOOT

  Copyright (c) 2010/03/03 by Le Thanh Binh
**************************************************************************}

const
   tfi                          =    'COMPAR$R.INP';
   tfo                          =    'COMPAR$R.OUT';
   tf_vao                       =    'foot.inp';
   tf_ra                        =    'foot.out';

var
   b_path                       :    string;
   t_input, t_answer, t_output  :    string;
   fi, fo, fm                   :    text;
   error                        :    integer;

   n, m: longint;
   c: array[1..100001] of longint;
   kqm, kqo: int64;



procedure read_input;
begin
end;

procedure read_answer;
begin
   readln(fm,kqm);
end;

procedure read_output;
var i: longint;
begin
   {$i-}
   readln(fo,kqo);
   if ioresult<>0 then
      begin
         error:=2;
         exit;
      end;
   if kqm<>kqo then
      begin
         error:=1;
         exit;
      end;
end;

procedure kiem_tra;
begin

end;


{------------------------Doc thong tin duong dan cua test---------------}
procedure chuan(var s: string);
begin
   while (length(s)>0) and (s[1]=#32) do delete(s,1,1);
   while (length(s)>0) and (s[length(s)]=#32) do delete(s,length(s),1);
end;

procedure chuan_bi;
var f: text;
begin
   assign(f,tfi); reset(f);
   readln(f,b_path);
   chuan(b_path);
   close(f);
   t_input:=b_path+tf_vao;
   t_answer:=b_path+tf_ra;
   t_output:=tf_ra;
end;

{---- Mo cac file input, answer va output-------------------------------}
procedure open_file;
begin
   assign(fi,t_input); reset(fi);
   assign(fm,t_answer); reset(fm);
   assign(fo,t_output); reset(fo);
   if ioresult<>0 then
      begin
         error:=2;
         exit;
      end;
end;


procedure cham;
begin
   read_input;
   read_answer;
   read_output;
   if error<>0 then exit;
   kiem_tra;
end;

procedure viet;
var f: text;
begin
   assign(f,tfo); rewrite(f);
   case error of
      0: writeln(f,'DUNG');
      1: writeln(f,'SAI');
      2: writeln(f,'SAIDINHDANG');
      3: writeln(f,'DUNGMOTPHAN 50');
   end;
   close(f);
end;

procedure close_file;
begin
   close(fi);
   close(fm);
   close(fo);
end;

procedure main;
begin
   chuan_bi;
   error:=0;
   open_file;
   if error=0 then cham;
   close_file;
   viet;
end;


BEGIN
   {$i-}
   main;
   {$i+}
END.


