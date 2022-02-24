
/*************************************************/
/*       Author: Esraa Sayed                     */
/*       Description:Queue Array Based           */
/*       Date:28 DEC 2021                        */
/*       Version: v01                           */
/*************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

/* create a struct for the queue */
typedef struct queue
{
	int Arr[MAX_SIZE];
	int Front;
	int Rear;
	int size;
}Queue;

/*************************************/
/*     Function Prototypes            */
/*************************************/

void Queue_voidInit(Queue* pq);
void Queue_voidEnQueue(int Value, Queue* pq);
int Queue_IntISFull(Queue* pq );
void Queue_voidDeQueue(Queue* pq , int* data);
int Queue_IntISEmpty(Queue* pq);
int Queue_IntSize(Queue* pq);
void Queue_voidPrint(Queue* pq);


int main()
{
	Queue q;
	Queue_voidInit(&q);
	Queue_voidEnQueue(100,&q);
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
	printf("Size of Queue: %d\n",q.size );
	printf("********************************************************\n");
	int data;
	Queue_voidDeQueue(&q, &data);
	printf("First element in the queue: %d\n" ,data );
	Queue_IntSize(&q);
	printf("Size of Queue after dequeing the first element: %d\n", q.size);

	return 0;
}


void Queue_voidInit(Queue* pq)
{
	pq->Front = -1;
	pq->Rear = -1;
	pq->size = 0;
}


void Queue_voidEnQueue(int Value, Queue* pq)
{
	/*check if the queue is empty*/
	if (Queue_IntISFull(pq))
	{
		printf("Queue is full\n");
	}
	else
	{
		/*corner case: first EnQueue operation */
		if (pq->Front == -1)
		{
			/* front holds the index of the first enqued element */
			pq->Front = 0;

		}
		/*Rear holds the location of the last enqued element */
		pq->Rear++;
		/*assign the value to that location */
		pq->Arr[pq->Rear] = Value;
		/* increment the size  */
		pq->size++;
	}
	


}


int Queue_IntISFull(Queue* pq)
{
	return (pq->Rear == MAX_SIZE - 1);
}

void Queue_voidDeQueue(Queue* pq, int* data)
{
	  /* check if the queue is empty*/
	if (Queue_IntISEmpty(pq))
	{
		printf("queue is empty\n");
	}
	else
	{
			/* return the value of the front node to this pointer to data */
			*data = pq->Arr[pq->Front];
			/*increment the front to point to the next element */
			pq->Front++;
			/*Decrement the size*/
			pq->size--;
			/*corner case:  the last Dequeu operation  */
			if (pq->Front > pq->Rear)
			{
				/* Reset the indexes holders */
				pq->Front = pq->Rear = -1;
			}
	}
}
int Queue_IntISEmpty(Queue* pq)
{
	return (pq->Front == -1);
}

int Queue_IntSize(Queue* pq)
{
	return pq->size;
}
void Queue_voidPrint(Queue* pq)
{
	if (Queue_IntISEmpty(pq))
	{
		printf("queue is empty\n");

	}
	else
	{
		for (int i = pq->Front; i <= pq->Rear; i++)
		{
			printf("%d\n", pq->Arr[i]);
		}

	}
	
}









