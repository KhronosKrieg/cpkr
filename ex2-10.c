/* Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.*/


#include <stdio.h>

int lower(int);

int main()
{
	char c;
	printf("enter a character:");
	scanf("%c",&c);
	printf("%c",lower(c));
	return 0;

}

int lower(int c)
{
	return (c>='A' && c<='Z')? c + 'a' -'A' :c;
}
