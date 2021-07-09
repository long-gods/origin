#pragma once
#include"drinks.h"
#include<vector>
#include<algorithm>

class SupermarketManager
{
protected:
	string a[5] = { "drinks","paper" };
	int drinksnum=0;
	vector<drinks*> dri;
public:
	void add();
	void adddrinks();
	void show();
	void beforedel();
	template<class T>
	void del(vector<T*> vec);
	void Sort();
};

template<class T>
inline void SupermarketManager::del(vector<T*> vec)
{
	cout << "删除商品和数量（如：王老吉 2）：";
	string name;
	int number;
	cin >> name >> number;
	for (auto ve : vec)
	{
		if (ve->name == name && ve->num >= number)
			ve->num -= number;
	}
}
