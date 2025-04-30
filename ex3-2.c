/* Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.*/


#include <stdio.h>
#define SIZE  10000
void escape(char [], char []);
void unescape(char [], char []);

int main()
{
    int i=0, j=0;
	char c[SIZE], r[SIZE], t[SIZE];
    while(((c[i++] =getchar())!=EOF)&& i< SIZE)
		;
	escape(c,r);
    
	printf("\nescape:\n");
	while(r[j]!='\0')
	{
		putchar(r[j++]);
	}

    j=0;
	unescape(c,t);
	printf("\nunescape:\n");
	while(t[j]!='\0')
	{
		putchar(t[j++]);
	}
	return 0;

	
}


void escape(char s[], char t[])
{
    int j=0;
	for(int i =0;s[i]!='\0';i++)
	{
		switch(s[i])
		{
			case '\n': t[j++] ='\\';
					   t[j++] ='n';
					   break;
		    case '\t': t[j++] ='\\';
					   t[j++] = 't';
					   break;
			default:  t[j++] = s[i];
					  break;

		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i,j;
	for (i =0, j=0; s[i]!=0;i++)
	{
		if(s[i]=='\\')
		{
			i++;
			switch(s[i])
			{
				case 'n': t[j++] ='\n';
						  break;
				case 't': t[j++] ='\t';
						  break;
				default:
						  t[j++] = '\\';
						  t[j++] = s[i];
						  break;
			}
		}
		else
		{
			t[j++] = s[i];
		}
	}
	t[j] = '\0';
}
	


