/*************************************************/
/*       Author: Esraa Sayed                     */
/*       Description:CheckBranthesisUsingStack     */
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
void Stack_VoidPush(int Copy_intValue, Stack* ps);
char Stack_charPop(Stack* ps);
char Stack_charReturnTopValue(Stack* ps);
int Stack_IntIsFull(Stack* ps);
int Stack_IntIsEmpty(Stack* ps);
void Stack_VoidPrint(Stack* ps);
int Stack_IntSize(Stack* ps);
int Check_Balacnced_Brackets(char* Str);

int main()
{
	char Str[50] = "{()}([])";//Balanced
	//char Str[50] = "{({)}([}])"; //not Balanced
	//char Str[50] = ")("; //not balanced
	//char Str[50]="{([()])}{[([[({})]])]}";//balanced
	
	printf("string: %s has " , Str);
	if (Check_Balacnced_Brackets(Str))
	{
		printf("Balanced Brackets");
	}
	else
	{
		printf("Not Balanced Brackets");
	}

	return 0;
}
void Stack_voiInit(Stack* ps)
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
		//printf("Stack is empty");
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

int Check_Balacnced_Brackets(char* Str)
{
	char matched_bracket;
	//create opening bracket stack
	Stack s;
	int opening_index= 0;
	int closing_index= 0;
	

	//intialize the stack
	Stack_voiInit(&s);

	//traverse the string to push opening bracket
	for (int i = 0; i < sizeof(Str); i++)
	{
		//push the opening bracket to the stack
		if (Str[i] == '(' || Str[i] == '{' || Str[i] == '[')
		{
			opening_index = i;
			Stack_VoidPush(Str[i], &s);
		}
		//pop the opening bracket from the stack when finding a closing bracket
		if (Str[i] == ')' || Str[i] == '}' || Str[i] == ']')
		{
			//check for matching pairs
			
			if (Stack_charReturnTopValue(&s) == '(' && Str[i] == ')')
			{
				closing_index = i;
				//check for brackets indexes
				if (closing_index > opening_index)
				{
					matched_bracket = Stack_charPop(&s);

				}
				
			}
			else if (Stack_charReturnTopValue(&s) == '[' && Str[i] == ']')
			{
				closing_index = i;
				//check for brackets indexes
				if (closing_index > opening_index)
				{
					matched_bracket = Stack_charPop(&s);

				}
			}
			else if (Stack_charReturnTopValue(&s) == '{' && Str[i] =='}')
			{
				closing_index = i;
				//check for brackets indexes
				if (closing_index > opening_index)
				{
					matched_bracket = Stack_charPop(&s);

				}
			}

			
			
		}


	}
	
	//empty string is balanced
	if (Stack_IntIsEmpty(&s))
	{
		return 1; 
	}
	else
	{
		return 0;
	}
	
}















