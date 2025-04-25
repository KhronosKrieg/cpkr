/*Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to 
achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank
 would suffice to reach a tab stop, which should be given preference?*/


#include <stdio.h>
#define TAB 4

int main
{
	int c, tabs_req,current_pos = 0; spaces_req,blanks = 0, tabs = 0, i,j,spaces;

    while((c=getchar())!=EOF)
	{
		if(c!='\t' && c!='\n' && c!=' ')
		{
			++current_pos;

            if(c = ' ')
			{
				++blanks;
				if(current_pos%TAB ==0 && blanks >1)
				{
					putchar('\t');
				}
			}
			spaces = blanks +(4*tabs);
            while(spaces>=TAB)
			
			
            spaces = 0;
			++current_pos;
			 putchar(c);
		     blanks = 0;
		     tabs = 0;
		}
		else if(c==' ') ++blanks;
		else if(c=='\t') +=tabs;
	}  
}
