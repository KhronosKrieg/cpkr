/*write a program to count blanks, tabs and newlines*/

#include <stdio.h>

int main()
{
	int c, nl = 0, nt = 0 ,nb = 0;

	while((c=getchar())!=EOF)
	{
		if(c == ' ') ++nb;   /*C, character literals are enclosed in single quotes ('), not double quotes ("). So, instead of c == " ", it should be c == ' '.*/
        else if (c == '\t') ++nt;
		else if (c == '\n') ++nl;
    }
 
 printf("number of blanks:%d\n number of tabs:%d\n number of new lines:%d\n",nb,nt,nl);
}

