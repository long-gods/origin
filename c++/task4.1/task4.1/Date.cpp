#include "Date.h"

int Date::days(int year, int month)
{
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
		return a[month - 1] + 1;
	else
		return a[month - 1];
}

void Date::NewDay()
{
	day++;
	if (day % days(year, month) == 1)
	{
		day =1;
		month++;
		if (month == 13)
		{
			month = 1;
			year++;
		}
	}
}
