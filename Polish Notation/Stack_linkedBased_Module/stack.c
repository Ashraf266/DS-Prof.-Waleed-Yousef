/******************************************************************************
 *
 * Module: Stack_linkedBased
 *
 * File Name: stack.c
 *
 * Description: Source file for the Stack Module
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "../Stack_linkedBased_Module/stack.h"
#include <stdlib.h>

/*
 * Description:
 * initialize the stack by assigning the top value to the first index "0"
 */
void STACK_initializeStack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0; /*upgrade*/
}

/*
 * pre: stack is initialized
 *
 * Description:
 * push an element to the first available location in the stack
 */
void STACK_push(StackEntry e,Stack *ps)
{
	StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
	/*we can check whether the allocation failed or not by checking if(pn == NULL) but i won't in this case*/

	pn->entry = e;
	pn->next = ps->top;
	ps->top = pn;
	ps->size++; /*upgrade*/
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Checks if the stack is full
 *
 * we didn't delete that function because we want to stay consistent with the previous module (arrayBased)
 * and we don't want the user to change any thing if we replaced one module with the other
 */
uint8 STACK_stackFull(Stack *ps)
{
	return STACK_IS_NOT_FULL;
}

/*
 * pre: stack not empty
 *
 * Description:
 * pop the last element of the stack and decrement the the top by 1
 */
void STACK_pop(StackEntry *pe,Stack *ps)
{
	StackNode *pn = ps->top;
	*pe = ps->top->entry;
	ps->top = ps->top->next;
	free(pn);
	ps->size--;/*upgrade*/
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Checks if the stack is empty
 */
uint8 STACK_stackEmpty(Stack *ps)
{

	if(ps->top == NULL)
		{
			return STACK_IS_EMPTY;
		}
		else
		{
			return STACK_IS_NOT_EMPTY;
		}

	/* Another Way instead of the above */

	/*
	 * return ps->top == NULL;
	 * or
	 * return !(ps->top);
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
	*pe = ps->top->entry;
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Get the value of the current size of the stack
 */
uint64 STACK_stackSize(Stack *ps)
{
	return ps->size; /*upgrade*/

	/*
	uint64 counter;
	StackNode * pn = ps->top;
	for(counter = 0; pn; pn = pn->next)
		counter++;
	return counter;
	*/
}

/*
 * pre: stack is initialized
 *
 * Description:
 * Clear the entire stack
 */
void STACK_clearStack(Stack *ps)
{
	StackNode *pn = ps->top;
	/*StackNode *qn = ps->top;*/

	while(pn) /* == (pn != NULL) */
	{
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	ps->size = 0;
	/*ps->top = NULL;*/
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
	StackNode *pn = ps->top;
	while(pn)
	{
		(*pf)(pn->entry);
		pn = pn->next;
	}
}
