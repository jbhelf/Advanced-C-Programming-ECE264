# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
OUTPATH="output"
TESTFALGS = -DTEST_SWAP -DTEST_SORT

SRCS = main.c sort.c
OBJS = $(SRCS:%.c=%.o)

sort: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o sort

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5 test6

test1: sort
	./sort inputs/test1 > $(OUTPATH)/output1
	diff $(OUTPATH)/output1 expected/expected1

test2: sort
	./sort inputs/test2 > $(OUTPATH)/output2
	diff $(OUTPATH)/output2 expected/expected2

test3: sort
	./sort inputs/test3 > $(OUTPATH)/output3
	diff $(OUTPATH)/output3 expected/expected3

test4: sort
	./sort inputs/test4 > $(OUTPATH)/output4
	diff $(OUTPATH)/output4 expected/expected4

test5: sort
	./sort inputs/test5 > $(OUTPATH)/output5
	diff $(OUTPATH)/output5 expected/expected5

test6: sort
	./sort inputs/test6 > $(OUTPATH)/output6
	diff $(OUTPATH)/output6 expected/expected6

clean: # remove all machine generated files
	rm -f sort *.o output?


