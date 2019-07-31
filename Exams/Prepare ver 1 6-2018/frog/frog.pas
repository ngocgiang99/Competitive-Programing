{**************************************************************************
*  Program   :    CHUONG TRINH CHAM EXTERNAL CUA AMM2                     *
*  Date      :    2013/08/01                                              *
*  Author    :    Le Thanh Binh                                           *
**************************************************************************}

const
   tfi                          =    'COMPAR$R.INP';
   tfo                          =    'COMPAR$R.OUT';
   tf_vao                       =    'FROG.inp';
   tf_ra                        =    'FROG.out';

var
   b_path                       :    string;
   t_input, t_answer, t_output  :    string;
   fi, fo, fm                   :    text;
   error                        :    integer;

   m, n, k: longint;
   a: array[0..1001,0..1001] of longint;



procedure read_input;
var i,j: longint;
begin
   read(fi,m,n,k);
   for i:=1 to m do
      for j:=1 to n do read(fi,a[i,j]);
end;

procedure read_answer;
begin
end;

procedure read_output;
var kqm, kqo, tong: int64;
    i, j, u, v: longint;
begin
   {$i-}
   readln(fm,kqm);
   readln(fo,kqo);
   if (ioresult<>0) or (kqm<>kqo) then
      begin
         error:=1;
         exit;
      end;
   error:=3;
   tong:=0;
   readln(fo,u);
   if (ioresult<>0) or (u<1) or (u>n) then exit;
   tong:=a[1,u];
   for i:=2 to m do
      begin
         readln(fo,v);
         if (ioresult<>0)  or (v<1) or (v>n) or (abs(u-v)>k) then exit;
         tong:=tong+a[i,v];
         u:=v;
      end;
   if tong<>kqo then exit;
   error:=0;
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
      3: writeln(f,'DUNGMOTPHAN 0.5');
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



