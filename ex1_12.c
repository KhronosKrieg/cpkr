/* Write a program that prints its input one word per line.*/

#include <stdio.h>

#define IN 1
#define OUT 0
int main()
{
	int n,state = OUT;

    while((n=getchar())!=EOF)
	{
		if((n==' ') || (n == '\t') ||(n == '\n'))
		{
		     
				 putchar('\n');
				 state = OUT;
			
		}
		else if(state == OUT)
		{
			state = IN;
			putchar(n);
		}
		
		else putchar(n); 
	}
}
