/* Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void push(double);
double pop(void);

#define MAXLINE 1000
#define MAX_STACK_SIZE 100


double stack[MAX_STACK_SIZE];
int sp = 0;  /*stack pointer*/

int main(int argc, char *argv[])
{
	int i, op2;
	double num;
	char *p, c, t;
	int ar = argc;

	for(i = 1; i < argc; i++)
	{
		p = argv[i];
		c = p[0];
		printf("argc = %d, c = %c\n",ar,c);
		if (isdigit(c))
		{
			num = atof(p);
			push(num);
		}
		else if (c == '.')
		{
			if (isdigit(t = p[1]))
			{
				num = atof(p);
				push(num);
			}

		}
		else if (c == '-')
		{
			if (isdigit(t = p[1]))
			{
				num = atof(p);
				push(num);
			}
			else
			{
				push(pop() - pop());
			}

		}
		else if (c == '+')
		{
			push(pop() + pop());
		}
		else if (c == '*')
		{
			printf("i came here\n");
			push(pop() * pop());
		}
		else if (c == '/')
		{
			op2 = pop();
			if (op2)
			{
				push(pop() / op2);
			}

		}

	}
	printf("result: %g", pop());

	return 0;
}

void push(double value)
{
	if (sp < MAX_STACK_SIZE)
	{
		stack[sp++] = value;
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return stack[--sp];
	}
}
