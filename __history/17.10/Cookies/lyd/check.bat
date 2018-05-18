@echo off
set /a t=0
:loop
	CookiesMaker.exe
	cookies_1.exe
	cookies_2.exe
	fc cookies_1.out cookies_2.out
	set /a t=t+1
	@echo %t%
if not errorlevel 1 goto loop
pause
goto loop