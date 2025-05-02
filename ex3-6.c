/* Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough*/

#include <stdio.h>
#include <string.h>

void itoa(int , char [], int);
void reverse(char []);

void itoa(int n, char s[], int w)
{
	int i,rem, sign;

	sign = n;
	i=0;

	do{
		rem = n % 10;
		if(rem < 0) rem = -rem;
		s[i++] = rem + '0';

	}while((n/=10)!=0);

	if(sign < 0) s[i++] = '-';
	while(i < w)
	{
		s[i++] = ' ';
	}
	s[i] = '\0';

	reverse(s);

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
    int n, b ,i;
    char s[256];

    printf("enter integer:");
    scanf("%d",&n);

	printf("enter minimum field width:");
	scanf("%d",&b);
    itoa(n,s,b);
	printf("\nAscii:");
    for(i=0;s[i]!='\0';i++) printf("%c",s[i]);

}

