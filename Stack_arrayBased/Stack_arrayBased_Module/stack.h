/******************************************************************************
 *
 * Module: Stack_arrayBased
 *
 * File Name: stack.h
 *
 * Description: Header file for the Stack Module
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef STACK_H_
#define STACK_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MAXSTACK				100
#define STACK_IS_FULL			(1u)
#define STACK_IS_NOT_FULL		(0)
#define STACK_IS_EMPTY          (1u)
#define STACK_IS_NOT_EMPTY		(0)

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/*Please Define your own DataType for the stack Elements*/
typedef uint8 StackEntry;

/*Stack Structure*/
typedef struct
{
	uint64 top;
	StackEntry entry[MAXSTACK];
}Stack;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * initialize the stack by assigning the top value to the first index "0"
 */
void STACK_initializeStack(Stack *);

/*
 * Description:
 * push an element to the first available location in the stack
 */
void STACK_push(StackEntry,Stack *);

/*
 * Description:
 * Checks if the stack is full
 */
uint8 STACK_stackFull(Stack *);

/*
 * Description:
 * pop the last element of the stack and decrement the the top by 1
 */
void STACK_pop(StackEntry *,Stack *);

/*
 * Description:
 * Checks if the stack is empty
 */
uint8 STACK_stackEmpty(Stack *);

/*
 * Description:
 * Get the last element Entered the stack without removing it
 */
void STACK_peek(StackEntry *,Stack *);

/*
 * Description:
 * Get the value of the current size of the stack
 */
uint64 STACK_stackSize(Stack *);

/*
 * Description:
 * Clear the entire stack
 */
void STACK_clearStack(Stack *);

/*
 * Description:
 * takes a function from the user through out a pointer to function and implement that
 * function to all the element of the stack from the top to the entry
 * !!!"the function written by the user must take StackEntry as a parameter and return void"!!!
 */
void STACK_traverseStack(Stack *,void (*)(StackEntry));

#endif
