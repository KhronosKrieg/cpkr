#include <stdio.h>
#include <string.h>

void itoa(int, char []);
void reverse(char []);

void itoa(int n, char s[])
{
	int i, sign;
	if((sign = n) <0) n = -n; /*make n posiitive*/

	i = 0;
	do  /*generate digigs in reverse order*/
	{
		s[i++] = (n%10) + '0'; /* get next digit */
	} while((n /= 10) > 0);

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
	printf("\nAscii:");
	for(i=0;s[i]!='\0';i++) printf("%c",s[i]);
}

void reverse(char s[])
{
	int c,i,j;

	for(i = 0, j=strlen(s)-1;i<j;i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main()
{
	int n;
	char s[256];

	printf("enter integer:");
	scanf("%d",&n);
	itoa(n,s);
}




/* enter integer:4294967296

Ascii:0


enter integer:-2147483648

Ascii:-(

The output -( is occurring due to a combination of the two issues we discussed earlier:

The Attempt to Negate INT_MIN Causes Overflow:
Your code has the line if((sign = n) <0) n = -n;. When n is INT_MIN (e.g., -2147483648), the expression -n attempts to calculate -(-2147483648), which is 2147483648. This value is one greater than INT_MAX. Attempting to store 2147483648 back into the int variable n results in integer overflow. On most systems using two's complement, this overflow causes n to wrap around and become INT_MIN again (-2147483648). So, after this line, n is still -2147483648.

The do-while Loop Condition and n % 10 Behavior:
The do-while loop starts with n = -2147483648.

Inside the loop, (n % 10) is calculated. For -2147483648 % 10, the result is -8 (in C, the sign of the result of % matches the sign of the dividend).
You then calculate (-8) + '0'. The ASCII value of '0' is 48. So, (-8) + 48 equals 40.
The integer value 40 corresponds to the ASCII character (. This character is stored in s[0].
The loop condition (n /= 10) > 0 is then checked. n /= 10 is -2147483648 / 10, which is -214748364. The condition (-214748364 > 0) is false. The loop terminates after only one iteration.

*/

