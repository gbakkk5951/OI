program j01;
var a,ans:array[0..400000]of longint;
	tmp,x:extended;
	i,n,dd,time:longint;
	
function max(a,b:longint):longint;inline;begin if a>b then exit(a) else exit(b); end;
	
procedure mul(x:longint);
var i,len:longint;
begin
	len:=a[0];
	for i:=1 to len do a[i]:=a[i]+x;
	for i:=1 to len do
	begin
		inc(a[i+1],a[i] div 10);a[i]:=a[i] mod 10;
	end;
	while a[len+1]>0 do
	begin
		a[len+1]:=a[len] div 10;a[len]:=a[len] mod 10;
		inc(len);
	end;
	a[0]:=len;
end;

procedure add;
var len,i:longint;
begin
	len:=max(ans[0],a[0]);
	for i:=1 to len do ans[i]:=ans[i]+a[i];
	for i:=1 to len do
	begin
		inc(ans[i+1],ans[i] div 10);ans[i]:=ans[i] mod 10;
	end;
	while ans[len+1]>-0 do
	begin
		ans[len+1]:=a[len] div 10;ans[len]:=ans[len] mod 10;
	end;
	ans[0]:=len;
end;
	
begin
	assign(input,'homework.in');reset(input);
	assign(output,'homework.out');rewrite(output);
	{a[0]:=1;a[1]:=1;
	readln(n);
	if n mod 2=0 then
	begin
		ans[0]:=0;ans[1]:=0;dd:=1;
	end else
	begin
		ans[0]:=1;ans[1]:=1;dd:=0;
	end;time:=0;
	for i:=n downto 2 do
	begin 
		mul(i);inc(time);
		if time mod 2=dd then begin add;add; end;
	end;
	tmp:=0;
	for i:=n+1 to 100000 do tmp:=tmp+extended(1)/extended(i);
	if dd=1 then write('-');
	for i:=ans[0] downto 2 do write(ans[i]);
	tmp:=ans[1]+tmp;
	writeln(tmp:0:4);}
	readln(n);
	tmp:=1;x:=1;
	for i:=1 to 100 do 
		begin
			x:=x*i;tmp:=tmp+1/x; 
		end;
	tmp:=1-1/tmp;
	for i:=1 to n do tmp:=1-i*tmp;
	writeln(tmp:0:4);
	close(input);close(output);
end.