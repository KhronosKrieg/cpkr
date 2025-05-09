/* Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly */

#include <stdio.h>
#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE]; // BUFSIZE should be defined

int getch(void)
{
    return (bufp >  0) ? (bufp = 0, buf[0]) : getchar();
}

void ungetch(int c)
{
    if (bufp >= 1)
        printf("ungetch: too many characters\n");
    else
        buf[0] =c;
	    bufp = 1;
}
                 
