#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef	struct stacktype
{
	int data[MAX_STACK_SIZE];
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

void push(Stacktype* s, int item)
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
	else {
		temp = s->data[s->top];
		(s->top)--;
		return temp;
	}
}


int check_matching(char in[])
{
	Stacktype s;
	char ch, open_ch;
	int i, n = strlen(in);

	init_stack(&s);

	for (int i = 0; i < n; i++) {

		if (in[i] >= 'A' && in[i] <= 'Z') {
			in[i] += 32;
			push(&s, in[i]);
		}
		else if (in[i] >= 'a' && in[i] <= 'z')
		{
			push(&s, in[i]);
		}
		
	}
	for (int i = 0; i < n; i++) {
		if (in[i] >= 'A' && in[i] <= 'Z' || in[i] >= 'a' && in[i] <= 'z') {
			if (in[i] != pop(&s))
			return 0;
		}
		
	}
	return 1;

}







int main()
{
	Stacktype* s;
	s = (Stacktype*)malloc(sizeof(Stacktype));
	if (s == NULL)
	{
		printf("NUll");
		exit(1);
	}
	char Str[100] = { 0 };
	gets_s(Str);
	if (check_matching(Str) == 1)
	{
		printf("%s yes\n", Str);
	}
	else
	{
		printf("%s no\n", Str);
	}

	return 0;
}
