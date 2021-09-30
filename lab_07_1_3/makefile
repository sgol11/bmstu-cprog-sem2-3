CC = gcc
INC = ./inc/
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CMP = ./cmp/
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

OBJS = $(OUT)filter.o $(OUT)input.o $(OUT)output.o $(OUT)sort.o
OBJS_UNIT = $(OUT)check_fill_array.o $(OUT)check_filter.o \
$(OUT)check_number_of_elements.o $(OUT)check_sort.o $(OUT)check_output.o 

.PHONY : clean debug release

release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

unit : unit_tests.exe
	./unit_tests.exe

func :
	cd func_tests && ./run_tests.bat 

time : measure_time.exe
	./measure_time.exe

clean :
	$(RM) $(OUT)*.o *.exe

app.exe: $(OUT)main.o $(OBJS)
	$(CC) -o $@ $^
unit_tests.exe: $(OUT)check_main.o $(OBJS) $(OBJS_UNIT) 
	$(CC) -o $@ $^ -lcheck
measure_time.exe : $(OUT)cmp_main.o $(OUT)sort.o
	$(CC) -o $@ $^
	
$(OUT)main.o: $(SRC)main.c $(INC)main.h $(INC)filter.h $(INC)input.h $(INC)output.h $(INC)sort.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)filter.o: $(SRC)filter.c $(INC)filter.h $(INC)main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)input.o: $(SRC)input.c $(INC)input.h $(INC)main.h 
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)output.o: $(SRC)output.c $(INC)output.h $(INC)main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)sort.o: $(SRC)sort.c $(INC)sort.h $(INC)main.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_main.o: $(UNIT)check_main.c $(UNIT)check_main.h $(UNIT)check_fill_array.h $(UNIT)check_filter.h \
$(UNIT)check_number_of_elements.h $(UNIT)check_sort.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_fill_array.o: $(UNIT)check_fill_array.c $(UNIT)check_fill_array.h $(UNIT)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_filter.o: $(UNIT)check_filter.c $(UNIT)check_filter.h $(UNIT)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$< 
$(OUT)check_number_of_elements.o: $(UNIT)check_number_of_elements.c $(UNIT)check_number_of_elements.h $(UNIT)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_sort.o: $(UNIT)check_sort.c $(UNIT)check_sort.h $(UNIT)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_output.o: $(UNIT)check_output.c $(UNIT)check_output.h $(UNIT)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)cmp_main.o: $(CMP)cmp_main.c
	cd out && $(CC) $(CFLAGS) -c ../$<