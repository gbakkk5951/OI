program homework;
const math_e=2.718281828459045;
var ans:extended;
	n,i:longint;
begin
	assign(input,'homework.in');reset(input);
	assign(output,'homework.out');rewrite(output);
	readln(n);
	ans:=1-1/math_e;
	for i:=1 to n do ans:=1-i*ans;
	writeln(ans:0:4);
	close(input);close(output);
end.