/******************************************************************************
 *
 * Module: Queue_linkedBased
 *
 * File Name: queue.h
 *
 * Description: Header file for the Queue Module
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Queue element type user can define it */
/* not a proper solution if the user want to make many Queues with different elements but leave it for now */
typedef int QueueEntry;

/* Queue linked list Node */
typedef struct queuenode
{
	QueueEntry entry;
	struct queuenode * next;
}QueueNode;

/* Queue structure*/
typedef struct queue
{
	int size;
	QueueNode * front;
	QueueNode * rear;
}Queue;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void InitializeQueue(Queue * pq);

void Append(QueueEntry e,Queue *pq);

void Serve(QueueEntry *pe,Queue *pq);

void Retrieve(QueueEntry *pe,Queue *pq);

int QueueIsEmpty(Queue *pq);

int QueueIsFull(Queue *pq);

void TraverseQueue(Queue *pq,void (*pf)(QueueEntry));

void ClearQueue(Queue *pq);



#endif /* QUEUE_H_ */
