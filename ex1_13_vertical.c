/* write a program to print a histogram of the lengths of words in its input.*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int n,state,count, word_count,max= 0;
    int hist[10];
    state = OUT;
    count = 0, word_count = 0;
    while((n=getchar())!=EOF)
    {

        if(n=='\t' || n=='\n' || n==' ')
        {

            if(state == IN )
            {
                //printf("%d\n", count);
                state = OUT;
                hist[word_count]=count;
                printf("count: %d\n",count);
                if(count > max) max = count;
                count = 0;
                word_count++;
            }

        }
        else
        {
          count++;
          state = IN;
        }

    }
    printf("word_count:%d\n",word_count);
    for(int i = 0; i<word_count;i++)
		printf("%d\n",hist[i]);

    for(int i = 0; i<max;i++)
       {
		for(int j = 0;j<word_count;j++)
           {
			if(i<hist[j]) putchar('*');
            else putchar(' ');
            }
         putchar('\n');
        }
}


