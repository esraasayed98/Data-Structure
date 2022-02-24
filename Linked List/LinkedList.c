/*************************************************/
/*       Author: Esraa Sayed                     */
/*       Description:Linked List                  */
/*       Date:30 DEC 2021                        */
/*       Version: v01                           */
/*************************************************/



#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
    int Data;
    struct listnode* Next;
}ListNode;

typedef struct list
{
    int size;
    ListNode* head;
}List;

/**************************************************/
/***************Functions Prototypes***************/
/**************************************************/
void List_voidInit(List* pl);
void List_voidInsertList(int Position, List* pl, int Value);
void List_voidReplaceList(int Position, List* pl, int Value);
void List_voidDeleteList(int Position, List* pl, int* pd);
void List_voidRetriveList(int Position, List* pl, int* pd);
int  List_intIsEmpty(List* pl);
int  List_intIsFull(List* pl);
int  List_intSize(List* pl);
void List_voidPrint(List* pl);
void List_voidDestroyList(List* pl);

int main()
{
    int size, RetrivedValue;
    List L;

    List_voidInit(&L);

    List_voidInsertList(0, &L, 100);
    List_voidInsertList(1, &L, 200);
    List_voidInsertList(2, &L, 300);
    List_voidInsertList(3, &L, 400);
    List_voidInsertList(4, &L, 500);
    List_voidInsertList(5, &L, 600);
    List_voidInsertList(6, &L, 700);
    List_voidInsertList(7, &L, 800);
    List_voidInsertList(8, &L, 900);
    List_voidInsertList(9, &L, 1000);
    
    

    printf("\n********************************************************\n");
    printf("List of elements:\n");
    List_voidPrint(&L);

   
    printf("\n********************************************************\n");
    List_intSize(&L);
    printf("Size of List is: %d\n", L.size);
    
    printf("\n********************************************************\n");

    List_voidRetriveList(2, &L, &RetrivedValue);
    printf("\nThe RetrivedValue of element at position 2 is  %d\n", RetrivedValue);
    
    printf("\n********************************************************\n");

    List_voidDeleteList(1, &L, &RetrivedValue);
    printf("Delete element at position 1 which is  %d\n", RetrivedValue);

    List_voidDeleteList(5, &L, &RetrivedValue);
    printf("Delete element at position 5 which is  %d\n", RetrivedValue);

   
    printf("\n********************************************************\n");
    printf("The rest of elements  in the list after deleting some elements:\n");
    List_voidPrint(&L);

    printf("\n********************************************************\n");
    List_intSize(&L);
    printf("Size of List after deleting some elements is %d\n", L.size);

}

void List_voidInit(List* pl)
{
    pl->head = NULL;
    pl->size = 0;
}

int  List_intIsEmpty(List* pl)
{
    return (pl->head == NULL);
}

int  List_intIsFull(List* pl)
{
    return 0;
}

int  List_intSize(List* pl)
{
    return (pl->size);
}


void List_voidInsertList(int Position, List* pl, int Value)
{

    ListNode* q;
    int i;

    ListNode* pn = (ListNode*)malloc(sizeof(ListNode));
    pn->Data = Value;
    pn->Next = NULL;

    /* insert at first position*/
    if (Position == 0)
    {
        pn->Next = pl->head;
        pl->head = pn;
    }
    else
    {
        for (q = pl->head, i = 0; i < Position - 1; i++)
        {
            q = q->Next;
        }
        pn->Next = q->Next;
        q->Next = pn;
    }

    pl->size++;
}

void List_voidReplaceList(int Position, List* pl, int Value)
{
    int i;
    ListNode* q;
    for (q = pl->head, i = 0; i < Position; i++)
    {
        q = q->Next;
    }
    q->Data = Value;
}

void List_voidDeleteList(int Position, List* pl, int* pd)
{
    int i;
    ListNode* q, * tmp;

    if (Position == 0)
    {
        *pd = pl->head->Data;
        tmp = pl->head->Next;
        free(pl->head);
        pl->head = tmp;
    }
    else
    {
        for (q = pl->head, i = 0; i < Position - 1; i++)
        {
            q = q->Next;
        }
        *pd = q->Next->Data;
        tmp = q->Next->Next;
        free(q->Next);
        q->Next = tmp;
    }
    pl->size--;
}

void List_voidRetriveList(int Position, List* pl, int* pd)
{
    int i;
    ListNode* q;

    for (q = pl->head, i = 0; i < Position; i++)
    {
        q = q->Next;
    }
    *pd = q->Data;
}

void List_voidPrint(List* pl)
{
    ListNode* q = pl->head;

    while (q != NULL)
    {
        printf("%d\t", q->Data);
        q = q->Next;
    }
}

void List_voidDestroyList(List* pl)
{
    ListNode* tmp;

    while (pl->head != NULL)
    {
        tmp = pl->head->Next;
        free(pl->head);
        pl->head = tmp;
    }

    pl->size = 0;
}


