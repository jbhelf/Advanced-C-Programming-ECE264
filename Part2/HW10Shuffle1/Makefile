WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

shuffle: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o shuffle

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: shuffle
	$(VAL) ./shuffle 4 | sort > output4

testall: test1 test2 test3

test1: shuffle
	./shuffle 4 | sort > output4
	diff -w output4 expected/expected4

test2: shuffle
	./shuffle 8 | sort > output8
	diff -w output8 expected/expected8

test3: shuffle
	./shuffle 11 | sort > output11
	diff -w output11 expected/expected11

clean:
	rm -f shuffle *.o output?
