/*************************************************/
/*       Author: Esraa Sayed                     */
/*       Description:StackArrayBased             */
/*       Date:26 DEC 2021                        */
/*       Version: v01                           */
/*************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

//to change stack type easily
//typedef int StackEntry;

typedef  struct stack
{
	int Arr[MAX_SIZE];
	int Top;
	int Size;


}Stack;

/*****************************************************/
/*                  Function prototypes              */
/*****************************************************/
void Stack_voidInit(Stack* ps);
void Stack_VoidPush(int Copy_intValue , Stack* ps);
int Stack_intPop(Stack* ps); 
int Stack_IntReturnTopValue(Stack* ps);
int Stack_IntIsFull(Stack* ps);
int Stack_IntIsEmpty(Stack* ps);
void Stack_VoidPrint(Stack* ps);
int Stack_IntSize(Stack* ps);

int main()
{
	/* create object from stack*/
	Stack s;
	/* initialize stack */
	Stack_voidInit(&s);
	Stack_VoidPush(13,&s);
	Stack_VoidPush(2, &s);
	Stack_VoidPush(5, &s);
	Stack_VoidPush(25, &s);
	
	printf("\n***********************\n");
	Stack_VoidPrint(&s);
	
	printf("\n***********************\n");
	int size=Stack_IntSize(&s);
	printf("size of stack: %d\n" , size);
	
	printf("\n***********************\n");
	int TopValue = Stack_intPop(&s);
	printf("top element=  %d\n", TopValue);
	
	printf("\n***********************\n");
	size = Stack_IntSize(&s);
	printf("size of stack after poping an element= %d\n ", size);

	return 0;
}
void Stack_voidInit(Stack* ps)
{
	ps->Top = -1;
	ps->Size = 0;
}

void Stack_VoidPush(int Copy_intValue, Stack* ps)
{
	/*check stack is not full */
	if (Stack_IntIsFull(ps))
	{
		printf("Stack is full , you can't push\n");

	}
	else
	{
		/* 1-increment Top */
		ps->Top++;
		/* 2-Assign the value to Arr[Top] */
		ps->Arr[ps->Top] = Copy_intValue;
		/* increment stack size*/
		ps->Size++;
	}

}
int Stack_intPop(Stack* ps)
{
	/* check if stack is not empty */
	if (!Stack_IntIsEmpty(ps))
	{
		int TopValue;
		/* 1-Assign Top value to a temp variable */
		TopValue = ps->Arr[ps->Top];
		/* 2-Decrement Top indicator  */
		ps->Top--;
		/* Decrement stack size*/
		ps->Size--;
		/*return temp variable */
		return TopValue;

	}
	else
	{
		printf("Stack is empty");
		return 0;
	}

}
int Stack_IntReturnTopValue(Stack* ps)
{

	if (!Stack_IntIsEmpty(ps))
	{
		
		return ps->Arr[ps->Top];
	}
	else
	{
		printf("Stack is empty");
		return 0;
	}


}
int Stack_IntIsFull(Stack* ps)
{
	return  (ps->Top ==MAX_SIZE-1);
}

int Stack_IntIsEmpty(Stack* ps)
{
	return (ps->Top == -1);
}

void Stack_VoidPrint(Stack* ps)
{
	printf("Stack elements: \n");
	int i = ps->Top;
	for (i; i != -1; i--)
	{
		printf("%d\n", ps->Arr[i]);

	}


}
int Stack_IntSize(Stack* ps)
{
	return ps->Size;

}

















