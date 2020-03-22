// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
<<<<<<< HEAD
	int ind;
	int numop = sizeof(Operations) / sizeof(int);
	for (ind = 0; ind < numop; ind ++)
=======
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
>>>>>>> fdda0c67c6732be4491fe3a3a328a4451aed0717
	{
		char *loc = strchr(word, Operations[ind]);
		if(loc != NULL && !isdigit(loc[1]))
		{
			return ind;
		}
	}
	return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
{
	if (arithlist == NULL)
	{
		return true;
	}
	if ((arithlist -> head) == NULL)
	{
		return true;
	}

	// go through the list until there is only node in the list
	// find the next operator
	// If no operator can be found, return false
	// If an operator is found, find the two previous nodes as operands
	// If cannot find previous two operands, return false
	// If two operands can be found, perform the arithmetic operation

	ListNode *operators;
	
	int tOp;
	int opL;
	int opR;
	int opfl;

	ListNode *temp = NULL;
	temp = arithlist->head;	
	
	while(arithlist->head != arithlist->tail){
		tOp = isOperator(temp->word);
		if(tOp == -1){
			temp = temp->next;
		}else if(tOp == 2){
			opL = atoi(temp->prev->prev->word);
			opR = atoi(temp->prev->word);
			if(opR == NULL || opL == NULL){
				return false;
			}
			strcpy(temp->word, (opL * opR));
			opfl++;	
		}else if(tOp == 1){	
			opL = atoi(temp->prev->prev->word);
			opR = atoi(temp->prev->word);
			if(opR == NULL || opL == NULL){
				return false;
			}
			strcpy(temp->word, (opL - opR));
			opfl++;
		}else{	
			opL = atoi(temp->prev->prev->word);
			opR = atoi(temp->prev->word);
			if(opR == NULL || opL == NULL){
				return false;
			}
			strcpy(temp->word, (opL + opR));
			opfl++;
		}
		if(opfl == 1){
			while(arithlist->head != temp){
				deleteNode(arithlist,temp->prev);
				temp = temp->prev;
			}
			temp = temp->next;
			deleteNode(arithlist, temp->prev);
			opfl--;
		}
	}


	// Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
	//    not 2 - 4
	// After the operation,
	//     put the result back to the list
	//     remove the two nodes used to store the two operands
	// After going through the entire list and performing the operations,
	//     the list should have exactly one node left. If this is not
	//     true, return false
	// If the input is valud, return true



	// if more than one node left, return false

	// if the remaining node is an operator, return false
	if(isOperator(arithlist->tail) != -1){
		return false;
	}
	// if everything is OK, return true
	return true;
}
#endif
