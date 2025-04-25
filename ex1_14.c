/* write a program to print a histogram of the frequencies of different characters in its input */

#include <stdio.h>
#define MAX_CHAR 128

int main()
{
	int c, i, j;
    int freq[MAX_CHAR];
    
    for(i = 0; i<MAX_CHAR;i++) freq[i]= 0;


    while((c = getchar())!=EOF)
	{
		if(c < MAX_CHAR && c!='\n' && c!='\t' && c!=' ')
            freq[c]++;
	}
   printf("\n");   
   for (i = 0; i<MAX_CHAR; i++)
   {
		if(freq[i] > 0)
		{ 
			printf("%c:",i);
            for(j= 0; j< freq[i];j++)
			{
				printf("*");
			}
			printf("\n");
		}
   }
    
}
