#include "Queue_arrayBased_Module/queue.h"
#include <stdio.h>

void DisplayElement(QueueEntry e)
{
	printf("%d\n",e);
}

int main(void)
{

	Queue q;
	QueueEntry e;

	InitializeQueue(&q);
	Append(5, &q);
	Append(6, &q);
	Append(7, &q);
	Append(8, &q);
	Append(9, &q);
	Append(10, &q);
	Serve(&e, &q);
	printf("%d\n",e);
	Retrieve(&e, &q);
	printf("%d\n",e);
	printf("--------------\n");
	TraverseQueue(&q, DisplayElement);
	ClearQueue(&q);
	printf("--------------\n");
	TraverseQueue(&q, DisplayElement);
	printf("--------------\n");
	Append(20, &q);
	TraverseQueue(&q, DisplayElement);


	return 0;
}
