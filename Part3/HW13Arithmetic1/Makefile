WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_READLIST -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETNODE -DTEST_CALCULATE

SRCS = main.c calculate.c list.c
OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw13

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw13
	$(VAL) ./hw13 test1 > output1

testall: test1 test2 test3 test4 test5 test6

test1: hw13
	./hw13 test1 > output1
	diff output1 expected/expected1
test2: hw13
	./hw13 test2 > output2
	diff output2 expected/expected2
test3: hw13
	./hw13 test3 > output3
	diff output3 expected/expected3
test4: hw13
	./hw13 test4 > output4
	diff output4 expected/expected4
test5: hw13
	./hw13 test5 > output5
	diff output5 expected/expected5
test6: hw13
	./hw13 test6 > output6
	diff output6 expected/expected6

clean:
	rm -f hw13 *.o output?
