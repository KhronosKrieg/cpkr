/*Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable..*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100	
#define SIN 101
#define COS 102
#define POW 103
#define VAR_REF 104 //To indicate a variable name token
#define M_PI 3.14159265358979323846
#define VARNUM 26
#define ASSIGN_OP 106
#define LAST_RESULT_CMD 105
#define UNKNOWN_CMD 107

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void swap(void);
void print_top(void);
void clear_stack(void);
void duplicate_top(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
double variables[VARNUM];
double last_result = 0.0;
double value_to_assign = 0.0;

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER: push(atof(s));
			break;

		case '+': push(pop() + pop());
			break;

		case '-': op2 = pop();
			push(pop() - op2);
			break;
		case '*': push(pop() * pop());
			break;

		case '/': op2 = pop();
			if (op2 != 0) push(pop() / op2);
			else printf("zero divison not permitted\n");
			break;

		case '%': op2 = pop();
			if (op2 != 0) push((int)pop() % (int)op2);
			else printf("zero divison not permitted\n");
			break;

		case SIN: push(sin(pop() * M_PI / 180.0));
			break;

		case COS: push(cos(pop() * M_PI / 180.0));
			break;

		case POW:push(pow(pop(), pop()));
			break;

		case '\n':
			if (sp > 0)
			{
				last_result = pop();
				printf("Result:%.8g\n", last_result);
			}
			else printf("Nothing to show\n");
			break;

		case 'c': clear_stack();
			break;

		case 's': swap();
			break;

		case 'p': print_top();
			break;

		case 'd': duplicate_top();
			break;

		case VAR_REF: if (s[0] >= 'A' && s[0] <= 'Z')
		{
			push(variables[s[0] - 'A']);
		}
					else
		{
			printf("error: invalid variable reference token\n");
		}
					break;

		case ASSIGN_OP: if (sp < 1) printf("error: assignment requires value on stack\n");
					  else
		{
			value_to_assign = pop();
			int next_token_type = getop(s);
			if (next_token_type == VAR_REF)
			{
				char var_char = s[0];
				int var_index = var_char - 'A';
				if (var_index >= 0 && var_index < VARNUM)
				{
					variables[var_index] = value_to_assign;
				}
				else
				{
					printf("error: invalid variable name after '%c' \n", ASSIGN_OP);
				}
			}
			else
			{
				printf("error: expected variable name after assignment operator");
				if (type >= 0 && type != EOF && type != '\n')
				{
					//ungetch(type);
				}
			}
		}
					  break;
		case LAST_RESULT_CMD: push(last_result);
			break;

		default: printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void push(double f)
{
	if (sp >= MAXVAL) printf("stack limit reached");
	else val[sp++] = f;
}

double  pop(void)
{
	if (sp > 0) return val[--sp];  /*here if sp is 5,then first it reduces sp to 4 then it returns val[4]*/
	else
	{
		printf("stack is empty\n");
		return 0.0;
	}
}

void swap(void)
{
	double a;
	int temp = sp;

	if (sp < 2) printf("not enough values to swap");
	else
	{
		a = val[temp - 1];
		val[temp - 1] = val[temp - 2];
		val[temp - 2] = a;

	}
}

void print_top(void)
{
	int n = sp;
	if (n == 0)
	{
		printf("stack empty\n");
		return;
	}
	printf("value of n: %d\n", n);
	while (n > 0)
	{
		printf("\t%.8g\n", val[--n]);
	}

}

void clear_stack(void)
{

	if (sp == 0)
	{
		printf("stack already empty\n");
		return;
	}
	else
		while (sp > 0) pop();

}

void duplicate_top(void)
{
	int n = sp - 1;
	if (sp == 0) printf("stack empty, cannot duplicate\n");
	else
	{
		push(val[n]);
	}
}


int getop(char s[])
{
	int i, c, n;
	static int p = 0;

	if (p)
	{
		s[0] = c = p;
		p = 0;
	}
	else c = s[0] = getch();
	while (c == ' ' || c == '\t')
		s[0] = c = getch();

	s[1] = '\0';

	i = 0;
	if (c == '>') return ASSIGN_OP;
	if (c == '_') return LAST_RESULT_CMD;
	if (c == '\n') return '\n';

	if (isalpha(c))
	{
		while (isalpha(c))
		{
			s[i++] = c;
			c = getch();
		}
		s[i] = '\0';
		p = c;
		if (strcmp(s, "sin") == 0 || strcmp(s, "SIN") == 0) return SIN;
		else if (strcmp(s, "cos") == 0 || strcmp(s, "COS") == 0) return COS;
		else if (strcmp(s, "pow") == 0 || strcmp(s, "POW") == 0) return POW;
		else if (i == 1 && s[0] >= 'A' && s[0] <= 'Z') return VAR_REF;
		else if (i == 1) return s[0];
		else return UNKNOWN_CMD;

	}

	if (!isdigit(c) && c != '.' && c != '-')
		return c; //to handle +, /, %
	n = c;
	if (c == '-')
		if (isdigit(c = getch())) /*if next character to - is digit ,then its negative number*/
		{
			s[++i] = c;
			while (isdigit(s[++i] = c = getch()))
				;
		}
		else
		{
			p = c;
			return n;
		}
	else
		if (isdigit(c))
			while (isdigit(s[++i] = c = getch()))
				;
	if (s[i] == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		p = c;
	return NUMBER;
}

int getch()
{
	return getchar();
}

