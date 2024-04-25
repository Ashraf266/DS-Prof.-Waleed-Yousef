#include <stdio.h>
#include "Stack_linkedBased_Module/stack.h"

uint8 IsDigit(char c);
uint8 Precedent(char op1 , char op2);
void InfixToPostfix(char infix[],char postfix[]);
int Oper(char,int,int);
int EvaluatePostfix(char *postfix);

int main(void)
{

	char infix[] = "1+2*3$4/5-6";
	char postfix[sizeof(infix)/sizeof(infix[0])];

	InfixToPostfix(infix, postfix);
	printf("%s\n",infix);
	printf("%s = %d",postfix,EvaluatePostfix(postfix));

}
/*Check if the input is a digit*/
uint8 IsDigit(char c)
{
	return (c >= '0' && c <= '9');
}

/*if op1 > op1 return 1 else return 0*/
/*'$' is for power operator*/
uint8 Precedent(char op1 , char op2)
{
	if(op1 == '$')
		return 1;
	else if(op1 == '*' || op1 == '/')
		return op2 != '$';
	else
		return (op2 == '+' || op2 == '-');
}
/*
 * in this case there's a lot of limitations
 * 1-only single digits
 * 2-only positive integers
 * 3-no unary operators allowed
 * 4-no brackets
 * 5-no handling for invalid expressions -extra operator or -invalid order
 * 6-no character allowed (Easiest to solve)
 * 				"Maybe i'll rewrite it in the future with putting those limitations into considerations"
 */
/*converts Infix to Postfix but note that this function only works if the operands of any operation is just one digit*/
void InfixToPostfix(char infix[],char postfix[])
{
	Stack s;
	STACK_initializeStack(&s);
	StackEntry op;
	int i=0,j=0;
	while(infix[i] != '\0')
	{
		if(IsDigit(infix[i]))
		{
			postfix[j] = infix[i];
			j++;
		}
		else
		{
			if(!(STACK_stackEmpty(&s)))
			{
				STACK_peek(&op, &s);
			}
			while(!(STACK_stackEmpty(&s)) && Precedent(op,infix[i]))
			{
				STACK_pop(&op,&s);
				postfix[j] = op;
				j++;
				if(!(STACK_stackEmpty(&s)))
					STACK_peek(&op,&s);
			}
			STACK_push(infix[i],&s);
		}
		i++;
	}
	while(!(STACK_stackEmpty(&s)))
	{
		STACK_pop(&op, &s);
		postfix[j++] = op;
	}
	postfix[j] = '\0';
}

int Oper(char operator,int op1,int op2)
{
	switch(operator)
	{
	case '+':
		return op1 + op2;
		break;
	case '-':
		return op1 - op2;
		break;
	case '*':
		return op1 * op2;
		break;
	case '/':
		return (unsigned char)op1 / op2; /*an annoying bug this fixes it temporarily*/
		break;
	case '$':
		if(op2 == 0)
			return 1;
		int i,val=1;
		for(i=0;i<op2;i++)
		{
			val *= op1;
		}
		return val;
		break;
	}
	return -1;
}
/*there's a problem her about stackEntry i defined it in the header file as char but here i want it to save int
 * so the problem is in the Stack_Module it self i need to edit it to be generic with whatever i put in it
 * This will take a lot of time to resturcture the whole module .. maybe it's better to be written with template in c++
 * so i'll but another limitation here and i'll fix it later maybe
 * if the postfix operation value is more than 255 it will be written only 255 !!!!!!!!!!!!!!!!
 */
int EvaluatePostfix(char *postfix)
{
	Stack s;
	STACK_initializeStack(&s);
	int i=0;
	StackEntry op1,op2;
	int val=0;
	while(postfix[i] != '\0')
	{
		if(IsDigit(postfix[i]))
		{
			STACK_push(postfix[i]-'0',&s);
		}
		else
		{
			STACK_pop(&op2,&s);
			STACK_pop(&op1,&s);
			val = Oper(postfix[i],op1,op2);
			STACK_push((char)val,&s);
		}
		i++;
	}
	STACK_pop((char *)&val,&s);
	return val;
}
