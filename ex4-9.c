/* Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.*/
#include <stdio.h>
#define BUFSIZE 100

int bufp = 0;
int buf[BUFSIZE]; // BUFSIZE should be defined

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(c == EOF)
		return;
	if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}



/* Okay, let's consider how to handle pushing back the EOF character correctly in your getch and ungetch routines.

Explanation of the Problem:

The standard EOF (End-Of-File) indicator is not a regular character. It's typically defined as a negative integer constant (e.g., -1).

Your current buf array is likely declared as char buf[]. The char data type might be signed or unsigned depending on the system and compiler.

Storing EOF: If char is unsigned, trying to store a negative EOF value directly into buf[0] will result in the negative value being converted to a large positive value (due to integer wrapping). The original EOF value is lost. If char is signed, storing EOF works, but...
Retrieving EOF: When getch retrieves the value from buf[0] (which is a char) using buf[0], this char value is then promoted to an int before being returned. If the char held the bit pattern for EOF but was treated as an unsigned char during promotion, the resulting int will be a large positive number, not the negative EOF value you need to signal end-of-file. If the char was signed and held EOF, the promotion to int should preserve the negative value correctly on most systems, but relying on char signedness can be non-portable. */

/* The most reliable and portable way to handle pushing back EOF (or any other value returned by getchar(), which is specified to return an int) is to change the type of your pushback buffer buf from char to int.

By using int buf[], you guarantee that the buffer can correctly store the full range of values returned by getchar(), including the negative EOF. Then, getch can simply return the int value from the buffer directly, preserving the EOF signal.*/

