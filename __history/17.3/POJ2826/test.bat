@ echo off
set t=0
: loop
	set /a t=t+1
	make.exe 
	std.exe 
	my.exe 
	fc my.out std.out
	echo %t%
if not errorlevel 1 goto loop
pause
goto loop
