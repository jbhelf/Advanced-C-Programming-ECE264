WARNING = -Wall -Wshadow --pedantic
ERROR =  -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check= full --verbose

SRCS = main.c sudo.c
OBJS = $(SRCS:%.c=%.o)

hw19: $(OBJS)
	$(GCC) $(OBJS) -o hw19

.c.o:
	$(GCC) -c $*.c

testall: test1 test2 test3 test4 test5 test6

test1: hw19
	./hw19	inputs/test1 > output1
	diff output1 expected/expected1
test2: hw19
	./hw19	inputs/test2 > output2
	diff output2 expected/expected2
test3: hw19
	./hw19	inputs/test3 > output3
	diff output3 expected/expected3
test4: hw19
	./hw19	inputs/test4 > output4
	diff output4 expected/expected4
test5: hw19
	./hw19	inputs/test5 > output5
	diff output5 expected/expected5
test6: hw19
	./hw19	inputs/test6 > output6
	diff output6 expected/expected6

memory: hw19
	$(VAL) ./hw19 inputs/test1 > output1

clean:
	rm -f hw19 *.o output? vallog testgen
	clear
