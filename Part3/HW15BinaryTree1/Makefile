WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_BUILDTREE

SRCS = main.c tree.c
OBJS = $(SRCS:%..c=%.o)

hw15: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw15

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw15
	$(VAL) ./hw15 inputs/test1in inputs/test1post output1

testall: test1 test2 test3 test4 test5 test6

test1: hw15
	./hw15 inputs/test1in inputs/test1post output1
	diff output1 expected/expected1
test2: hw15
	./hw15 inputs/test2in inputs/test2post output2
	diff output2 expected/expected2
test3: hw15
	./hw15 inputs/test3in inputs/test3post output3
	diff output3 expected/expected3
test4: hw15
	./hw15 inputs/test4in inputs/test4post output4
	diff output4 expected/expected4
test5: hw15
	./hw15 inputs/test5in inputs/test5post output5
	diff output5 expected/expected5
test6: hw15
	./hw15 inputs/test6in inputs/test6post output6
	diff output6 expected/expected6

clean:
	rm -f hw15 *.o output?
