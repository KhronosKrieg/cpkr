/* Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.) */



#include <stdio.h>

void any(const char [],const  char []);
int main()
{
    char s1[100], s2[100];
    printf("enter first string:");
    scanf("%99s",s1);
    printf("\nenter second string:");
    scanf("%99s",s2);
    any(s1,s2);
}

void  any(const char s1[],const  char s2[])
{
    int i, j;

    for(i=0;s1[i]!='\0';i++)
    {
        for(j = 0;s2[j]!='\0';j++)
        {
            if(s1[i] ==s2[j])
            {
                printf("first location match index:%d",i+1);
                return;
            }

        }
       
    }
    printf("-1");
}
