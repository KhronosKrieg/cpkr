/* Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. */


#include <stdio.h>

void squeeze(char [], const char []);
int main()
{
	char s1[100], s2[100];
	printf("enter first string:");
	scanf("%99s",s1);
	printf("\nenter second string:");
	scanf("%99s",s2);
	squeeze(s1,s2);
}

void squeeze(char s1[], const char s2[])
{
	int i, j, k, found=0;

	for(i=k=0;s1[i]!='\0';i++)
	{
		found = 0;
		for(j = 0;s2[j]!='\0';j++)
		{
			if(s1[i] ==s2[j])
			{
				found =1;
				break;
			}
			
		}
		if(!found)
		{
			s1[k++] =s1[i];
		}
	}
	s1[k] = '\0';
	printf("\nsqueezed string: %s",s1);
}
