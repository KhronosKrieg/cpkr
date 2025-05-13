/*As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.*/


#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, next_c, sign;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
		}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		next_c = getch();
		if(!isdigit(next_c))
		{
			ungetch(c);
			ungetch(next_c);
			return 0;
		}
		c = next_c;
	}
	
	for (*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	
	
	if (c != EOF)
	ungetch(c);
	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
