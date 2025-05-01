/* In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs */


#include <stdio.h>
#include <string.h>

void itoa(int, char []);
void reverse(char []);

void itoa(int n, char s[])
{
    int i, temp, sign;
    if(n <0) sign = 1; /*make n posiitive*/

    i = 0;
    do  /*generate digigs in reverse order*/
    {
        temp = n%10;
		if (temp <0) temp = -temp;
        s[i++] = temp  + '0'; /* get next digit */
    } while((n /= 10) != 0);

	if(sign >  0)
    s[i++] = '-';

    s[i] = '\0';
    reverse(s);
    printf("\nAscii:");
    for(i=0;s[i]!='\0';i++) printf("%c",s[i]);
}

void reverse(char s[])
{
    int c,i,j;

    for(i = 0, j=strlen(s)-1;i<j;i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    int n;
    char s[256];

    printf("enter integer:");
    scanf("%d",&n);
    itoa(n,s);
}                   
