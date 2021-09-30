@echo off

cls
"../app.exe" neg_01_in.txt out.txt
fc out.txt neg_01_out.txt

"../app.exe" neg_02_in.txt out.txt f
fc out.txt neg_02_out.txt

"../app.exe" neg_03_in.txt out.txt f
fc out.txt neg_03_out.txt

"../app.exe" neg_04_in.txt out.txt f
fc out.txt neg_04_out.txt

"../app.exe" neg_05_in.txt out.txt f
fc out.txt neg_05_out.txt


"../app.exe" pos_01_in.txt out.txt
fc out.txt pos_01_out.txt

"../app.exe" pos_02_in.txt out.txt
fc out.txt pos_02_out.txt

"../app.exe" pos_03_in.txt out.txt
fc out.txt pos_03_out.txt

"../app.exe" pos_04_in.txt out.txt
fc out.txt pos_04_out.txt

"../app.exe" pos_05_in.txt out.txt
fc out.txt pos_05_out.txt

"../app.exe" pos_06_in.txt out.txt f
fc out.txt pos_06_out.txt

"../app.exe" pos_07_in.txt out.txt f
fc out.txt pos_07_out.txt

"../app.exe" pos_08_in.txt out.txt f
fc out.txt pos_08_out.txt

"../app.exe" pos_09_in.txt out.txt f
fc out.txt pos_09_out.txt

copy /y NUL out.txt

pause