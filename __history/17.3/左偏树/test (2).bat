@echo off
set t=0
:loop
	set /a t=t+1
	make.exe
	my.exe
	std.exe
	fc my.out std.out
	echo %t%
if not errorlevel 1 gotp loop
pause
goto loop