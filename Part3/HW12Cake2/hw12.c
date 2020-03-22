// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
	ListNode * p = head;
	printf("printListNode: ");
	while (p != NULL)
	{
		printf("%7d ", p -> value);
		p = p -> next;
	}
	printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
	ListNode * head = NULL;
	ListNode * p = NULL;
	ListNode * t = NULL;

	for(int i = 0;i < valn;i++){
		t = (ListNode*)malloc(sizeof(ListNode));
		t->value = i;
		t->next = NULL;
		if(head == NULL){
			head = t;
		}else{
			p = head;
			while(p->next != NULL){
				p = p->next;
			}
			p->next = t;
		}
	}
	return(head);	
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
	ListNode * p;
	ListNode * next;
	p = head;

	while(head->next != NULL){ 
		for(int i = 0;i < valk-1;i++){ //counting loop
			//printf("%d\n",i);
			if(p->next == NULL){
				p = head;	
			
			}else{
				p = p->next;
			}
		}
#ifdef DEBUG
		// this #ifdef ... #endif should be inside the condition *BEFORE* a
		// node' value is printed and it is deleted
		ListNode * todelete = p;
		next = p->next;
		if(next == NULL){
			next = head;		
		}
		printListNode (todelete); 
		head = deleteNode(head, todelete); //added
		p = next;
#endif
	}
	printf("%d\n", head->value);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
	if(head == NULL){
		return(NULL);
	}
	if(head == todelete){ 
		head = head->next;
		printf("%d\n", todelete->value);
		free(todelete);		
		return(head);
	}

	//Summary of below:
	//
	//runs through entire list and if todelete is in the list, head is returned,
	//otherwise, it goes to the next index
	ListNode *t = NULL; //test for cond3
	ListNode * before = head;
	t = head->next; //test for cond3
	while(t->next != NULL && t != todelete){
		before = t;		
		t = t->next;
	}
	
	if(t == todelete){
		//delete node
		before->next = t->next;
		t->next = NULL;
		printf("%d\n", t->value);
		free(t);

		}
	return head;	
}
#endif


