/* Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.*/

#include <stdio.h>

void str_cat(char *, char *);
void getstr(char *);

void str_cat(char *s, char *t)
{

	while( *s!='\0') s++;
	while( *t!='\0')
	{
		*s = *t;
		t++;
		s++;
	}
	*s = '\0';
	//while (*s) s++;           // move to end of s
    //while ((*s++ = *t++)) ;   // copy t to end of s
}

int main()
{
	char s[100], t[100];
	printf("enter first char:");
	getstr(s);
	printf("enter second char:");
	getstr(t);
	str_cat(s, t);
	printf("concat string:");
	printf("%s\n",s);
}

void getstr(char *s)
{
	int c;
	while((c = getchar())!='\n')
		*s++ = c;
	*s = '\0';
}
