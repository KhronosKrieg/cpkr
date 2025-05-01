/* Writ a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally*/



#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char [], char []);

int main() {
    char s1[100];
    char s2[200]; // s2 needs to be large enough to hold the expanded string

    strcpy(s1, "a-z");     expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abcdefghijklmnopqrstuvwxyz
    strcpy(s1, "A-Z");     expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    strcpy(s1, "0-9");     expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: 0123456789
    strcpy(s1, "a-b-c");   expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abc
    strcpy(s1, "a-z0-9");  expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abcdefghijklmnopqrstuvwxyz0123456789
    strcpy(s1, "-a-z");    expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: -abcdefghijklmnopqrstuvwxyz
    strcpy(s1, "a-z-");    expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abcdefghijklmnopqrstuvwxyz-
    strcpy(s1, "a-c-e");   expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abcce
    strcpy(s1, "A-C-E");   expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: ABCCE
    strcpy(s1, "1-3-5");   expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: 1235
    strcpy(s1, "a-z-A-Z-0-9"); expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abc...xyzABC...Z012...9
    strcpy(s1, "a-z-9-0"); expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abc...xyz-9-0 (invalid range 9-0)
    strcpy(s1, "a-Z");     expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: a-Z (invalid range)
    strcpy(s1, "-");       expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: -
    strcpy(s1, "abc");     expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: abc
    strcpy(s1, "");        expand(s1, s2); printf("'%s' expands to '%s'\n", s1, s2); // Expected: ""

    return 0;
}

void expand(char s1[], char s2[])
{

	int i=0, j=0,c, is_lower_range, is_upper_range, is_digit_range;
	char c1, c2;
 
	if( s1[i] == '-') s2[j++]=s1[i++];


	while(s1[i]!='\0')
	{
		if(s1[i+1] == '-' && s1[i+2]!='\0')
		{
			c1= s1[i];
			c2= s1[i+2];

			is_lower_range = islower(c1) && islower(c2) && (c1<=c2);
			is_upper_range = isupper(c1) && isupper(c2) && (c1<=c2);
			is_digit_range = isdigit(c1) && isdigit(c2) && (c1<=c2);

			if(is_lower_range || is_upper_range || is_digit_range)
			{
				for(c=c1;c<=c2;c++)
				{
					s2[j++]=c;
				}
				i+=3;
			}
			else
			{
				s2[j++] = s1[i++];
				s2[j++] = s1[i++];
			}

		}
		else
		{
			s2[j++] = s1[i++];
		}

	}
	
	s2[j] = '\0';
}
