// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
	Tree * t = malloc(sizeof(Tree));
	t -> root = NULL;
	return t;
}

void deleteTreeNode(TreeNode * tr)
{
	if (tr == NULL)
	{
		return;
	}
	deleteTreeNode (tr -> left);
	deleteTreeNode (tr -> right);
	free (tr);
}

void freeTree(Tree * tr)
{
	if (tr == NULL)
	{
		// nothing to delete
		return;
	}
	deleteTreeNode (tr -> root);
	free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE

TreeNode * newNode(int data){
	TreeNode *node =(TreeNode*)malloc(sizeof(TreeNode));
	node->value = data;
	node->left = NULL;
	node->right = NULL;
	return(node);	
}

int search(int *oArr, int in, int fin, int target){
	int temp;
	for(int j = in; j <= fin;j++){
		if(oArr[j] == target){
			temp = j;
		}
	}
	return(temp);
}

TreeNode * helper(int *inArr,int *postArr, int start, int end, int *pInd){
	if(start > end){
		return NULL;
	}

	TreeNode *node = newNode(postArr[*pInd]);
	(*pInd)--;

	if(start == end){
		return(node);
	}

	int fInd = search(inArr, start, end, node->value);

	node->right = helper(inArr, postArr, fInd + 1, end, pInd);
	node->left = helper(inArr, postArr, start, fInd - 1, pInd);

	return(node);
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
	int ind = size - 1;

	Tree *node = NULL;

	node = (Tree*)malloc(sizeof(Tree));	

	node->root = helper(inArray, postArray, 0, size - 1, &ind);

	return(node);
}

#endif

#ifdef TEST_PRINTPATH

void finder(int val, TreeNode *node, Tree *tr){	
	if(node->value != val){
		if(node != NULL){
			finder(val, node->right, tr);
			finder(val, node->left, tr);
		}
	}
	printf("%d\n", node->value);

	if(node == tr->root){
		return;
	}

/*	if(node == NULL){
	 return 0;
	}
	if(node->value == val){
		printf("%d\n", node->value);
		return 1;
	}
	if(finder(val, node->right)){
		printf("%d\n", node->value);
		return 1;
	}
	if(finder(val, node->left)){
		printf("%d\n", node->value);
		return 1;
	}*/
	
}

void printPath(Tree * tr, int val)
{
	//int t;
	finder(val, tr->root, tr);
}
#endif
