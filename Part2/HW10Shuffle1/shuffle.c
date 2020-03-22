// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
	int ind;
	for (ind = 0; ind < deck.size; ind ++)
	{
		printf("%c ", deck.cards[ind]);
	}
	printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
	for(int i = 0;i < origDeck.size - 1;i++){
		int lSize = i + 1;
		memcpy(leftDeck[i].cards, origDeck.cards, lSize * sizeof(char));

		int rSize = origDeck.size - i - 1;
		memcpy(rightDeck[i].cards, &(origDeck.cards[i + 1]), rSize * sizeof(char));

		leftDeck[i].size = lSize;
		rightDeck[i].size = rSize;
	}
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.

static void helper(CardDeck leftDeck, CardDeck rightDeck, CardDeck combo, int ldx, int rdx, int cdx){

	if(ldx < leftDeck.size){
		combo.cards[cdx] = leftDeck.cards[ldx];
		helper(leftDeck, rightDeck, combo, ldx + 1, rdx, cdx + 1);
	}
	if(rdx < rightDeck.size){
		combo.cards[cdx] = rightDeck.cards[rdx];
		helper(leftDeck, rightDeck, combo, ldx, rdx + 1, cdx + 1);
	}
	if(cdx == combo.size) {
		printDeck(combo);
	}
}

void interleave(CardDeck leftDeck, CardDeck rightDeck)
{		
	CardDeck combo;
	combo.size = leftDeck.size + rightDeck.size;
	helper(leftDeck, rightDeck, combo, 0, 0, 0);
}
#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
{
	//calculate num possible l and r decks
	
	CardDeck *leftDeck;
	CardDeck *rightDeck;
	
	int pos = origDeck.size - 1;

	//malloc for l and r
	
	leftDeck = malloc(sizeof(CardDeck) * pos);
	rightDeck = malloc(sizeof(CardDeck) * pos);	

	divide(origDeck, leftDeck, rightDeck);

	//call interleave

	for(int i = 0;i < pos;i++){	
		interleave(leftDeck[i], rightDeck[i]);
	}

	//release
	
	free(leftDeck);
	free(rightDeck);
}
#endif
