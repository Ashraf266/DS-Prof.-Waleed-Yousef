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

int FindItemTree(Tree *tree, TreeEntry key)
{
	if(!*tree)
		return -1;
	if((*tree)->entry == key)
	{
		return 1;
	}

	else if((*tree)->entry > key)
	{
		return FindItemTree(&(*tree)->left, key);
	}
	else
	{
		return FindItemTree(&(*tree)->right, key);
	}
}

int FindItemTreeIterative(Tree *tree, TreeEntry key)
{
	TreeNode *p = *tree;
	while(p)
	{
		if(p->entry == key)
		{
			return 1;
		}
		else if(p->entry > key)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}

	}

	return -1;
}


int FindItemTree2(Tree2 *tree, TreeEntry key)
{
	return FindItemTree(&tree->root, key);
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




void DeleteNodeTree(TreeNode **nodePtr)
{
	//Two solutions first one is to add the left tree of the deleted node to the last
	//left node in the right tree and add the right tree in place of the deleted node
	//but it's inefficient solution because the depth of the tree will increase a lot

	//the second one is to add the most right node of the left tree of the deleted node
	//in place of the deleted node .. or the most left node of the right tree of the deleted node

	//to do change current name
	TreeNode *current = *nodePtr, *prev= NULL;

	if(!current->left)
	{
		(*nodePtr) = (*nodePtr)->right;
	}
	else if(!current->right)
	{
		(*nodePtr)= (*nodePtr)->left;
	}
	else
	{
		/* inefficient solution */
//		(*nodePtr) = (*nodePtr)->right;
//		for(prev = current->right; prev->left; prev=prev->left);
//		prev->left = current->left;

		/* efficient solution */
		prev = current;
		current = current->left;
		if(!current->right)
		{
			*nodePtr = current;
			current->right = prev->right;
			current = prev;
		}
		else
		{
			while(current->right)
			{
				prev = current;
				current = current->right;
			}
//			prev->right = NULL;
//			prev = current;
//			current = *nodePtr;
//			*nodePtr = prev;
//			prev->right = current->right;
//			while(prev->left)
//			{
//				prev = prev->left;
//			}
//			prev->left = current->left;

			/* A trick is to copy the entry and delete the node easier than moving the node to the position of the deleted one */
			prev->right = current->left;
			(*nodePtr)->entry = current->entry;


		}
	}

	free(current);
}



int DeleteItemTree(Tree *tree, TreeEntry key)
{
	TreeNode *current = *tree,*prev=NULL ;
	while(current)
	{
		prev = current;
		if(current->entry == key)
		{
			break;
		}
		else if(current->entry > key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

	}

	if(!current)
	{
		return -1;
	}

	if(!prev)//delete root
	{
		DeleteNodeTree(tree);
	}
	else if(key > prev->entry)
	{
		DeleteNodeTree(&prev->right);
	}
	else
	{
		DeleteNodeTree(&prev->left);
	}

	return 1;
}

















