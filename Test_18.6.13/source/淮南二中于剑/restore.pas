program restore;
const maxn=110;
       eps=1e-8;
type position=record x,y:extended;end;
var net:array[0..maxn,0..maxn] of extended;
    p:array[0..maxn] of position;
    n,i,j,k:longint;
    p1,p2:position;
    d1,d2:extended;
function dis(p1,p2:position):extended;
begin
    exit(sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y)));
end;
function check(ps:position;k:longint):extended;
var i:longint;
    ret:extended;
begin
    ret:=0;
    for i:=1 to k-1 do ret:=ret+sqr(dis(ps,p[i])-net[k,i]);
    exit(ret);
end;
procedure swap(var x,y:extended);
var t:extended;
begin
    t:=x;x:=y;y:=t;
end;
procedure calc(p1,p2:position;r1,r2:extended;var ans1,ans2:position);
var a,b,c,t:extended;
    flag:boolean;
begin
    if abs(p1.y-p2.y)<abs(p1.x-p2.x) then
    begin
        flag:=true;
        swap(p1.x,p1.y);
        swap(p2.x,p2.y);
    end else flag:=false;
    t:=(sqr(r1)-sqr(r2)+sqr(p2.x)-sqr(p1.x))/(2*(p2.y-p1.y))+(p1.y+p2.y)/2;
    a:=1+sqr(p2.x-p1.x)/sqr(p2.y-p1.y);
    b:=-2*(t-p1.y)*(p2.x-p1.x)/(p2.y-p1.y);
    c:=sqr(t-p1.y)-sqr(r1);
    if sqr(b)-4*a*c<eps then
    begin
        ans1.x:=-b/(2*a);
        ans2.x:=-b/(2*a);
    end else
    begin
        ans1.x:=(-b+sqrt(sqr(b)-4*a*c))/(2*a);
        ans2.x:=(-b-sqrt(sqr(b)-4*a*c))/(2*a);
    end;
    ans1.y:=t-(p2.x-p1.x)/(p2.y-p1.y)*ans1.x;
    ans2.y:=t-(p2.x-p1.x)/(p2.y-p1.y)*ans2.x;
    if flag then
    begin
        swap(ans1.x,ans1.y);
        swap(ans2.x,ans2.y);
    end;
end;
begin
    assign(input,'restore.in');reset(input);
    assign(output,'restore.out');rewrite(output);
    readln(n);
    for i:=1 to n do
        for j:=1 to n do read(net[i,j]);
    p[1].x:=0;
    p[1].y:=0;
    for i:=2 to n do
    begin
        k:=0;
        for j:=2 to i-1 do if k=0 then k:=j
        else if net[j,1]>net[k,1] then k:=j;
        if (k>0) then
        begin
            calc(p[1],p[k],net[i,1],net[i,k],p1,p2);
            d1:=check(p1,i);
            d2:=check(p2,i);
            if d1<d2 then p[i]:=p1 else p[i]:=p2;
        end else begin p[i].x:=net[i,1];p[i].y:=0;end;
    end;
    for i:=1 to n do writeln(p[i].x:0:6,' ',p[i].y:0:6);
    close(input);close(output);
end.