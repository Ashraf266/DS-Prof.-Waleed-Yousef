#include <stdio.h>
int Fibanocci(int);
int Fibanocci_1(int);



int main(void)
{
	printf("%d\n",Fibanocci(7));
	printf("%d",Fibanocci_1(7));
}

/* there's a lot of optimization that can be applied on these functions but this is the main idea*/

int Fibanocci(int n)/*recursion*/
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return (Fibanocci(n - 1) + Fibanocci(n - 2));
}
int Fibanocci_1(int n)/*iterative*/
{
	int i, twoback, oneback, current;
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		twoback = 0;
		oneback = 1;
		for(i=2;i<=n;i++)
		{
			current = twoback + oneback;
			twoback = oneback;
			oneback = current;
		}
	}
	return current;
}
