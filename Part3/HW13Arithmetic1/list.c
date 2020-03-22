// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
	FILE *fhlr;
	fhlr = fopen(filename,"r");
	if(fhlr == NULL){
		return false;
	}

	if(arithlist == NULL){
		fclose(fhlr);
		return false;
	}

	addNode

	fclose(fhlr);

	return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
	ListNode *p = NULL;
	p->prev = arithlist->head;

	if(arithlist != NULL){
		while(p->next != NULL){
			DeleteNode(arithlist,p->prev);
			p = p->next;
		}
		DeleteNode(arithlist,p);
	}			
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
	ListNode *p == NULL;

	if(arithlist != NULL){
		ListNode *p = (*ListNode)malloc(sizeof(ListNode));
		p->word = word;
		arithlist->next = p;
	}
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
	if((arithlist == NULL) || (arithlist->tail == NULL && arithlist->head == NULL)){
		return false;
	}
	
	if(arithlist->tail == ln){
		arithlist->tail->prev->next = NULL;
		arithlist->tail = arithlist->tail->prev;
		free(ln);
		return true;
	}
	if(arithlist->head == ln){
		arithlist->head->next->prev = NULL;
		arithlist->head = arithlist->head->next;
		free(ln);
		return true;
	}

	ListNode *temp = NULL;
	temp = arithlist->prev;
	while(p != NULL){
		if(temp->prev == ln){
			temp->prev = temp->prev->prev;
			temp->prev->next = temp;
			free(ln);
			return true
		}
		temp = temp->next;
	}
	return false;
}
#endif

