#include <iostream>
#include <string>
class Time {
	int hour, minute, second;
public:
	Time(int h = 0, int m = 0, int s = 0) :hour(h), minute(m), second(s) {}
	Time& operator++()
	{
		second++;
		if (second == 60)
		{
			second = 0;
			minute++;
			if (minute == 60)
			{
				minute = 0;
				hour++;
				if (hour == 24)
					hour = 0;
			}
		}
		return *this;
	}

	Time operator++(int) {
		second++;
		if (second == 60)
		{
			second = 0;
			minute++;
			if (minute == 60)
			{
				minute = 0;
				hour++;
				if (hour == 24)
					hour = 0;
			}
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, Time time);
	friend std::istream& operator>>(std::istream& in, Time time);
};

// 补充代码

//主函数
int main() {
	Time time(11, 59, 58);
	for (int i = 0; i < 4; i++)
		std::cout << time++ << std::endl;
	std::cout << std::endl;
	for (int j = 0; j < 4; j++)
		std::cout << ++time << std::endl;
	return 0;
}

std::ostream& operator<<(std::ostream& out, Time time)
{
	out << time.hour <<" " << time.minute << " " << time.second << " " << std::endl;// TODO: 在此处插入 return 语句
	return out;
}

std::istream& operator>>(std::istream& in, Time time)
{
	in >> time.hour>>time.minute>>time.second;// TODO: 在此处插入 return 语句
	return in;
}
