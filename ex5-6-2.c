/* Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).*/



#include <stdio.h>
#include <ctype.h>

void atoi(char *, int *);

int main()
{
	char a[100];
	int i = 0;
	

	printf("enter ascii:");
	scanf("%s",a);
	atoi(a,&i);
	printf("integer:%d\n",i);
}

void atoi(char *s, int *i)
{
	int sign;
	*i = 0;
   
	while(isspace(*s))
		s++;
	sign = (*s == '-')? -1 : 1;

	if(*s == '+' || *s == '-')
		s++;

	while(isdigit(*s))
	{
		*i = (10 * *i) + (*s - '0');
		s++;
	}
	
	*i *=sign;

}
