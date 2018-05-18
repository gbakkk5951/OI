@ echo off
set t=0
: loop
	set /a t=t+1
	数据生成.exe 
	棘手操作std.exe 
	棘手的操作.exe 
	fc my.out std.out
	echo %t%
if not errorlevel 1 goto loop
pause
goto loop
