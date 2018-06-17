program j01;
const eps=1e-4;
type pos=record x,y:extended; end;
var d:array[0..200,0..200]of extended;
	ans:array[0..200]of pos;
	ps:array[0..200,0..2]of pos;
	bo:array[0..200,0..200,1..2,1..2]of boolean;
	ban:array[0..200,1..2]of longint;
	apr:array[0..200]of boolean;
	now:array[0..200]of pos;
	ff:array[0..200]of longint;
	inl:array[0..200]of boolean;
	n,i,j,k,l,x,y:longint;
	t1,t2,a,b,c:extended;
	tmp:pos;
	flag:boolean;
	
procedure swap(var a,b:longint);inline;var c:longint;begin c:=a;a:=b;b:=c; end;
function cmp(a,b:extended):boolean;inline;begin exit(abs(a-b)<=eps); end;
function dis(a,b:pos):extended;inline;begin exit(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))); end;

procedure print;
begin
	for i:=1 to n do ans[i]:=now[i];
	for i:=1 to n do writeln(ans[i].x:0:6,' ',ans[i].y:0:6);
	close(input);close(output);
	halt;
end;
	
begin
	assign(input,'restore.in');reset(input);
	assign(output,'restore.out');rewrite(output);
	randomize;
	readln(n);
	for i:=1 to n do 
		for j:=1 to n do 
			read(d[i,j]);
	ps[1,1].x:=0;ps[1,1].y:=0;
	ps[2,1].x:=d[1,2];ps[2,1].y:=0;
	for i:=3 to n do
	begin
		x:=i;
		if cmp(d[x,1]+d[x,2],d[1,2])then
		begin
			ps[i,1].x:=d[x,1];ps[i,1].y:=0;continue;
		end;
		apr[i]:=true;
		a:=d[1,x];b:=d[1,2];c:=d[2,x];
		ps[i,1].x:=(a*a+b*b-c*c)/(2*b);
		ps[i,1].y:=sqrt(a*a-ps[i,1].x*ps[i,1].x);
		ps[i,2].x:=ps[i,1].x;ps[i,2].y:=-ps[i,1].y;
	end;
	for i:=1 to n do
	begin
		if apr[i]=false then 
		begin 
		now[i]:=ps[i,1];
		ff[i]:=0;continue; end;
		tmp:=ps[i,1];flag:=true;
		for j:=i-1 downto 3 do 
			flag:=flag and cmp(dis(tmp,now[j]),d[i,j]);
		if flag then
		begin
			now[i]:=tmp;ff[i]:=0;continue;
		end;
		tmp:=ps[i,2];flag:=true;
		for j:=i-1 downto 3 do flag:=flag and cmp(dis(tmp,now[j]),d[i,j]);
		if flag then
		begin
			now[i]:=tmp;ff[i]:=1;continue;
		end;
		for j:=i-1 downto 3 do
			if apr[j] then 
			begin
				ff[j]:=ff[j] xor 1;now[j]:=ps[j,ff[j]+1];
			end;
		tmp:=ps[i,1];flag:=true;
		for j:=i-1 downto 3 do flag:=flag and cmp(dis(tmp,now[j]),d[i,j]);
		if flag then
		begin
			now[i]:=tmp;ff[i]:=0;continue;
		end;
		tmp:=ps[i,2];flag:=true;
		for j:=i-1 downto 3 do flag:=flag and cmp(dis(tmp,now[j]),d[i,j]);
		if flag then
		begin
			now[i]:=tmp;ff[i]:=1;continue;
		end;
	end;
	print;
end.