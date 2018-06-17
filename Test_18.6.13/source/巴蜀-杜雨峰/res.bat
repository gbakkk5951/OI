@echo off
:wer
grs.exe 
restore.exe 
chkr.exe
if not errorlevel 1 goto wer
pause
