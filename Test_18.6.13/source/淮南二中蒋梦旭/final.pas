program j01;
var j,n,i:longint;
	ans:longint;
	a:array[1..2,1..2]of longint;
begin
	assign(input,'final.in');reset(input);
	assign(output,'final.out');rewrite(output);
	readln(n);
	if n>2 then
	begin	
		writeln('no solution');close(input);close(output);halt;
	end;
	readln(a[1,1],a[1,2]);
	for i:=-2000 to 2000 do
		for j:=-2000 to 2000 do
		begin
			ans:=a[1,1]*a[2,2]-a[2,1]*a[1,2];
			if ans=1 then
			begin
				writeln(a[1,1],' ',a[1,2]);
				writeln(a[2,1],' ',a[2,2]);
				close(input);close(output);
				halt;
			end;
		end;
	writeln('no solution');
	close(input);close(output);
end.