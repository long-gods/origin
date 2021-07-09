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
	virtual string getname() = 0;
	virtual int getid() = 0;
	virtual double getprice()= 0;
};

