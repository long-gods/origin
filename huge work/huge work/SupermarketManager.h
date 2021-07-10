#pragma once
#include"drinks.h"
#include<vector>
#include<algorithm>

class SupermarketManager
{
protected:
	string a[5] = { "drinks","paper" };
	int drinksnum=0;
	vector<Commodity*> com[5];
public:

	void menu();
	void add();
	void show();
	void del();
	void changeinfor();
	void Search() {};
	void SortAndOut() {};
	void Sort();
	void PriceNum5() {};
	bool ifback();
};


