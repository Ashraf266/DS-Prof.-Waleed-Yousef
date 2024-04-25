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
#include "queue.h"


void InitializeQueue(Queue * pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

void Append(QueueEntry e,Queue *pq)
{
	pq->rear = (pq->rear + 1) % MAXQUEUE;
	pq->entry[pq->rear] = e;
	pq->size++;
}

void Serve(QueueEntry *pe,Queue *pq)
{
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1) % MAXQUEUE;
	pq->size--;
}

void Retrieve(QueueEntry *pe,Queue *pq)
{
	*pe = pq->entry[pq->front];
}

int QueueIsEmpty(Queue *pq)
{
	return !pq->size;
}

int QueueIsFull(Queue *pq)
{
	return pq->size == MAXQUEUE;
}

void TraverseQueue(Queue *pq,void (*pf)(QueueEntry))
{
	int i,s;

	for(i = pq->front , s= 0;s<pq->size;s++,++i%MAXQUEUE)
	{
		(*pf)(pq->entry[i]);
	}
}

void ClearQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

