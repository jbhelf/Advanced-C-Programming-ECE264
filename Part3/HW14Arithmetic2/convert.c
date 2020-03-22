// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
	int ind;
	int numop = sizeof(Operations) / sizeof(int);
	for (ind = 0; ind < numop; ind ++)
	{
		char *loc = strchr(word, Operations[ind]);
		if (loc != NULL && !isdigit(loc[1]))
		{
			return ind;
		}
	}
	return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT
static ListNode arithCheck(ListNode *operand, ListNode *operator, ListNode *p){
	int future = isOperator(p->next->word); //CHECK NEXT OPERATOR
	while(future == -1){
		p = p->next;
		future = isOperator(p->next->next->word); //CHECK NEXT OPERATOR
	}
	if(future == 0 || future == 1){ //if next operator is additionor subtraction
		operand->word = p->next->word;
		//special case above

		addList(operator, operand); //add to the list
		p = p->next->next;
	}else if(future == 2){ //if multiply next
		while(p == -1){
			p = p->next; //prepare to store next operand		
		}

		operand = (*ListNode)malloc(sizeof(ListNode));
		operand->word = p->word;
		operand = operand->next;

		while(!(p ==-1)){
			p = p->next; //prepare to store next operator
		}

		operator = (*ListNode)malloc(sizeof(ListNode));
		operator->word = p->word;
		operator = operator->next; //insert * to list

		addList(operand, operator); //for *
		operator = operator->prev; //shift from NULL to -+
		addList(operand, operator); //for -+
	}else if(future == 3){ //if open parenthesis

		helper(operand, operator, p); //deal with parenthesis first


		/*EXPLANATION OF THIS CONDITION:
		 *
		 *	treat everything within the bordering parenthesis as a variable, x
		 *	once 'x' figured out, insert the arithmetic into list, checking
		 *	if a * or a -+ is after parenthesis.
		 */	

		future = isOperator(p->next->next->word); //CHECK NEXT OPERATOR

		if(future == 0 || future == 1)/*operator after parentesis is NOT a *...*/{
			operand = (*ListNode)malloc(sizeof(ListNode));
			operand->word = p->word;
			operand = operand->next; //insert -+ to list
			operator = operator->prev;
			free(operator->next);
		}else{
			//should recursively call arithCheck, until a -+, or NO OPERATOR operator is reached, and then add
			//the operator BEFORE the parenthesis first

			arithCheck(operand, operator, p); //making to check for the NEXT operator

			while(isOperator(p->word) == 2){ //while next operator is *...
				addList(operand, operator);

				operand->next = (*ListNode)malloc(sizeof(ListNode));
				operand = operand->next;
				p = p->next;
				operand->word = p->word;

				p = p->next; //shift to next operator
			}

			addList(operand, operator); //for the operator befor the parenthesis
		}
	}

	return(p); //return the continuation of the list
}

static void addList(ListNode *operand, ListNode *operator){

	//NOTE:
	//
	//	if issues arise with this logic, consider using strcpy???
	//

	operand->next = (*ListNode)malloc(sizeof(ListNode));
	operand = operand->next;
	operand->word = operator->word;
	operator = operator->prev;
	free(operator->next); //does this destroy my list???
}

static void helper(ListNode *operand, ListNode *operator, ListNode *p){
	int temp;
	int bCount;	

	while(p->word != NULL){
		temp = isOperator(p->word);
		if(temp == -1){ //JUST THE STORAGE OF THE OPERAND
			operand = (*ListNode)malloc(sizeof(ListNode));
			operand->word = p->word;
			operand = operand->next;
		}else{ //JUST THE STORAGE OF THE OPERATOR
			operator = (*ListNode)malloc(sizeof(ListNode));
			operator->word = p->word;
			operator = operator->next;
		}

		if(temp == 0 || temp == 1){	
			arithCheck(operand, operator, p);
		}else if(temp == 2){
			addList(operand, operator);
		}else if(temp == 3){ //open parenthesis case
			helper(operand, operator, p);
		}	
	}
}

bool convert(List * arithlist)
{
	ListNode *operator = NULL;
	ListNode *operand = NULL;
	ListNode *p = NULL;

	p = arithlist->head;

	helper(operand, operator, p);

	if (arithlist == NULL)
	{
		return true;
	}
	if ((arithlist -> head) == NULL)
	{
		return true;
	}
	return true;
}
#endif
