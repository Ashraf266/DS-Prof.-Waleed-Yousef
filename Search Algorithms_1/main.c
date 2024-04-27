#include <stdio.h>
#include <string.h>


typedef int KeyType;

#define KEY_IS_STRING	(0)

#if KEY_IS_STRING

#define EQ(X,Y) ((strcmp(X,Y) == 0))
#define GT(X,Y) ((strcmp(X,Y) > 0))
#define GE(X,Y) ((strcmp(X,Y) >= 0))
#define LT(X,Y) ((strcmp(X,Y) < 0))
#define LE(X,Y) ((strcmp(X,Y) <= 0))



#else

#define EQ(X,Y) ((X) == (Y))
#define GT(X,Y) ((X) > (Y))
#define GE(X,Y) ((X) >= (Y))
#define LT(X,Y) ((X) < (Y))
#define LE(X,Y) ((X) <= (Y))


#endif


typedef struct elementtype{
	KeyType key;
	int year;
	int etype;

	union{
		int year;
		float age;
	}info;

}ElementType;

typedef ElementType* List;

int SequentialSearch(KeyType target, List list, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(EQ(target, list[i].key))
			return i;
	}
	return -1;

}

int binarySearch(int target, int *arr, int size)
{
	int bottom = 0;
	int top = size-1;
	int middle;

	while(bottom <= top)
	{
		middle = (bottom + top) / 2;

		if(EQ(target,arr[middle]))
		{
			return middle;
		}
		else if(LT(target,arr[middle]))
		{
			top = middle-1;
		}
		else
		{
			bottom = middle+1;
		}
	}
	return -1;
}


int recBinary(int target, int *arr, int bottom, int top)
{
	int middle;

	if(bottom <= top)
	{
		middle = (bottom + top) / 2;

		if(EQ(target,arr[middle]))
		{
			return middle;
		}
		else if(LT(target,arr[middle]))
		{
			return recBinary(target, arr, bottom, middle-1);
		}
		else
		{
			return recBinary(target, arr, middle+1, top);
		}
	}
	return -1;
}

int recBinarySearch(int target, int *arr, int size)
{
	return recBinary(target, arr, 0, size-1);
}




int main(void)
{
	ElementType arr[5] = {{3},{4},{8},{2},{9}};
	int index = SequentialSearch(20, arr, 5);
	printf("%d\n",index);

	int array[10] = {1,3,4,6,7,9,11,13,15,20};
	int res = binarySearch(20, array, 10);
	printf("%d\n",res);

	res = recBinarySearch(5, array, 10);
	printf("%d\n",res);




	return 0;
}
