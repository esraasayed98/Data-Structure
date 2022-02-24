/*************************************************/
/*       Author: Esraa Sayed                     */
/*       Description:RverseArrayUsingStack         */
/*       Date:27 DEC 2021                        */
/*       Version: v01                            */
/*************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

//to change stack type easily
//typedef int StackEntry;

typedef  struct stack
{
	char Arr[MAX_SIZE];
	int Top;
	int Size;


}Stack;

/*****************************************************/
/*                  Function prototypes              */
/*****************************************************/
void Stack_voiInit(Stack* ps);
void Stack_VoidPush(char Copy_Value, Stack* ps);
char Stack_charPop(Stack* ps);
char Stack_charReturnTopValue(Stack* ps);
int Stack_IntIsFull(Stack* ps);
int Stack_IntIsEmpty(Stack* ps);
void Stack_VoidPrint(Stack* ps);
int Stack_IntSize(Stack* ps);
void Stack_VoidReverse(char* Arr);

int main()
{
	
	char Arr[5] = "Esraa";
	printf("String before reversing:  ");
	for (int i=0 ; i< sizeof(Arr) ; i++)
	{
		printf("%c" , Arr[i]);
	}
	printf("\nString after reversing:");

	//Reverse String
	 Stack_VoidReverse(Arr);
	
	
	
		
	return 0;
}
void Stack_voiInit(Stack* ps)
{
	ps->Top = -1;
	ps->Size = 0;
}

void Stack_VoidPush(char Copy_Value, Stack* ps)
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
		ps->Arr[ps->Top] = Copy_Value;
		/* increment stack size*/
		ps->Size++;
	}

}
char Stack_charPop(Stack* ps)
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
char Stack_charReturnTopValue(Stack* ps)
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
	return  (ps->Top == MAX_SIZE - 1);
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
		printf("%c\n", ps->Arr[i]);

	}


}
int Stack_IntSize(Stack* ps)
{
	return ps->Size;

}
void Stack_VoidReverse(char* Arr)
{
	Stack ps;
	Stack_voiInit(&ps);
	for (int i = 0; i < sizeof(Arr); i++)
	{
		Stack_VoidPush(Arr[i], &ps);
	}
	//reversing the array
	for (int i = 0; i < sizeof(Arr); i++)
	{
		Arr[i] = Stack_charPop(&ps);
	}
	//print reversed Array
	for (int i = 0; i < sizeof(Arr); i++)
	{
		printf("%c", Arr[i]);
	}

}
















