// ***
// *** DO NOT modify this file
// ***

#ifndef LIST_H
#define LIST_H

#define WORDLENGTH 10
// assume each numbers use at most 9 digits
<<<<<<< HEAD
// the fifth character stores '\0'
=======
// the tenth character stores '\0'
>>>>>>> fdda0c67c6732be4491fe3a3a328a4451aed0717

#include <stdbool.h>

typedef struct Node
{
  char word[WORDLENGTH];
  // word is a string and one element must be '\0'
  struct Node * next;
  struct Node * prev;
  // doubly linked list
} ListNode;

typedef struct
{
  ListNode * head;
  ListNode * tail;
} List;

bool readList(char * filename, List * arithlist);
void deleteList(List * arithlist);
void addNode(List * arithlist, char * word);
bool deleteNode(List * arithlist, ListNode * ln);

#endif
