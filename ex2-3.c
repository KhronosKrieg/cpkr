/* Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htos(char []);
int main()
{
    char str[1000];
	printf("enter number:");
	scanf("%99s",str);
	htos(str);
}


int htos(char s[])
{
	int i, n;
	n = 0;

	if(strncmp(s,"0x",2)==0 || strncmp(s,"0X",2)==0)
		s+=2;//move pointer past the prefix by 2



	for(i = 0;s[i]!='\0';i++)
	{
		if((s[i]>='a' && s[i] <='f') || (s[i]>='A' && s[i]<='F'))
		{
			n=(n*16)+(tolower(s[i]-'a' + 10));

		}
		else if(s[i] >='0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else
		{
			printf("wrong input\n");
			return 0;
		}

	}
	printf("Hex value:%d\n",n);

}
