CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic -Wextra -Wpedantic

OBJS = ./out/io.o ./out/memory_work.o ./out/delete.o ./out/add.o ./out/multi.o
OBJS_UNIT = ./out/check_delete.o ./out/check_add.o ./out/check_multi.o

INCS = $(wildcard ./inc/*.h) 

app.exe: ./out/main.o $(OBJS)
	$(CC) -o $@ $^

unit_tests.exe: ./out/check_main.o $(OBJS) $(OBJS_UNIT) 
	$(CC) -o $@ $^ -lcheck

./out/%.o: ./src/%.c $(INCS)
	cd out && $(CC) $(CFLAGS) -I "../inc" -c ../$<

./out/%.o: ./unit_tests/%.c $(INCS)
	cd out && $(CC) $(CFLAGS) -I "../inc" -c ../$<

.PHONY : clean debug release

release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

unit : unit_tests.exe
	./unit_tests.exe

func :
	cd func_tests && ./run_tests.bat

clean :
	$(RM) ./out/*.o *.exe