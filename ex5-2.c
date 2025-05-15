/*Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value*/


#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *);

int main() {
    float x;
    printf("Enter a float: ");
    if (getfloat(&x))
        printf("You entered: %f\n", x);
    else
        printf("Not a valid float.\n");
    return 0;
}



/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
	int c, next_c, sign;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c!= '.') {
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

	
	if(isdigit(c))
	{
		for (*pn = 0; isdigit(c); c = getch())
            *pn = 10 * *pn + (c - '0');
		
		if(c=='.')
		{
			c = getch();
			if(!isdigit(c))
			{
				if(c != EOF) ungetch(c);
		        *pn = sign * (*pn);
				return 0;
			}
		}
	}

	else if(c =='.') //Handle case when input starts with .
    {
        c = getch();
        if(!isdigit(c))
        {
            if(c!=EOF) ungetch(c);
            if (sign) ungetch((sign == -1)?'-':'+');
            ungetch('.');
            return 0; //Not a valid number(just a standalone '.')
        }
		else *pn = 0;

    }


	float exp = 1;
	for( ;isdigit(c);c = getch())
	{
		*pn = 10 * *pn + (c - '0');
		exp = exp * 10;
	}

	*pn = sign * (*pn / exp);
	
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
