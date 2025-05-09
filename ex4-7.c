/* Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch */

#include <stdio.h>
#include <string.h>

void ungets(char []);

void ungets(s)
{
	int i;

	for(i = strlen(s)-1; i>=0;i--)
	{
		ungetch(s[i]);
	}

}


int bufp = 0;
char buf[BUFSIZE]; // BUFSIZE should be defined

int getch(void)
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
