CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -Wvla -pedantic -Wextra -Wpedantic

OBJS = ./out/read_from_file.o ./out/choose_products.o ./out/print_chosen_products.o \
       ./out/my_functions.o ./out/memory_management.o
OBJS_UNIT = ./out/check_io.o ./out/check_choose.o

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

clean :
	$(RM) ./out/*.o *.exe
