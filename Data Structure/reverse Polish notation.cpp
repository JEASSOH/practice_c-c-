#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100


typedef float element;
typedef	struct stacktype
{
	float data[MAX_STACK_SIZE];
	int top;
}Stacktype;

void init_stack(Stacktype* s)
{
	s->top = -1;
	return;
}

int is_full(Stacktype* s)
{
	if (s->top == MAX_STACK_SIZE - 1)
	{
		printf("Stack is full!!\n");
		return 1;
	}
	else
	{
		return 0;
	}

}

int is_empty(Stacktype* s)
{
	if (s->top == -1)
	{
		printf("Stack is empty!!\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(Stacktype* s, float item)
{
	if (is_full(s))
	{
		printf("stack is full!\n");
		exit(1);
	}
	(s->top)++;
	s->data[s->top] = item;


}


element pop(Stacktype* s)
{
	element temp;

	if (is_empty(s))
	{
		printf("stack is empty\n");
		exit(1);
	}
	else 
	{
		temp = (float)(s->data[s->top]);
		(s->top)--;
		return temp;
	}
}


float eval(char exp[])
{
	double op1, op2,result = 0;
	int value = 0;
	int i = 0;
	int len = strlen(exp);
	char ch;

	Stacktype s;

	init_stack(&s);

	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0';
			push(&s, value);


		}
		
		else 
		{

			op2 = pop(&s);
			op1 = pop(&s);

			switch (ch) {
			case '+':push(&s, op1 + op2); break;
			case '-':push(&s, op1 - op2); break;
			case '*':push(&s, op1 * op2); break;
			case '/':
			if (op1 == 0 || op2 == 0)
				{	
					printf("나눗셈에 0은 사용이 불가합니다");
					break;
				}
			else
			push(&s, op1 / op2); break;
				
			}

		}
	}
	result = pop(&s);
	return result;

}



int main()
{
	Stacktype* s;
	float result = 0;
	float result1 = 0;
	float result2 = 0;
	s = (Stacktype*)malloc(sizeof(Stacktype));
	if (s == NULL)
	{
		printf("NUll");
		exit(1);
	}
	char Str1[100] = { 0 };
	char Str2[100] = { 0 };
	char Str3[100] = { 0 };
	gets_s(Str1);
	gets_s(Str2);
	gets_s(Str3);
	result = eval(Str1);
	result1 = eval(Str2);
	result2 = eval(Str3);
	printf("결과값은 : %.2f\n", result);
	printf("결과값은 : %.2f\n", result1);
	printf("결과값은 : %.2f\n", result2);


}