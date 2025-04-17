//Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

#include <stdio.h>

int main()
{
	int c,blank = 0;
    
    while((c = getchar())!=EOF)
	{
		if((c==' ' && !blank) || c!=' ') putchar(c);
        
 		if(c==' ') blank = 1;
		else blank = 0;
	}
}

