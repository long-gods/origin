#pragma once
#include<iostream>
class Date
{
public:
	Date(int y = 1996, int m = 1, int d = 1)
	{
		if (m > 12 || m < 1)
		{
			m = 1;
		}
		if (d > days(y, m))
		{
			day = 1;
		}
		day = d;
		year = y;
		month = m;
	};
	int days(int year, int month);
	void NewDay();
	virtual void showTime()
	{
		std::cout << year << "-" << month << "-" << day << std::endl;
	}
protected:
	int year;
	int month;
	int day;
};

