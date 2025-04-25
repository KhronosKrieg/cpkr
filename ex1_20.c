/* write a program detab that replaces tabs in the input with the proper number of blanks to space the next 
tab stop. Assume a fixed set of tab stops, say every n columns.Should n be a variable or a symbolic parameter?.*/


#include <stdio.h>
#define TAB 4

int main()
{
	int c, current_pos = 0, spaces_required;
	
	while((c= getchar())!=EOF)
    {
		if(c == '\t')
		{
			spaces_required =TAB -  (current_pos % TAB);
            //printf("current pos:%d,spaces:%d\n",current_pos ,spaces_required);
			for (int i = 0; i< spaces_required; i++)
				putchar(' ');
		}
		else if(c=='\n') /*when new line encountered current pos reset to zero*/
		{
			 putchar(c);
			 current_pos = 0;
		}
		else
		{
			++current_pos;
			putchar(c);
		}
	}
}
