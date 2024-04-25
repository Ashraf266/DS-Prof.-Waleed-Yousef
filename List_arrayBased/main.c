#include "List_arrayBased_Module/list.h"
#include <stdio.h>


void Display(ListEntry e)
{
	printf("Element = %d\n",e);
}

int main(void)
{

	List list;
	ListEntry e;

	createList(&list);
	if(!listFull(&list))
		insertList(0, 6, &list);
	if(!listFull(&list))
		insertList(0, 7, &list);
	if(!listFull(&list))
		insertList(0, 8, &list);
	if(!listFull(&list))
		insertList(0, 9, &list);

	printf("%d\n",list.size);

	if(!listEmpty(&list))
		deleteList(3, &e, &list);

	printf("elemnt = %d\n",e);
	printf("%d\n",list.size);

	printf("The List: \n");
	traverseList(&list, Display);

	if(!listFull(&list))
			/* insert at the end */
			insertList(listSize(&list), 12, &list);
	if(!listFull(&list))
			/* insert at the beginning */
			insertList(0, 13, &list);

	printf("The List: \n");
	traverseList(&list, Display);
	return 0;
}
