/*Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent*/


#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

double atof(char []);

double atof(char s[])
{
    double val, power;
    int i,j, sign, power_sign, exponent;

    for(i=0;isspace(s[i]);i++) /*skip white spaces*/
        ;
    sign = (s[i] == '-')?-1:1;
    if(s[i]=='+' || s[i] =='-')
        i++;
    for(val = 0.0; isdigit(s[i]);i++)
        val = (10.0 *val)+(s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0;isdigit(s[i]);i++)
    {
        val=10.0*val +(s[i] - '0');
        power *=10;
    }
	if(s[i] == 'e'|| s[i] == 'E')
		i++;

	 power_sign = (s[i] == '-')?-1:1;

	 if(s[i]=='+' || s[i] =='-')
        i++;

	 for(exponent = 0 ;isdigit(s[i]);i++)
		 exponent = (10 *exponent)+(s[i] - '0');

	 //printf("exponent:%d, power_sign:%c\n",exponent,power_sign);
	 for(j = 0; j< exponent;j++)
	 {
		 if(power_sign == -1) val = val /10;
		 else val = val*10;
	 }

    return sign*( val /power);
}

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);

    sum = 0;

    while(get_line(line, MAXLINE) > 0)
        printf("\t%g\n", atof(line));
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
                                                
