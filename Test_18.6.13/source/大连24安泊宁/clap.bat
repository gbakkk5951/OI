@echo off
:begin
data
restore
if not errorlevel 1 break;
echo done
goto begin