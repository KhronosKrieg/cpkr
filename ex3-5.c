/* Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.*/


#include <stdio.h>
#include <string.h>

void itob(int ,char [], int);
void reverse(char []);

void itob(int n, char s[], int b)
{
	int rem, j=0, sign;
    
	sign = n;

	if(n==0) s[j++] = '0';
   
	while(n!=0)
	{
		rem = n%b;
		if(rem <0) rem = -rem;

		if(rem < 10) s[j++] = rem + '0';
		else s[j++] = rem - 10 + 'A';
	
		n = n / b;

	}

	if(sign < 0) s[j++] = '-';
	s[j] = '\0';
}



void reverse(char s[])
{
	int i, j;
	char temp;


	for (i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;

	}
	
}

int main()
{
	int n,b,i;
	char s[256];

	

	printf("enter integer:");
	scanf("%d",&n);
	printf("enter base format:");
	scanf("%d",&b);
	
	itob(n,s,b);
    
	reverse(s);

	printf("result:");
	for (i=0;s[i]!=0;i++)
    {
        printf("%c",s[i]);
    }


	return 0;
}
