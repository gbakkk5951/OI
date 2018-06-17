g++ sol.cpp -o sol -g -O3
g++ std.cpp -o std -g -O3
g++ maker.cpp -o maker -g -O3
:loop
maker.exe %RANDOM% >in.txt         
std.exe < in.txt > std.txt  
sol.exe < in.txt > ans.txt  
fc /A std.txt ans.txt
if not errorlevel 1 goto loop
pause
:end