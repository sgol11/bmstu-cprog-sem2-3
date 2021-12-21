@echo off

cls

"../app.exe" pos_01_in.txt out.txt p
fc out.txt pos_01_out.txt

"../app.exe" pos_02_in.txt out.txt i Titanic 1997 The_Intouchables 2011
fc out.txt pos_02_out.txt

"../app.exe" pos_03_in.txt out.txt r
fc out.txt pos_03_out.txt

"../app.exe" pos_04_in.txt out.txt s
fc out.txt pos_04_out.txt

copy /y NUL out.txt

pause