WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_CONVERT 

SRCS = main.c convert.c list.c
OBJS = $(SRCS:%.c=%.o)

hw14: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw14

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw14
	$(VAL) ./hw14 test1 > output1

testall: test1 test2 testrest

test1: hw14
	./hw14 test1 > output1
	diff output1 expected/expected1
test2: hw14
	./hw14 test2 > output2
	diff output2 expected/expected2
testrest: hw14
	./hw14 test3 > output3
	diff output3 expected/expected3
	./hw14 test4 > output4
	diff output4 expected/expected4
	./hw14 test5 > output5
	diff output5 expected/expected5

clean: 
	rm -f hw14 *.o output?
