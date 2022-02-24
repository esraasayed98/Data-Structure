/***************************************************/
/*          Author: Esraa Sayed                    */
/*          Description:StackLinkedBased           */
/*          Date:28 DEC 2021                       */
/*          Version: v01                           */
/***************************************************/

#include<stdio.h>
#include<stdlib.h>

/*Create structure for stack nodes*/
typedef struct stacknode
{
	int Data;
	struct stacknode* Next;

}StackNode;

/*the top pointer is a pointer to StackNode*/
typedef struct stack
{
	int SizeCounter;
	StackNode* Top;


}Stack;


/*****************************************************/
/*                  Function prototypes              */
/*****************************************************/
void Stack_voidInit(Stack* ps);
void Stack_VoidPush(int Copy_intValue, Stack* ps);
void Stack_voidPop(Stack* ps, int* pd);
void Stack_voidReturnTopValue(Stack* ps , int* pd);
int Stack_IntIsFull(Stack* ps);
int Stack_IntIsEmpty(Stack* ps);
void Stack_VoidPrint(Stack* ps);
void Stack_voidSize(Stack* ps , int* size);
void Stack_VoidClear(Stack* ps);

int main()
{
	int TopValue, size;
	Stack s;
	Stack_voidInit(&s);
	Stack_VoidPush( 73, &s);
	Stack_VoidPush(5, &s );
	Stack_VoidPush(2, &s);
	Stack_VoidPush(55, &s);
	Stack_VoidPush(62, &s);
	Stack_VoidPush(245, &s);
	
	printf("*******************************\n");
	printf("Stack elements: \n");
	Stack_VoidPrint(&s);
	printf("*******************************\n");
	Stack_voidSize(&s, &size);
	
	printf("size of stack=  %d\n", size);

	printf("\n------- Poping first element -------\n");

	Stack_voidPop(&s, &TopValue);
	printf("the top value in the stack= %d\n" , TopValue);
	
	printf("\n*******************************\n");

	printf("Stack elements after poping first element: \n");
	Stack_VoidPrint(&s);
	Stack_voidSize(&s, &size);
	printf("size of stack after poping first element =  %d\n", size);
	printf("*******************************\n");
	printf("------- Clearing Stack -------\n");
	Stack_VoidClear(&s);
	
	Stack_voidSize(&s, &size);
	printf("size of stack after clearing all elements=  %d\n", size);

	
	return 0;
}

/* Intialize the stack */
void Stack_voidInit(Stack* ps)
{
	ps->Top = NULL;
	/* intialize the SizeCounter with zero */
	ps->SizeCounter = 0;
}
/* Pushing elements in stack */
void Stack_VoidPush(int Copy_intValue, Stack* ps)
{
	/* 1. create a node */
	/* 1.1. Allocate size of stackNode in memory  */
	/* create a pointer to StackNode */
	StackNode* pn = (StackNode*)malloc(sizeof(StackNode) );
	/* 1.2. Assign Copy_intValue to the data field */
	pn->Data = Copy_intValue;

	/* 1.3. update next pointer to point to what top pointer points to, to follow the chain */
	pn->Next = ps->Top;
	/* update the top pointer to point to the new node */
	ps->Top = pn;

	/*increment the SizeCounter */
	ps->SizeCounter++;
}

void Stack_voidPop(Stack* ps , int* pd)
{
	if (!Stack_IntIsEmpty(ps))
	{
		/* 1- Return data field of the top node */
		/* pd is a pointer to data to acess the variable directly */
		*pd = ps->Top->Data;
		/* 2- Make a Temporary pointer */
		StackNode* pn = ps->Top;
		/* 3- Update Top pointer */
		ps->Top = ps->Top->Next;
		/* 4-Deallocate the old Top node */
		free(pn);
		/* 5- decrement SizeCounter */
		ps->SizeCounter--;
		

	}
	else
	{
		printf("Stack is empty\n");
		
	}
	

}


void Stack_voidReturnTopValue(Stack* ps , int* pd)
{
	if (!Stack_IntIsEmpty(ps))
	{
		/* Return data field of the top node */
		/* pd is a pointer to data to acess the variable directly */
		*pd = ps->Top->Data;
		
	}
	else
	{
		printf("Stack is empty\n");

	}


}

int Stack_IntIsFull(Stack* ps)
{
	return 0;
}
int Stack_IntIsEmpty(Stack* ps)
{
	return (ps->Top == NULL );
}


void Stack_VoidPrint(Stack* ps)
{
	
	StackNode* pn = ps->Top;
	
	while (pn != NULL)
	{
		
		printf("%d\n" , pn->Data);
		pn = pn->Next;
		
	}
	
}
void Stack_voidSize(Stack* ps , int* size)
{
	*size= ps->SizeCounter;
}

void Stack_VoidClear(Stack* ps)
{
	StackNode* pn = ps->Top;
	
	while (pn != NULL)
	{
		
		ps->Top = ps->Top->Next;
		free(pn);
		pn = ps->Top;
	}
	ps->SizeCounter = 0;
	
}


























