#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template<class T=char>
struct node {
	T data;
	node* next;
};
class errorOutRange
{

};

template <class T = char>
class KsoString
{
public:
	KsoString();
	KsoString(const T* p);//char* 构造函数
	int getlength() { return length; }
	void insert_point(int n, T data);
	void delete_point(int n, T data);

	T operator [](int id);
	void show() {
		node<T>* p;
		p = m_node;
		if (strcmp(typeid(T).name(), "char") == 0)
			while (p->next != NULL)
			{
				cout << p->data;
				p = p->next;
			}
		else if (strcmp(typeid(T).name(), "wchar_t") == 0)
			while (p->next != NULL)
			{
				wcout << p->data;
				p = p->next;
			}
		else
				cout << "类型不匹配，请检查输入的类型" << endl;
		cout << endl;
	}

private:
	node<T>* m_node;
	int length = 0;
};


template <class T>
KsoString<T>::KsoString()
{
	m_node = (node<T>*)malloc(sizeof(node<T>));
	m_node->data = {};
	m_node->next = NULL;
	length = 0;
}

template <class T>
KsoString<T>::KsoString(const T* p)
{
	m_node = (node<T>*)malloc(sizeof(node<T>));
	m_node->data = {};
	m_node->next = NULL;
	length = 0;
	//c++需要严格注意类型匹配。
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		this->length = strlen(reinterpret_cast<const char*>(p)) + 1;//字符串长度需要加1 \0
		for (int i = 0; i < this->length; i++)
			insert_point(i, p[i]);

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		this->length = wcslen(reinterpret_cast<const wchar_t*>(p)) + 1;
		for (int i = 0; i < this->length; i++)
			insert_point(i, p[i]);

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
		return '0';
	}
	node<T>* p;
	p = m_node;
	while (id--)
	{
		p = p->next;

	}
	return p->data;
}

template<class T>
inline void KsoString<T>::insert_point(int n, T data)
{
	node<T>* p;
	p = m_node;
	for (int i = 0; i < n-1; i++)
	{
		p = p->next;
	}
	node<T>* insertpoint;
	insertpoint = (node<T>*)malloc(sizeof(node<T>));
	if (n == 0)
	{
		insertpoint->data = data;
		insertpoint->next = p;
		m_node = insertpoint;
	}
	else
	{
		insertpoint->data = data;
		insertpoint->next = p->next;
		p->next = insertpoint;
	}
}

template<class T>
inline void KsoString<T>::delete_point(int n, T data)
{
	node<T>* p;
	p = m_node;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	node<T>* d;
	d = p;
	p = p->next;
	free(d);
}






