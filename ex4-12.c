/*Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.*/

#include <stdio.h>
void itoa(int, char []);

int main()
{
	int n;
	char s[100];
	printf("enter integer:");
	scanf("%d",&n);
	itoa(n,s);
	printf("%s",s);
	return 0;
}

void itoa(int n, char s[] )
{
	static int i = 0;
	if(n<0)
	{
		s[i] = '-';
		n = -n;
		i++;
	}
	if (n / 10)
		itoa(n /10,s);
	s[i++] = (n%10) + '0';
}
