// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
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

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

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
