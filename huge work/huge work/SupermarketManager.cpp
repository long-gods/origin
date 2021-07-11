#include "SupermarketManager.h"
using namespace std;
vector<Commodity*> SupermarketManager::operator[](const string str)
{
	int i = 0;
	for(i=0;i<5;i++)
		if(a[i]==str)
			return com[i];
}

void SupermarketManager::init()
{
	string name;
	int id;
	double price;
	int num;
	while (name != "end")
	{
		cin >> name >> id >> price >> num;
		initdrinks(name, id, price, num);
	}
	while (name != "end")
	{
		cin >> name >> id >> price >> num;
		initpapers(name, id, price, num);
	}
}

void SupermarketManager::add()
{
	cout << ">>>>>>增加商品<<<<<<" << endl;
	int flag = 0,i=0;
	string obj;
	cout << "类型：";
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
		string name;
		cout << "名称：";
		cin >> name;
		double price;
		cout << "价格：";
		cin >> price;
		int id;
		cout << "id：";
		cin >> id;
		int num;
		cout << "数量：";
		cin >> num;
		for (auto c : com[i])
		{
			if (c->getname() == name)
			{
				c->num+=num;
				flag = 0;
			}
		}

		if (flag == 1)
		{
			com[i].push_back(new drinks(name, id, price,num));
		}
		cout << "商品添加成功" << endl;
		if (!ifback())
			add();
	}
	else
		cout << "没有这种类型" << endl;
}

void SupermarketManager::show(vector<Commodity*> com)
{
	cout << *com.begin();
	for (vector<Commodity*>::iterator it = com.begin()+1; it != com.end(); it++)
		cout<<" , " << *it;
	cout << endl;
}


//void SupermarketManager::show()
//{
//	Sort();
//	cout << *dri.begin();
//	for (vector<drinks*>::iterator it = dri.begin()+1; it != dri.end(); it++)
//		cout<<" , " << *it;
//}

void SupermarketManager::del()
{
	cout << ">>>>>>删除商品<<<<<<" << endl;
	cout << "类型：";
	string type;
	int i = 0;
	cin >> type;
	while (a[i] != type) {
		i++;
		if (i == 5)
			break;
	}
	if (i == 5)
		cout << "没有这种类型！"<<endl;
	else
	{
		int flag = 0;
		cout << "删除商品和数量（如：王老吉 2）：";
		string name;
		int number;

		cin >> name >> number;
		for (auto ve : com[i])
		{
			if (ve->getname() == name)
			{
				ve->num -= number;
				flag = 1;
				if (ve->num <= 0)
				{
					delete ve;
					ve = NULL;
				}
				cout << "删除成功！！！" << endl;
			}
		}
	}
	if (!ifback())
		del();
}

void SupermarketManager::changeinfor()
{
	cout << ">>>>>>修改商品<<<<<" << endl;
	cout << "名称：";
	string name;
	cin >> name;
	for(int i=0;i<5;i++)
		for(auto co:com[i])
			if (co->getname() == name)
			{
				cout << " 修改项（1 = 价格，2 = 描述）：";
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					cout << "新价格：";
					double newp;
					cin >> newp;
					co->newprice(newp);
					cout << "价格修改成功" << endl;
				}
				else if (choice == 2)
				{
					cout << "新描述：";
					string newd;
					cin >> newd;
					co->newdescribe(newd);
					cout << "描述修改成功" << endl;
				}
				else
					cout << "输入错误" << endl;
			}
	if (!ifback())
		changeinfor();
}

void SupermarketManager::Search()
{
	cout << ">>>>>>商品信息检索<<<<<" << endl;
	cout << "类型：";
	string type;
	int i = 0;
	cin >> type;
	for(i=0;i<5;i++)
		if (a[i] == type)
		{
			if (com[i].empty())
			{
				cout << "这类商品卖完了" << endl;
				break;
			}
			Sort(com[i]);
			show(com[i]);
			break;
		}
	if (i == 5)
		cout << "不存在此类商品。" << endl;
	if (!ifback())
		Search();
}

void SupermarketManager::SortAndOut()
{
	cout << ">>>>>>商品排序输出<<<<<" << endl;
	
	for (int i = 0; i < 5; i++)
		for (auto co : com[i])
			sorts.push_back(co);
	if (sorts.empty())
		cout << "商品为空" ;
	else if (sorts.size() == 1)
		cout<<"只有一件不排" << *sorts.begin();
	else
	{
		cout << "排序类型（1=由高到低，2=由低到高）:" << endl;
		int in;
		cin >> in;
		if (in == 1)
		{
			Sort(sorts);
			cout << *sorts.begin();
			if (sorts.size() != 1)
				for (vector<Commodity*>::iterator it = sorts.begin() + 1; it != sorts.end(); it++)
					cout << " > " << *it;
		}
		else if (in == 2)
		{
			Sort(sorts);
			cout << (sorts[sorts.size()-1]);
			for (int i= sorts.size() - 2;i>=0;i--)
				cout << " < " << sorts[i];
		}
		else
			cout << "错误的输入" ;
	}
	sorts.clear();
	cout << endl;
	if (!ifback())
		SortAndOut();
	//cout << ">>>>>>商品排序输出<<<<<" << endl;
	//cout << "类型：";
	//string type;
	//cin >> type;
	//for (int i = 0; i < 5; i++)
	//{
	//	if (a[i] == type)
	//	{
	//		cout << "排序类型（1=由高到低，2=由低到高）:" << endl;
	//		int in;
	//		cin >> in;
	//		if (in == 1)
	//		{
	//			rSort(com[i]);
	//			cout << *com[i].begin();
	//			for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
	//				cout << " > " << *it;
	//		}
	//		else if (in == 2)
	//		{
	//			Sort(com[i]);
	//			cout << *com[i].begin();
	//			for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
	//				cout << " < " << *it;
	//		}
	//		else
	//			cout << "错误的输入" << endl;
	//	}
	//}
	//if (!ifback())
	//	SortAndOut();
}

void Quicksort(vector<Commodity*>& a, int low, int high)
{
	int i = low, j = high;
	if (i<j)
	{
		Commodity* key = a[i];
		while (j != i)
		{
			if (a[i] == key)
			{
				if (a[j]->getprice() > key->getprice())
				{
					a[i] = a[j];
					a[j] = key;
				}
				else
					j--;
			}
			else
			{
				if (a[i]->getprice() < key->getprice())
				{
					a[j] = a[i];
					a[i] = key;
				}
				else
					i++;
			}
		}

		Quicksort(a, 0, i-1);
		Quicksort(a, i+1, high);
	}
}


void SupermarketManager::Sort(vector<Commodity*>& com)
{
	int n = com.size();
	Quicksort(com, 0, n-1);
}

//void SupermarketManager::rSort(vector<Commodity*> com)
//{
//	vector<Commodity*>::iterator i = com.begin(), j = com.end();
//	Quicksort(com, i, j);
//
//}

void SupermarketManager::PriceNum5()
{
	for (int i = 0; i < 5; i++)
		for (auto co : com[i])
			sorts.push_back(co);
	if (sorts.empty())
		cout << "商品为空";
	else if (sorts.size() == 1)
		cout << *sorts.begin();
	else
	{
		Sort(sorts);
		cout << *sorts.begin();
		if (sorts.size() < 5)
		{
			cout << *sorts.begin();
			if (sorts.size() != 1)
				for (vector<Commodity*>::iterator it = sorts.begin() + 1; it != sorts.end(); it++)
					cout << " > " << *it;
			sorts.clear();
		}
		else
		{
			for (int i = 1; i < 5; i++)
				cout << ">" << sorts[i];
		}
	}
	cout << endl;
	if (!ifback())
		PriceNum5();
	sorts.clear();
}

//void SupermarketManager::Sort()
//{
//	sort(dri.begin(), dri.end());
//}

bool SupermarketManager::ifback()
{
	cout << "是否返回主菜单（y返回，n退出）：";
	char in;
	cin >> in;
	if (in == 'y')
		return true;
	else if (in == 'n')
		return false;
	else
		ifback();		
}

