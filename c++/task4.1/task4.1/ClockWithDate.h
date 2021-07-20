#pragma once
#include"Clock.h"
#include"Date.h"
class ClockWithDate :
    public Date,public Clock
{
public:
	ClockWithDate() {};
	ClockWithDate(int h, int m, int s, int d, int mon, int y);
    void showTime() {
        std::cout<< "Now:" << hour << ":" << minute << ":" << second << std::endl;
        std::cout << year << "-" << month << "-" << day << std::endl;
    }
    void run() {
		second = second + 1;
		if (second > 59)
		{
			second = 0;
			minute += 1;
		}
		if (minute > 59)
		{
			minute = 0;
			hour += 1;
		}
		if (hour > 23)
		{
			hour = 0;
			NewDay();
		}
    }
};

