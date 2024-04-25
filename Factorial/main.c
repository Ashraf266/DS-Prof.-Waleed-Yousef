#include <stdio.h>
int Factorial(int n);
int Factorial_1(int n);



int main(void)
{
	printf("%d\n",Factorial(6));
	printf("%d\n",Factorial_1(6));

	return 0;
}

/* there's a lot of optimization that can be applied on these functions but this is the main idea*/

int Factorial(int n)/*recursion*/
{
	if(n == 0)
		return 1;
	else
		return n*Factorial(n-1);
}

int Factorial_1(int n)/*iterative*/
{
	int product = 1;
	if(n == 0)
		return 1;
	else
		for(;n>0;n--)
			product *= n;
	return product;
}
