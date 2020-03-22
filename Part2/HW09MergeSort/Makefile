WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_READDATA -DTEST_WRITEDATA -DTEST_MERGE -DDEBUG -DTEST_MERGESSORT

SRCS = main.c hw09.c
OBJS = $(SRCS:%.c=%.o)

hw09: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw09

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw09
	$(VAL) ./hw09 inputs/input1 > output1

testall: test1 test2 test3 test4 test5

test1: hw09
	./hw09 inputs/input1 output1
	diff output1 expected/expected1

test2: hw09
	./hw09 inputs/input2 output2
	diff output2 expected/expected2

test3: hw09
	./hw09 inputs/input3 output3
	diff output3 expected/expected3

test4: hw09
	./hw09 inputs/input4 output4
	diff output4 expected/expected4

test5: hw09
	./hw09 inputs/input5 output5
	diff output5 expected/expected5

clean:
	rm -f hw09 *.o output?
