#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include "KsoString.h"



template <class T>
KsoString<T>::KsoString() :pStart(nullptr), length(0)
{
}

template <class T>
KsoString<T>::KsoString(const T* p)
{
	//c++需要严格注意类型匹配。
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		this->length = strlen(reinterpret_cast<const char*>(p)) + 1;//字符串长度需要加1 \0
		this->pStart = new T[this->length];

		strcpy(reinterpret_cast<char*>(this->pStart), reinterpret_cast<const char*>(p));

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		this->length = wcslen(reinterpret_cast<const wchar_t*>(p)) + 1;
		this->pStart = new T[this->length];
		wcscpy(reinterpret_cast<wchar_t*>(this->pStart), reinterpret_cast<const wchar_t*>(p));

	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}
}

template <class T>
void KsoString<T>::operator = (const KsoString& str)
{
	//释放原来的数据
	if (this->pStart != nullptr)
	{
		delete[] this->pStart;
	}
	this->length = 0;


	this->length = str->length;
	this->pStart = new T[this->length];
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(this->pStart), reinterpret_cast<const char*>(str->pStart));

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wscpy(reinterpret_cast<wchar_t*>(this->pStart), reinterpret_cast<const wchar_t*>(str->pStart));

	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}

}
template <class T>
T KsoString<T>::operator [](int id)
{
	if (id < 0 || id >= this->length)
	{
		throw errorOutRange();
	}
	return this->pStart[id];
}

template <class T>
KsoString<T>::KsoString(const KsoString& str)
{
	//拷贝构造函数需要释放原来的数据
	if (this->pStart != nullptr)
	{
		delete[] this->pStart;
	}
	this->length = 0;

	this->length = str.length;
	this->pStart = new T[this->length];

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(this->pStart), reinterpret_cast<const char*>(str.pStart));

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t*>(this->pStart), reinterpret_cast<const wchar_t*>(str.pStart));

	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}
}

template <class T>
void KsoString<T>::show()
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		cout << reinterpret_cast<char*>(this->pStart) << endl;
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcout << reinterpret_cast<wchar_t*>(this->pStart) << endl;
	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}
}

template <class T>
KsoString<T>::~KsoString()
{
	if (this->pStart != nullptr)
	{
		delete[] this->pStart;
	}
}


//返回对象需要实例化 KsoString<T>
template <class T>
KsoString<T> KsoString<T>::operator + (const KsoString& str)
{
	KsoString<T> strTemp;
	strTemp.length = this->length + str.length - 1;
	strTemp.pStart = new T[strTemp.length];
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(strTemp.pStart), reinterpret_cast<char*>(this->pStart));
		strcat(reinterpret_cast<char*>(strTemp.pStart), reinterpret_cast<const char*>(str.pStart));
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t*>(strTemp.pStart), reinterpret_cast<wchar_t*>(this->pStart));
		wcscat(reinterpret_cast<wchar_t*>(strTemp.pStart), reinterpret_cast<const wchar_t*>(str.pStart));
	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}

	//会调用拷贝构造函数
	return strTemp;

}

template <class T>
void KsoString<T>::operator += (const KsoString& str)
{
	//"123"  4 "1234" 5
	this->length += (str.length - 1);//长度

	T* temp = new T[this->length];
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(temp), reinterpret_cast<char*>(this->pStart));
		strcat(reinterpret_cast<char*>(temp), reinterpret_cast<const char*>(str.pStart));
		delete[] this->pStart;

		this->pStart = temp;//拷贝
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t*>(temp), reinterpret_cast<wchar_t*>(this->pStart));
		wcscat(reinterpret_cast<wchar_t*>(temp), reinterpret_cast<const wchar_t*>(str.pStart));

		delete[] this->pStart;
		this->pStart = temp;//拷贝

	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}


}

template <class T>
ostream& operator <<(ostream& o, const KsoString<T>& str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		cout << reinterpret_cast<char*>(str.pStart);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcout << reinterpret_cast<wchar_t*>(str.pStart);
	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}
	return o;
}

template <class T>
istream& operator >>(istream& i, KsoString<T>& str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		char a[1000];
		cin >> a;
		delete[]str.pStart;
		str.length = strlen(reinterpret_cast<const char*>(a)) + 1;
		str.pStart = new T[str.length];
		strcpy(reinterpret_cast<char*>(str.pStart), reinterpret_cast<const char*>(a));
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wchar_t a[1000];
		wcin >> a;
		delete[]str.pStart;
		str.length = wcslen(reinterpret_cast<const wchar_t*>(a)) + 1;
		str.pStart = new T[str.length];
		wcscpy(reinterpret_cast<wchar_t*>(str.pStart), reinterpret_cast<const wchar_t*>(a));
	}
	else
	{
		cout << "类型不匹配，请检查输入的类型" << endl;
	}
	return i;
}

int main()
{

	//KsoString<char> str1;
	//KsoString<wchar_t> str2;
	KsoString<char> str1("hello");
	KsoString<wchar_t> str2(L"world");
	KsoString<char> str3;
	cin >> str3;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str1 + str3 << endl;
	cout << str1[2] << endl;
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
