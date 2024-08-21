/*
 * Tree.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Ashraf
 */
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "stack.h"

void CreateTree(Tree *tree)
{
	*tree = NULL;
}

void CreateTree2(Tree2 *tree)
{
	tree->root = NULL;
	tree->size = 0;
	tree->depth = 0;
}

int TreeEmpty(Tree *tree)
{
	return (!tree);
}

int TreeEmpty2(Tree2 *tree)
{
	return (!tree->root);
}

int TreeFull(Tree *tree)
{
	return 0;
}

int TreeFull2(Tree2 *tree)
{
	return 0;
}




void Inorder(Tree *tree, void (*func)(TreeEntry))
{
	if(*tree)
	{
		Inorder(&(*tree)->left, func);
		(*func)((*tree)->entry);
		Inorder(&(*tree)->right, func);
	}

}

void InorderIterative(Tree *tree, void (*func)(TreeEntry))
{
	Stack s;
	STACK_initializeStack(&s);
	void *p = (void *)(*tree);
	if(p)
	{
		do
		{
			while(p)
			{
				STACK_push(p, &s);
				p = ((TreeNode *)p)->left;
			}

			STACK_pop(&p, &s);
			(*func)(((TreeNode *)p)->entry);;
			p = ((TreeNode *)p)->right;

		}while(!STACK_stackEmpty(&s)||p);

	}
}

void Inorder2(Tree2 *tree, void (*func)(TreeEntry))
{
	Inorder(&tree->root, func);
}

void Inorder2Iterative(Tree2 *tree, void (*func)(TreeEntry))
{
	InorderIterative(&tree->root, func);
}


//void ClearTree(Tree *tree)
//{
//	if(*tree)
//	{
//		ClearTree(&((*tree)->left));
//		ClearTreee(&((*tree)->right));
//		free(*tree);
//		*tree=NULL; //we can do it once
//	}
//}

void ClearTreeAux(Tree *tree)
{
	if(*tree)
	{
		ClearTree(&((*tree)->left));
		ClearTree(&((*tree)->right));
		free(*tree);
	}
}

void ClearTree(Tree *tree)
{
	ClearTreeAux(tree);
	*tree=NULL;

}



void ClearTree2(Tree2 *tree)
{
	ClearTree(&tree->root);
	tree->depth= 0;
	tree->size= 0;
}


void InsertNode(Tree *tree, TreeEntry *pe)
{
	if(! *tree)//first node
	{
		*tree = (Tree)malloc(sizeof(TreeNode));
		(*tree)->entry= *pe;
		(*tree)->left= NULL;
		(*tree)->right= NULL;
	}
	else if((*tree)->entry > *pe)
	{
		InsertNode(&(*tree)->left, pe);
	}
	else
	{
		InsertNode(&(*tree)->right, pe);
	}
}

void InsertNodeIterative(Tree *tree, TreeEntry *pe)
{
	TreeNode *current = *tree;
	TreeNode *prev;
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	node->entry= *pe;
	node->left= NULL;
	node->right= NULL;

	if(!*tree)
		*tree = node;
	else
		while(current){

			prev = current;
			if(current->entry > *pe)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}

	if(prev->entry > *pe)
	{
		prev->left = node;
	}
	else
	{
		prev->right = node;
	}


}

void InsertNodeAux(Tree *tree, TreeEntry *pe,int *pdepth)
{
	if(! *tree)//first node
	{
		*tree = (Tree)malloc(sizeof(TreeNode));
		(*tree)->entry= *pe;
		(*tree)->left= NULL;
		(*tree)->right= NULL;
	}
	else if((*tree)->entry > *pe)
	{
		InsertNodeAux(&(*tree)->left, pe, pdepth);
	}
	else
	{
		InsertNodeAux(&(*tree)->right, pe, pdepth);
	}
	(*pdepth)++;
}

void InsertNode2(Tree2 *tree, TreeEntry *pe)
{
	int d=0;
	InsertNodeAux(&tree->root, pe, &d);
	if(tree->depth < d)
		tree->depth= d;
	tree->size++;

}

int TreeSize(Tree *tree)
{
	if(!*tree)
		return 0;
	return (1+ TreeSize(&(*tree)->left) + TreeSize(&(*tree)->right));
}
int TreeDepth(Tree *tree)
{
	if(!*tree)
		return 0;
	//max of depth of the left and the right
	int DL = TreeDepth(&(*tree)->left);
	int DR = TreeDepth(&(*tree)->right);

	return DL > DR? DL+1:DR+1;
}

int TreeSize2(Tree2 *tree)
{
	return tree->size;
}
int TreeDepth2(Tree2 *tree)
{
	return tree->depth;
}


