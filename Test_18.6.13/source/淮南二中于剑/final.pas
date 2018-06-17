program final;
const upper=2000;
var a,b,x,y,n:longint;
begin
    assign(input,'final.in');reset(input);
    assign(output,'final.out');rewrite(output);
    readln(n);
    if n>2 then
    begin
        writeln('no solution');
        close(input);close(output);
        halt;
    end;
    readln(a,b);
    for x:=-upper to upper do
        for y:=-upper to upper do
            if a*y-b*x=1 then
            begin
                writeln(a,' ',b);
                writeln(x,' ',y);
                close(input);close(output);
                halt;
            end;
    writeln('no solution');
    close(input);close(output);
end.