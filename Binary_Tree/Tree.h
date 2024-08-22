/*
 * Tree.h
 *
 *  Created on: Aug 21, 2024
 *      Author: Ashraf
 */

#ifndef TREE_H_
#define TREE_H_

#include "Global.h"

typedef struct treenode {

	TreeEntry entry;
	struct treenode *left, *right;

}TreeNode;


typedef TreeNode* Tree;//book def.

typedef struct tree {
	Tree root;
	int size;
	int depth;
	//other fields if needed
}Tree2;//our def.




void CreateTree(Tree *);
int TreeEmpty(Tree *);
int TreeFull(Tree *);//return 0 always
void ClearTree(Tree *);
int TreeSize(Tree *);
int TreeDepth(Tree *);
void Preorder(Tree*, void (*)(TreeEntry));
void Inorder(Tree*, void (*)(TreeEntry));
void InorderIterative(Tree *tree, void (*func)(TreeEntry));
void Postorder(Tree*, void (*)(TreeEntry));
void InsertNode(Tree*, TreeEntry*);
void InsertNodeIterative(Tree *tree, TreeEntry *pe);
int FindItemTree(Tree *, TreeEntry);
int FindItemTreeIterative(Tree *, TreeEntry);
int DeleteItemTree(Tree *, TreeEntry);//assuming that the TreeEntry is not a structure


void CreateTree2(Tree2 *);
int TreeEmpty2(Tree2 *);
int TreeFull2(Tree2 *);//return 0 always
void ClearTree2(Tree2 *);
int TreeSize2(Tree2 *);
int TreeDepth2(Tree2 *);
void Preorder2(Tree2*, void (*)(TreeEntry));
void Inorder2(Tree2*, void (*)(TreeEntry));
void Inorder2Iterative(Tree2 *tree, void (*func)(TreeEntry));
void Postorder2(Tree2*, void (*)(TreeEntry));
void InsertNode2(Tree2*, TreeEntry*);
int FindItemTree2(Tree2 *tree, TreeEntry key);



#endif /* TREE_H_ */
