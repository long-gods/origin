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
	string getname() { return name; }
	int getid() { return id; }
	double getprice() { return price; }
	int getnum() { return num; }
	void addnum() { num++; }
	void addname(string name);
	void newprice(double newp);
	void newdescribe(string newd);
	friend ostream& operator<<(ostream& out, Commodity* com);
	virtual ~Commodity() = 0;
};

inline ostream& operator<<(ostream& out, Commodity* com)
{

	out << "[" << com->getname() << "($" << com->getprice() << "),剩余" << com->getnum() << "]";
	return out;
	// TODO: 在此处插入 return 语句
}