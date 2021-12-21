CC = gcc
CFLAGS = -std=gnu99 -Wall -Wvla -pedantic -Wextra -Wpedantic
STATIC_FOLDER = cd static_lib
DYN_FOLDER_1 = cd dyn1_lib
DYN_FOLDER_2 = cd dyn2_lib

INCS = $(wildcard ./inc/*.h) 

all : app_static app_dyn1 app_dyn2


# статическая библиотека

build_static_lib :
	#
	# сборка статической библиотеки
	#
	# компиляция
	$(STATIC_FOLDER)/out && $(CC) $(CFLAGS) -I "../inc" -c ../lib/*.c
	# упаковка
	$(STATIC_FOLDER) && ar rc static.a out/*.o
	# индексирование
	$(STATIC_FOLDER) && ranlib static.a
	# удаление ненужных объектных файлов
	$(STATIC_FOLDER)/out && rm *.o

app_static : build_static_lib
	#
	# сборка приложения со статической библиотекой
	#
	$(STATIC_FOLDER) && $(CC) $(CFLAGS) -I "inc" src/*.c static.a -o app.exe

unit_tests_static : build_static_lib
	#
	# сборка юнит-тестов со статической библиотекой
	#
	$(STATIC_FOLDER) && $(CC) $(CFLAGS) -I "inc" src/cmp.c unit_tests/*.c static.a -o unit_tests.exe -lcheck


# динамическая библиотека (динамическая компоновка)

build_dyn1_lib :
	#
	# сборка динамической библиотеки (динамическая компоновка)
	#
	# компиляция
	$(DYN_FOLDER_1)/out && $(CC) $(CFLAGS) -I "../inc" -c ../lib/*.c
	# компоновка
	$(DYN_FOLDER_1) && $(CC) -shared out/*.o -Wl,--subsystem,windows -o dyn1.dll
	# удаление ненужных объектных файлов
	$(DYN_FOLDER_1)/out && rm *.o

app_dyn1 : build_dyn1_lib
	#
	# сборка приложения с динамической библиотекой (динамическая компоновка)
	#
	$(DYN_FOLDER_1) && $(CC) $(CFLAGS) -I "inc" src/*.c -L. -ldyn1 -o app.exe

unit_tests_dyn1 : build_dyn1_lib
	#
	# сборка юнит-тестов с динамической библиотекой (динамическая компоновка)
	#
	$(DYN_FOLDER_1) && $(CC) $(CFLAGS) -I "inc" src/cmp.c unit_tests/*.c -L. -ldyn1 -o unit_tests.exe -lcheck


# динамическая библиотека (динамическая загрузка)

build_dyn2_lib :
	#
	# сборка динамической библиотеки (динамическая загрузка)
	#
	# компиляция
	$(DYN_FOLDER_2)/out && $(CC) $(CFLAGS) -I "../inc" -c ../lib/*.c
	# компоновка
	$(DYN_FOLDER_2) && $(CC) -shared out/*.o -Wl,--subsystem,windows -o dyn2.dll
	# удаление ненужных объектных файлов
	$(DYN_FOLDER_2)/out && rm *.o

app_dyn2 : build_dyn2_lib
	#
	# сборка приложения с динамической библиотекой (динамическая загрузка)
	#
	$(DYN_FOLDER_2) && $(CC) $(CFLAGS) -I "inc" src/*.c  -o app.exe

unit_tests_dyn2 : build_dyn2_lib
	#
	# сборка юнит-тестов с динамической библиотекой (динамическая загрузка)
	#
	$(DYN_FOLDER_2) && $(CC) $(CFLAGS) -I "inc" src/cmp.c unit_tests/*.c -o unit_tests.exe -lcheck


.PHONY : clean debug release

release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

unit : unit_tests_static unit_tests_dyn1 unit_tests_dyn2
	$(STATIC_FOLDER) && ./unit_tests.exe
	$(DYN_FOLDER_1) && ./unit_tests.exe
	$(DYN_FOLDER_2) && ./unit_tests.exe

func :
	# статическая библиотека
	cd _func_tests_ && ./run_tests_static.bat
	# динамическая библиотека (динамическая компоновка)
	cd _func_tests_ && ./run_tests_dyn1.bat
	# динамическая библиотека (динамическая загрузка)
	cd _func_tests_ && ./run_tests_dyn2.bat

clean :
	rm static_lib/*.exe dyn1_lib/*.exe dyn2_lib/*.exe static_lib/*.a dyn1_lib/*.dll dyn2_lib/*.dll
