const   fi      ='INCSEQ.inp';
        fo      ='INCSEQ.out';
        oo      =trunc(1e6)+1;

type    arr     =array[0..oo] of longint;
var     n, k    :longint;
        a, vet,l        :arr;
        StartOf :arr;
        m       :longint;

Function find(i:longint):longint;
var     l, r, g :longint;
begin
        l:=1;
        r:=m+1;
        {if i=2 then
                begin
                for g:=1 to m do write(StartOf[g],' ');writeln;

                end;
                      }
        repeat
                g:=(l+r) div 2;
                if A[StartOf[g]]>a[i] then l:=g else r:=g;
        until l+1=r;

           // if i=2 then writeln(l,'-...');
        exit(StartOf[l]);
end;

procedure xuly;
var     i, j    :longint;
begin
        assign(input,fi);assign(output,fo);
        reset(input);rewrite(output);
        readln(n);
        for i:=1 to n do readln(a[i]);
        a[0]:=low(longint);
        a[n+1]:=high(longint);
        l[n+1]:=1;
        StartOf[1]:=n+1;
        m:=1;
        for i:=n downto 0 do
                begin
                        j:=find(i);
                        k:=l[j]+1;
                        if k>m then
                                begin
                                        m:=k;
                                        StartOf[k]:=i;
                                end
                        else
                                if A[StartOf[k]]<A[i] then
                                        StartOf[k]:=i;
                        Vet[i]:=j;
                   //     writeln(i,' ',vet[i]);
                        L[i]:=L[j]+1;
                end;
        writeln(l[0]-2);
        i:=vet[0];
        repeat
                writeln(a[i]);
                i:=vet[i];
        until i=n+1;
        close(input);close(output);
end;
begin
        xuly;
end.