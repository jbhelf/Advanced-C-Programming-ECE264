#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void shuffle(CardDeck origDeck, int round)
{
	CardDeck *leftDeck;
	CardDeck *rightDeck;	

	int pos = origDeck.size - 1;

	leftDeck = malloc(sizeof(CardDeck) * pos);
	rightDeck = malloc(sizeof(CardDeck) * pos);

	divide(origDeck, leftDeck, rightDeck);

	for(int i = 0;i < pos;i++){
		interleave(leftDeck[i], rightDeck[i], round);
	}

	free(leftDeck);
	free(rightDeck);
}

static void printDeck(CardDeck deck){
	int i;
	for(i = 0;i < deck.size;i++){
		printf("%c ",deck.cards[i]);
	}
	printf("\n");
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck){
	for(int i = 0;i < origDeck.size - 1;i++){
		int lSize = i + 1;
		memcpy(leftDeck[i].cards, origDeck.cards, lSize * sizeof(char));

		int rSize = origDeck.size - i - 1;
		memcpy(rightDeck[i].cards, &(origDeck.cards[i + 1]), rSize * sizeof(char));

		leftDeck[i].size = lSize;
		rightDeck[i].size = rSize;
	}
}

static void helper(CardDeck leftDeck, CardDeck rightDeck, CardDeck combo, int ldx, int rdx, int cdx, int round){
	if(ldx < leftDeck.size){
		combo.cards[cdx] = leftDeck.cards[ldx];
		helper(leftDeck, rightDeck, combo, ldx + 1, rdx, cdx + 1, round);
	}
	if(rdx < rightDeck.size){
		combo.cards[cdx] = rightDeck.cards[rdx];
		helper(leftDeck, rightDeck, combo, ldx, rdx + 1, cdx + 1, round);
	}
	if(cdx == combo.size && round != 0){
		shuffle(combo, round - 1);
		printDeck(combo);
	}
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round){
	CardDeck combo;
	combo.size = leftDeck.size + rightDeck.size;
	helper(leftDeck, rightDeck, combo, 0, 0, 0, round);
}
