
/*************************************************/
/*       Author: Esraa Sayed                     */
/*       Description:Queue Linked Based           */
/*       Date:28 DEC 2021                        */
/*       Version: v01                           */
/*************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Queuenode
{
	int Data;
	struct Queuenode* Next;
}QueueNode;

typedef struct queue
{
	int size;
	QueueNode* Front;
	QueueNode* Rear;

}Queue;

/*************************************/
/*     Function Prototypes            */
/*************************************/

void Queue_voidInit(Queue* pq);
void Queue_voidEnQueue(int Value, Queue* pq);
int Queue_IntISFull(Queue* pq);
void Queue_voidDeQueue(Queue* pq, int* data);
void Queue_voidpeek(Queue* pq, int* data);
int Queue_IntISEmpty(Queue* pq);
int Queue_IntSize(Queue* pq);
void Queue_voidPrint(Queue* pq);
void Queue_voidClear(Queue* pq);





int main()
{
	Queue q;
	Queue_voidInit(&q);
	Queue_voidEnQueue(100, &q);
	Queue_voidEnQueue(50, &q);
	Queue_voidEnQueue(30, &q);
	Queue_voidEnQueue(200, &q);
	Queue_voidEnQueue(150, &q);
	Queue_voidEnQueue(75, &q);
	
	printf("********************************************************\n");
	printf("Queue elements:\n");
	Queue_voidPrint(&q);
	
	printf("********************************************************\n");
	Queue_IntSize(&q);
	printf("Size of Queue: %d\n", q.size);
	
	printf("********************************************************\n");
	int data;
	Queue_voidDeQueue(&q, &data);
	printf("First element in the queue: %d\n", data);
	Queue_IntSize(&q);
	printf("Size of Queue after dequeing the first element: %d\n", q.size);
	
	printf("********************************************************\n");
	Queue_voidClear(&q);
	Queue_IntSize(&q);
	printf("Size of Queue after clearing the queue: %d\n", q.size);


	return 0;
}




void Queue_voidInit(Queue* pq)
{
	pq->Front = NULL;
	pq->Rear = NULL;
	pq->size = 0;
}

void Queue_voidEnQueue(int Value, Queue* pq)
{
	/*Allocate a new node in memory*/
	QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->Data = Value;
	pn->Next = NULL;

	if (pq->Front == NULL)
	{
		pq->Front = pn;
	}
	else
	{
		pq->Rear->Next = pn;

	}

	pq->Rear = pn;
	pq->size++; 
	
}

int Queue_IntISFull(Queue* pq)
{
	return 0;
}

void Queue_voidDeQueue(Queue* pq, int* data)
{
	if (Queue_IntISEmpty(pq))
	{
		printf("Queue is empty\n");
	}
	else
	{
		QueueNode* pn = pq->Front;
		/* return data field of the current front */
		*data = pn->Data;
		/*update the front of the queue*/
		pq->Front = pn->Next;
		/*Deallocate the old frontNode*/
		free(pn);

		if (pq->Front == NULL)
		{
			pq->Rear = NULL;
		}
		pq->size--;
	}
	
	
}
void Queue_voidpeek(Queue* pq, int* data)
{
	if (Queue_IntISEmpty(pq))
	{
		printf("Queue is empty\n");
	}
	else
	{
		QueueNode* pn = pq->Front;
		/* return data field of the current front */
		*data = pn->Data;
	}

}


int Queue_IntISEmpty(Queue* pq)
{
	return (pq->Front == NULL);
}
int Queue_IntSize(Queue* pq)
{
	return pq->size;
}
void Queue_voidPrint(Queue* pq)
{
	QueueNode* pn = pq->Front;
	while (pn != NULL)
	{
		printf("%d\n", pn->Data);
		pn = pn->Next;
	}
}

void Queue_voidClear(Queue* pq) {
	QueueNode* frontNode;
	while (pq->Front != NULL)
	{
		frontNode = pq->Front;
		pq->Front = pq->Front->Next;
		free(frontNode);
	}
	pq->size = 0;
}











