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

int is_full(Stacktype *s)
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

int is_empty(Stacktype *s)
{
	if (s->top == - 1)
	{
		printf("Stack is empty!!\n"); 
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(Stacktype *s, int item)
{
	if (is_full(s))
	{
		printf("stack is full!\n");
		exit(1);
	}
	(s->top)++;
	s->data[s->top] = item;


}


element pop(Stacktype *s)
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


int check_matching(const char* in)
{
	Stacktype s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch)
		{
		case'(': case '[': case '{':
			push(&s, ch);
			break;
		case')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else
			{
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
				{
					return 0;
				}
				break;
			}

			
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;

}





int main()
{
	Stacktype *s;
	s = (Stacktype*)malloc(sizeof(Stacktype));
	if (s == NULL)
	{
		printf("NUll");
		exit(1);
	}

	char *p = "({ 2 + 5) }";
	char* p1 = "()";
	char* p2 = ") (";
	char* p3 = "{ 3 + (2 * 5) }";
	char* p4 = "{ }";
	char* p5 = "(3 * 4 + (6)";
		
		if (check_matching(p) == 1)
		{
			printf("%s yes\n", p);
		}
		else
		{
			printf("%s no\n", p);
		}

		if (check_matching(p1) == 1)
		{
			printf("%s yes\n", p1);
		}
		else
		{
			printf("%s no\n", p1);
		}

		if (check_matching(p2) == 1)
		{
			printf("%s yes\n", p2);
		}
		else
		{
			printf("%s no\n", p2);
		}

		if (check_matching(p3) == 1)
		{
			printf("%s yes\n", p3);
		}
		else
		{
			printf("%s no\n", p3);
		}
		if (check_matching(p4) == 1)
		{
			printf("%s yes\n", p4);
		}
		else
		{
			printf("%s no\n", p4);
		}
		if (check_matching(p5) == 1)
		{
			printf("%s yes\n", p5);
		}
		else
		{
			printf("%s no\n", p5);
		}

	

	return 0;
}
