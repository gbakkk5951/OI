@ echo off
set t=0
: loop
	set /a t=t+1
	��������.exe 
	���ֲ���std.exe 
	���ֵĲ���.exe 
	fc my.out std.out
	echo %t%
if not errorlevel 1 goto loop
pause
goto loop
