#include <stdio.h>

#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/

int main()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while((c=getchar())!=EOF)
	{
		++nc;
		if(c == '\n') ++nl;
		if((c == ' ') || (c == '\n') || (c == '\t')) state  = OUT;
        else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("number of characters: %d\n, number of lines: %d\n, number of words : %d\n",nc,nl,nw);
}
        
