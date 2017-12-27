@echo off
set t=0
:loop
	set /a t=t+1
	make.exe
	gba.exe
	yousiki.exe
	fc gba.out yousiki.out
	echo %t%
if not errorlevel 1 goto loop
pause
goto loop
