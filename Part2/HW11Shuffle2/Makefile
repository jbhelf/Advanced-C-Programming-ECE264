WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

shuffle: $(OBJS)
	$(GCC) $(OBJS) -o shuffle

.c.o:
	$(GCC) -c $*.c

testmemory: shuffle
	$(VAL) ./shuffle 2 2 | sort | uniq | wc > output1 

testall: test1 test2 test3 test4

test1: shuffle
	./shuffle 2 2 | sort > output1

test2: shuffle
	./shuffle 3 2 | sort | uniq | wc > output2

test3: shuffle
	./shuffle 2 3 | sort | uniq | wc > output3

test4: shuffle
	./shuffle 3 3 | sort | uniq | wc > output4

clean:
	rm -f shuffle *.o output?
