//Write a loop equivalent to the for loop above without using && or ||.

#include <stdio.h>

int main()
{
	int  year;
    printf("enter a year:");
    scanf("%d",&year);
    if(year % 4 == 0)
	{
		if(year % 400 == 0) printf("%d is a leap year\n",year);
		else if(year % 100 != 0)
		{
			printf("%d is a leap year\n",year);
		}
        else  printf("%d is not a leap year\n", year);
    }
    else  printf("%d is not  a leap year",year);
}   
