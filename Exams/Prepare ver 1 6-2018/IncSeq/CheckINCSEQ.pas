{$MODE OBJFPC}
{$R-,Q-,S-,I+}
{$OPTIMIZATION LEVEL2}
program IntervalCover;
uses Windows, SysUtils, Math;
const
  prefix = 'INCSEQ';
  InputFile  = prefix + '.INP';
  OutputFile = prefix + '.OUT';
  AnswerFile = prefix + '.OUT';
var
  dirT, dirC: WideString;
  fi, fo, fa: TextFile;

procedure GenErr(const s: string; const param: array of const);
begin
  raise Exception.CreateFmt(s, param);
end;

procedure ReadDirs;
var
  s: AnsiString;
begin
  ReadLn(s); dirT := Utf8Decode(s);
  ReadLn(s); dirC := Utf8Decode(s);
end;

procedure OpenFiles;
var
  CurrentDir: array[0..Max_Path + 1] of WideChar;
begin
  GetCurrentDirectoryW(Max_Path, CurrentDir);
  SetCurrentDirectoryW(PWideChar(dirT));
  AssignFile(fi, InputFile); Reset(fi);
  AssignFile(fa, AnswerFile); Reset(fa);
  SetCurrentDirectoryW(CurrentDir);
  SetCurrentDirectoryW(PWideChar(dirC));
  AssignFile(fo, OutputFile); Reset(fo);
end;

procedure CloseFiles;
begin
  CloseFile(fi);
  CloseFile(fa);
  CloseFile(fo);
end;



//----------------------------------------------------------------------------------------------------------------
// Comment:
// fi: File input
// fa: File answer
// fo: File output
// Cac dong dau ghi loi chu thich
// Dong cuoi ghi mot so thuc nam trong pham vi 0->1

procedure DoCheck;
var
   dong,kqa, kqo: longint;
begin
   dong:=0;
   while not seekeof(fa) do
      begin
         readln(fa,kqa);
         readln(fo,kqo);
         inc(dong);
         if kqa<>kqo then
            begin
               writeln('Sai o dong:',dong);
               writeln('0.0');
               exit;
            end;
      end;
   writeln('Ket qua DUNG');
   writeln('1.0');
end;

//-----------------------------------------------------------------------------------------------------------------

begin
  try
    try
      ReadDirs;
      OpenFiles;
      DoCheck;
    finally
      CloseFiles;
    end;
  except
    on E: Exception do
      begin
        WriteLn(E.Message);
        WriteLn('0.0');
      end;
  end;
end.


