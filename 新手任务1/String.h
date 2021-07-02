#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


class errorOutRange
{

};

template <class T = char>
class String
{
public:
	String();
	~String();
	String(const T* p);//char* 构造函数

	String(const String& str);//拷贝构造函数
	void operator = (const String& str);//赋值构造函数

	String operator + (const String& str);
	void operator += (const String& str);

	T operator [](int id);

	void show();
	//流式运算符重载
	friend ostream& operator << <>(ostream& o, const String<T>& str);
	friend istream& operator >> <>(istream& o, String<T>& str);
private:
	T* pStart = nullptr;
	int length = 0;
};

