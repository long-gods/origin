#pragma once
#include"drinks.h"
#include"papers.h"
#include<vector>
#include<algorithm>

class SupermarketManager
{
protected:
	string a[5] = { "drinks","papers" };
	int drinksnum=0;
	vector<Commodity*> com[5];
	vector<Commodity*> sorts;
public:
	SupermarketManager() {};
	vector <Commodity*> operator[](const string str);
	void init();
	void initdrinks(string name, int id, double price, int num = 1) { com[0].push_back(new drinks(name, id, price, num)); }
	void initpapers(string name, int id, double price, int num = 1) { com[1].push_back(new papers(name, id, price, num)); }
	void add();
	void show(vector<Commodity*> com);
	void del();
	void changeinfor();
	void Search();
	void SortAndOut();
	void Sort(vector<Commodity*>& com);
	void PriceNum5();
	bool ifback();
};




