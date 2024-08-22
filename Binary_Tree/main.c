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

	TreeEntry element = 6;
	InsertNode(&t1, &element);
	InsertNode2(&t2, &element);
	element = 4;
	InsertNode(&t1, &element);
	InsertNode2(&t2, &element);
	element = 5;
	InsertNode(&t1, &element);
	InsertNode2(&t2, &element);
	element = 2;
	InsertNode(&t1, &element);
	InsertNode2(&t2, &element);
	element = 3;
	InsertNode(&t1, &element);
	InsertNode2(&t2, &element);

	InorderIterative(&t1, print);
	Inorder2(&t2, print);
	printf("Tree Size: %d\nTree Depth: %d\n",TreeSize(&t1), TreeDepth(&t1));
	printf("Tree Size: %d\nTree Depth: %d\n",TreeSize2(&t2), TreeDepth2(&t2));

	printf("Find 5==> %d\n",FindItemTreeIterative(&t1, 5));
	printf("Find 0==> %d\n",FindItemTreeIterative(&t1, 0));


	return 0;
}
