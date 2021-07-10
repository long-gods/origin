#pragma once
#include<string>
#include<iostream>
using namespace std;
class Commodity
{
protected:
	string name;
	int id=0;
	double price=0;
	string describe;
public:
	int num=0;
	virtual bool operator<(Commodity com) = 0;
	virtual string getname() = 0;
	virtual int getid() = 0;
	virtual double getprice()= 0;
	virtual int getnum() = 0;
	virtual void newprice(double newp)=0;
	virtual void newdescribe(string newd) = 0;
	friend ostream& operator<<(ostream& out, Commodity* com);
};

ostream& operator<<(ostream& out, Commodity* com)
{

	out << "[" << com->getname() << "($" << com->getprice() << "),剩余" << com->getnum() << "]";
	return out;
	// TODO: 在此处插入 return 语句
}