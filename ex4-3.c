/* Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100	

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER: push(atof(s));
						 break;

		    case '+'   : push(pop() + pop());
						 break;

			case '-'   : op2 = pop();
						 push(pop() - op2);
						 break;
			case '*'   : push(pop() * pop());
						 break;

			case '/'   : op2 = pop();
						 if(op2 != 0) push(pop() /op2);
						 else printf("zero divison not permitted\n");
						 break;

			case '%'   : op2 =pop();
						 if(op2 != 0) push((int)pop() % (int)op2);
						 else printf("zero divison not permitted\n");
						 break;

			case '\n'  : printf("Result:%.8g\n",pop());
						 break;
			default    :
						 printf("error: unknown command %s\n",s);
						 break;
		}
	}
	return 0;
}

void push(double f)
{
	if(sp >=  MAXVAL) printf("stack limit reached");
	else val[sp++] = f;
}

double  pop(void)
{
	if(sp > 0) return val[--sp];  /*here if sp is 5,then first it reduces sp to 4 then it returns val[4]*/
	else
	{
		printf("stack is empty\n");
		return 0.0;
	}

}

int getop(char s[])
{
	int i, c, n,  sign;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
    s[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '-')
		return c;
    i = 0;
	n = c;

	if(c == '-')
		if(isdigit(c = getch())) /*if next character to - is digit ,then its negative number*/
		{
	        s[++i] = c;
			while(isdigit(s[++i] = c = getch()))
				;
		}
		else
		{
			ungetch(c);
			return n;
		}
    else
		if(isdigit(c))
			while(isdigit(s[++i] = c = getch()))
				;
	if(s[i] == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c!= EOF)
		ungetch(c);
	return NUMBER;
}

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}

