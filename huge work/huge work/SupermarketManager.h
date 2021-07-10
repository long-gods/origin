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
	Commodity* comNum5[5];
public:
	vector <Commodity*> operator[](const string str);
	void menu();
	void add();
	void show(vector<Commodity*> com);
	void del();
	void changeinfor();
	void Search();
	void SortAndOut();
	void Sort(vector<Commodity*> com);
	void rSort(vector<Commodity*> com);
	void PriceNum5();
	bool ifback();
};


