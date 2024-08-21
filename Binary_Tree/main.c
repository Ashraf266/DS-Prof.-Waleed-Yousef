#include <stdio.h>
#include "Tree.h"


void print(TreeEntry e)
{
	printf("%d\n",e);
}

int main(void)
{

	Tree t1;
	Tree2 t2;

	CreateTree(&t1);
	CreateTree2(&t2);

	TreeNode n4 = {4, NULL, NULL};
	TreeNode n3 = {3, &n4, NULL};
	TreeNode n2 = {2, NULL, NULL};
	TreeNode n1 = {1, &n2, &n3};

	t1 = &n1;
	t2.root = &n1;

	InorderIterative(&t1, print);
	Inorder2(&t2, print);




	return 0;
}
