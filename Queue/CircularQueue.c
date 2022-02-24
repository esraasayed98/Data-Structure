/*************************************************/
/*       Author: Esraa Sayed                     */
/*       Description:Circular Queue          */
/*       Date:28 DEC 2021                        */
/*       Version: v01                           */
/*************************************************/

#include<stdio.h>
#include<stdlib.h>



#define MAX_SIZE 5

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
int Queue_IntISFull(Queue* pq);
void Queue_voidDeQueue(Queue* pq, int* data);
int Queue_IntISEmpty(Queue* pq);
int Queue_IntSize(Queue* pq);
void Queue_voidPrint(Queue* pq);






int main()
{
    Queue q;
    Queue_voidInit(&q);
    Queue_voidEnQueue(1, &q);
    Queue_voidEnQueue(2, &q);
    Queue_voidEnQueue(3, &q);
    Queue_voidEnQueue(4, &q);
    Queue_voidEnQueue(5, &q);
    
    

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
    printf("Queue elements after dequing the first element:\n");
    Queue_voidPrint(&q);

    Queue_voidEnQueue(6, &q);
    printf("********************************************************\n");
    printf("Queue elements after enquing new element:\n");
    Queue_voidPrint(&q);

    printf("********************************************************\n");
    printf("trying to add new element after the queue is full:\n");

    Queue_voidEnQueue(7, &q);// Fails to enqueue because front == 0 && rear == SIZE - 1
    


    

    return 0;
}

void Queue_voidInit(Queue* pq)
{
    pq->Front = -1;
    pq->Rear = -1;
    pq->size = 0;
}



int Queue_IntISFull(Queue* pq)
{
    return  ( pq->Front == pq->Rear+1 ||  (  pq->Front == 0 && pq->Rear == MAX_SIZE - 1 ));
}

int Queue_IntISEmpty(Queue* pq)
{
    return (pq->Front == -1);
}



int Queue_IntSize(Queue* pq)
{
    return pq->size;
}


void Queue_voidEnQueue(int Value, Queue* pq)
{
    
    /*check if the queue is empty*/
    if (Queue_IntISFull(pq))
    {
        printf("Queue is full, you can't add another element.\n");
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
        pq->Rear = (pq->Rear +1)%MAX_SIZE ;
        /*assign the value to that location */
        pq->Arr[pq->Rear] = Value;
        /* increment the size  */
        pq->size++;
    }



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
        /*corner case:  the last Dequeu operation  */
        if (pq->Front > pq->Rear)
        {
            /* Reset the indexes holders */
            pq->Front = pq->Rear = -1;
        }
        else
        {
            pq->Front = (pq->Front+1) % MAX_SIZE;
            /*Decrement the size*/
            pq->size--;
        }
        
    }
}


void Queue_voidPrint(Queue* pq)
{
    
    if (Queue_IntISEmpty(pq))
    {
        printf("queue is empty\n");

    }
    else
    {
        int i=0;
        for (i = pq->Front; i != pq->Rear; i=(i+1)%MAX_SIZE)
        {
            printf("%d\n", pq->Arr[i]);
        }
        printf("%d\n", pq->Arr[i]);
        
    }

}


