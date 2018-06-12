@echo off 
for /f "delims=" %%b in ('dir /a-d/b *.out') do (
ren %%b %%~nb.ans
)
pause
exit
