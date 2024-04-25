#include <stdio.h>
#include "Stack_arrayBased_Module/stack.h"

void Display(StackEntry e)
{
	printf("Element = %d\n",e);
}
int main(void)
{
	Stack s;
	StackEntry e;
	STACK_initializeStack(&s);
	if(!STACK_stackFull(&s))
		STACK_push(20, &s);
	if(!STACK_stackFull(&s))
		STACK_push(21, &s);
	if(!STACK_stackFull(&s))
		STACK_push(22, &s);
	if(!STACK_stackFull(&s))
		STACK_push(23, &s);
	if(!STACK_stackFull(&s))
		STACK_push(24, &s);
	if(!STACK_stackEmpty(&s))
		STACK_pop(&e,&s);
	STACK_traverseStack(&s, Display);
	printf("Stack size = %llu",STACK_stackSize(&s));

	return 0;
}
