

#include <stdio.h>
#include <string.h>

void reverse(char *);

int main()
{
	char s[100];
	printf("enter string:");
	scanf("%s",s);
	reverse(s);
	printf("reversed string: %s",s);
}

void reverse(char *s)
{
	int first, last;
	int c;

	first = 0;
	last = strlen(s)-1;

	while(first < last)
	{
		c = *(s+first);
		*(s + first) = *(s + last);
		*(s + last)  = c;
		first++;
		last--;
	}
}
