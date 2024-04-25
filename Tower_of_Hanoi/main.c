#include <stdio.h>

void MoveDisks(int count ,int start, int finish, int temp);
void MoveDisks_1(int count ,int start, int finish, int temp);
void MoveDisks_2(int count ,int start, int finish, int temp);

int main(void)
{
	MoveDisks_2(2,1,3,2);

	return 0;
}

void MoveDisks(int count ,int start, int finish, int temp)
{
	if(count>0)
	{
		MoveDisks(count - 1, start, temp, finish);
		printf("Move Disk %d from %d to %d\n",count ,start ,finish);
		MoveDisks(count - 1, temp, finish, start);
	}
}
void MoveDisks_1(int count ,int start, int finish, int temp)
{
	/*This condition saves us from two useless recursions*/
	if(count == 1)
	{
		printf("Move Disk %d from %d to %d\n",count ,start ,finish);
	}
	else if(count>0)
	{
		MoveDisks(count - 1, start, temp, finish);
		printf("Move Disk %d from %d to %d\n",count ,start ,finish);
		MoveDisks(count - 1, temp, finish, start);
	}
}

void MoveDisks_2(int count ,int start, int finish, int temp)
{
	int swap;
	/*This condition saves us from one useless recursions but not the final one*/
	if(count == 1)
	{
		printf("Move Disk %d from %d to %d\n",count ,start ,finish);
	}
	else
	{
		while(count > 0)
		{
			MoveDisks(count - 1, start, temp, finish);
			printf("Move Disk %d from %d to %d\n",count ,start ,finish);
			count--;
			swap = start;
			start = temp;
			temp = swap;
		}
	}
}
