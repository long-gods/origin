#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include "KsoString.h"




int main()
{

	//KsoString<char> str1;
	//KsoString<wchar_t> str2;
	KsoString<char> str1("hello");
	KsoString<wchar_t> str2(L"world");
	KsoString<char> str3("world");
	str1.show();
	cout << str1.getlength() << endl;
	cout << str1[0] << endl;
	str2.show();
	cout << str2.getlength() << endl;
	wcout << str2[3] << endl;
	str3 = str1;
	str3.show();
	KsoString<char> str4(str3);
	str4.show();
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
//template<class T>
//KsoString<T> operator+(const KsoString<T>& str1, const KsoString<T>& str2)
//{
//	node<T>* p = m_node;
//	while (p->next != NULL)
//	{
//		p = p->next;
//	}
//	p->next = str.m_node;
//	return *this;
//	}
//	KsoString<T> kso;
//	return KsoString();
//}
