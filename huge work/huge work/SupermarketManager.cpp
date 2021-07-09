#include "SupermarketManager.h"
#include<iostream>
using namespace std;
void SupermarketManager::add()
{
	int flag = 0,i=0;
	string obj;
	cin >> obj;
	for (i = 0; i < 5; i++)
	{
		if (a[i] == obj)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		switch (i) {
		case 1:adddrinks(); break;
		case 2:addpaper(); break;
		}
	}
	else
		cout << "没有这种类型" << endl;
}

void SupermarketManager::adddrinks()
{
	string name;
	int i = 0,flag=0;
	cout << "名称：";
	cin >> name;
	double price;
	cout << "价格：";
	cin >> price;
	int id;
	cout << "id：";
	cin >> id;
	for (auto dr:dri)
	{
		if (dr->getname() == name)
		{
			dr->addnum();
			flag = 1;
		}
	}

	if (flag == 0)
	{
		dri.push_back(new drinks(name,id,price));
	}
}

void SupermarketManager::show()
{
	Sort();
	cout << *dri.begin();
	for (vector<drinks*>::iterator it = dri.begin()+1; it != dri.end(); it++)
		cout<<" , " << *it;
}

void SupermarketManager::beforedel()
{
	cout << "类型：";
	string type;
	int i = 0;
	while (a[i] != type || i < 5) {
		i++;
	}
	if (i == 5)
		cout << "没有这种类型！"<<endl;
	else
	{
		switch (i) {
		case 1:del(dri); break;
		}
		
	}

}

void SupermarketManager::Sort()
{
	sort(dri.begin(), dri.end());
}
