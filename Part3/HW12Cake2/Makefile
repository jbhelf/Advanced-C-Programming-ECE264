WARNING =-Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_CREATELIST -DTEST_ELIMINATE -DTEST_DELETENODE -DDEBUG

SRCS = main.c hw12.c
OBJS = $(SRCS:%.c=%.o)

hw12: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw12

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw12
	$(VAL) ./hw12 6 3 > output 1

testall: test1 test2 test3

test1: hw12 
	./hw12 6 3 > output1
	diff output1 expected/expected1

test2: hw12
	./hw12 6 4 > output2
	diff output2 expected/expected2

test3: hw12
	./hw12 25 7 > output3
	diff output3 expected/expected3

clean:
	rm -f hw12 *.o output?
