/******************************************************************************
 *
 * Module: Stack_arrayBased
 *
 * File Name: stack.c
 *
 * Description: Source file for the Stack Module
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "stack.h"

/*
 * Description:
 * initialize the stack by assigning the top value to the first index "0"
 */
void STACK_initializeStack(Stack *ps)
{
	ps->top = 0;
}

/*
 * pre: stack not Full
 *
 * Description:
 * push an element to the first available location in the stack
 */
void STACK_push(StackEntry e,Stack *ps)
{
	ps->entry[ps->top++] = e;

	/* Another Way instead of the above */

	/* 		ps->entry[ps->top] = e;
	 * 		ps->top++;
	 */
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Checks if the stack is full
 */
uint8 STACK_stackFull(Stack *ps)
{
	if(ps->top == MAXSTACK)
	{
		return STACK_IS_FULL;
	}
	else
	{
		return STACK_IS_NOT_FULL;
	}

	/* Another Way instead of the above */

	/* return ps->top == MAXSTACK; */
}

/*
 * pre: stack not empty
 *
 * Description:
 * pop the last element of the stack and decrement the the top by 1
 */
void STACK_pop(StackEntry *pe,Stack *ps)
{
	*pe = ps->entry[--ps->top];

	/* Another Way instead of the above */

	/*		ps->top--;
	 *  	*pe = ps->entry[ps->top];
	 */
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Checks if the stack is empty
 */
uint8 STACK_stackEmpty(Stack *ps)
{
	if(ps->top == 0)
	{
		return STACK_IS_EMPTY;
	}
	else
	{
		return STACK_IS_NOT_EMPTY;
	}

	/* Another Way instead of the above */

	/* return ps->top == 0;
	 * or
	 * return !ps->top;
	 */
}

/*
 * pre: stack not empty
 *
 * Description:
 * Get the last element Entered the stack without removing it
 */
void STACK_peek(StackEntry *pe,Stack *ps)
{
	*pe = ps->entry[ps->top - 1];
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Get the value of the current size of the stack
 */
uint64 STACK_stackSize(Stack *ps)
{
	return ps->top;
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Clear the entire stack
 */
void STACK_clearStack(Stack *ps)
{
	ps->top = 0;
}

/*
 * pre: stack is initialized
 *
 * Description:
 * takes a function from the user through out a pointer to function and implement that
 * function to all the element of the stack from the top to the entry
 */
void STACK_traverseStack(Stack *ps,void (*pf)(StackEntry))
{
	int i;
	for(i=ps->top;i>0;i--)
		(*pf)(ps->entry[i-1]);
}
