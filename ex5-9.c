/*Rewrite the routines day_of_year and month_day with pointers instead of indexing.*/

#include <stdio.h>

static char daytab[2][13] =
{
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char month_name[][12] = { "-", "Jan", "Feb", "Mar" , "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};

/*day_of_year: set day of year from month & day*/
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (month < 1 || month > 12)
	{
		printf("wrong value: enter month between 1 and 12\n");
		return -1;
	}
	if (year < 1)
	{
		printf("year cannot be negative\n");
		return -1;
	}
	if (day < 1 || day > *(*(daytab + leap) + month))
	{
		printf("Wrong input: Maximum number of days in %d month is %d\n", month,*( *(daytab +leap) +month));
		return -1;
	}
	for (i = 1; i < month; i++)
	{
		day += *(*(daytab + leap) + i);
	}
	return day;
}

/*month_day: set month, day from day of year*/
int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (year < 1)
	{
		printf("year cannot be negative\n");
		return -1;
	}
	if (leap && (yearday > 366 || yearday < 0))
	{
		printf("maximum days in leap year is 366\n");
		return -1;
	}
	else if (!leap && (yearday > 365 || yearday < 0))
	{
		printf("maximum days in  year is 36\n");
		return -1;
	}

	for (i = 1; yearday > *(*(daytab + leap) + i); i++)
	{
		yearday -= *(*(daytab + leap) + i);
	}
	*pmonth = i;
	*pday = yearday;
	return 1;
}

int main()
{
	int choice, yearday,month, day, year,result;
	while (1)
	{
		printf("choose 1 or 2:\n");
		printf("1 : find yearday from year, month and day\n");
		printf("2 : find month and day from year and year day\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("enter year:");
			scanf("%d", &year);
			printf("enter month:");
			scanf("%d", &month);
			printf("enter day:");
			scanf("%d", &day);
			result = day_of_year(year, month, day);
			if (result > 0)
			{
				printf("the year day is %d\n", result);
			}
			
		}
		else if (choice == 2)
		{
			printf("enter year:");
			scanf("%d", &year);
			printf("enter yearday:");
			scanf("%d", &yearday);
			if(month_day(year, yearday, &month, &day) == 1) printf("the month  is %s and day is %d\n", *(month_name + month), day);
		}
	}
}