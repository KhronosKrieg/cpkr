/* Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none */

#include <stdio.h>
#define MAXLINE 1000

int strindex(char [], char []);
int get_line(char [], int);

int strindex(char s[], char t[])
{
	int i, j, k, found=-1;

	for(i=0; s[i]!='\0';i++)
	{
		for(j=i,k=0; s[j]==t[k] && t[k]!=0;j++, k++)
			;
		if(k>0 && t[k] == '\0')
			found = i;
	}
	return found;
}

int main()
{
	char line[MAXLINE];
    char pattern[] = "ould";
	int found;
	while(get_line(line, MAXLINE) > 0)
		if((found = strindex(line, pattern))>=0)
		{
			printf("Last occurence found at %d: %s",found, line);
		}
	    else
			printf("Not found\n");

	return 0;
}


int get_line(char s[], int lim)
{
	int i,c;

	i = 0;
	while(--lim > 0 && (c =getchar())!= EOF && c!='\n')
	{
		s[i++] = c;
	}
	if(c=='\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}
