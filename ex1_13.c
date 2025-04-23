/* write a program to print a histogram of the lengths of words in its input.*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int n,state,count;
	state = OUT;
    count = 0;	
	while((n=getchar())!=EOF)
	{
		
		if(n=='\t' || n=='\n' || n==' ')
		{
			
			if(state == IN )
			{
				//printf("%d\n", count);
		  		state = OUT;
				count = 0;
                putchar('\n');
			}
		
		}
	    else
		{
          count++;
		  state = IN;
          putchar('*');
		}
		
    }		

}
 
