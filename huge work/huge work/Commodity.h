#pragma once
#include<string>
using namespace std;
class Commodity
{
protected:
	string name;
	int id;
	double price;
public:
	int num=0;
	virtual string getname() = 0;
	virtual int getid() = 0;
	virtual double getprice()= 0;
	virtual int getnum() = 0;
};

