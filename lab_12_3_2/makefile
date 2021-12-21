CC = gcc
CFLAGS = -std=gnu99 -Werror -Wall -Wvla -pedantic -Wextra -Wpedantic

INCS = $(wildcard ./inc/*.h) 

all : build_lib

build_lib :
	$(CC) $(CFLAGS) -I "inc" -c lib/*.c
	$(CC) -shared *.o -Wl,--subsystem,windows -o arr_lib.dll
	rm *.o

unit_tests : build_lib
	$(CC) $(CFLAGS) -I "inc" unit_tests/*.c -L. -larr_lib -o unit_tests.exe -lcheck


.PHONY : clean debug release

release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

unit : unit_tests
	./unit_tests.exe

clean :
	rm *.exe *.dll *.o
