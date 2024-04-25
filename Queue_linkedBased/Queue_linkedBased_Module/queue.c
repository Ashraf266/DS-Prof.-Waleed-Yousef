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
#include <stdlib.h>


void InitializeQueue(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

void Append(QueueEntry e,Queue *pq)
{
	QueueNode * pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->entry = e;
	pn->next = NULL;
	/* if there's no nodes make the front point to the first node, if there's don't forget to make the last node point to the added node */
	if(!pq->rear)
		pq->front = pn;
	else
		pq->rear->next = pn;
	pq->rear = pn;
	pq->size++;
}

void Serve(QueueEntry *pe,Queue *pq)
{
	QueueNode * pn = pq->front;
	*pe = pn->entry;
	pq->front = pn->next;
	free(pn);
	if(!pq->front)
		pq->rear = NULL;
	pq->size--;
}

void Retrieve(QueueEntry *pe,Queue *pq)
{
	QueueNode * pn = pq->front;
	*pe = pn->entry;
	pq->front = pn->next;
	if(!pq->front)
		pq->rear = NULL;
	pq->size--;
}

int QueueIsEmpty(Queue *pq)
{
	return !pq->size;
}

int QueueIsFull(Queue *pq)
{
	return 0;
}

void TraverseQueue(Queue *pq,void (*pf)(QueueEntry))
{
	QueueNode * pn;
	for(pn=pq->front;pn;pn = pn->next)
	{
		(*pf)(pn->entry);
	}
}

void ClearQueue(Queue *pq)
{
	while(pq->front)
	{
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->size = 0;
}

