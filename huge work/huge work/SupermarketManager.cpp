#include "SupermarketManager.h"
using namespace std;
vector<Commodity*> SupermarketManager::operator[](const string str)
{
	int i = 0;
	for(i=0;i<5;i++)
		if(a[i]==str)
			return com[i];
}
void SupermarketManager::menu()
{
	int num = 1;
	while (num)
	{
		cout << "1、新增商品信息" << endl;
		cout << "2、删除商品信息" << endl;
		cout << "3、修改商品信息（ps：例如按Id修改价格、描述等）" << endl;
		cout << "4、商品信息检索" << endl;
		cout << "5、商品按价格排序输出" << endl;
		cout << "6、输出价格前五的商品" << endl;
		cout << "0、退出" << endl;
		cout << "请选择功能(0 - 6)：" << endl;
		cin >> num;
		switch (num) {
		case 0:break; break;
		case 1:add(); break;
		case 2:del(); break;
		case 3:changeinfor(); break;
		case 4:Search(); break;
		case 5:SortAndOut(); break;
		case 6:PriceNum5(); break;
		}
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
		int i = 0, flag = 0;
		cout << "名称：";
		cin >> name;
		double price;
		cout << "价格：";
		cin >> price;
		int id;
		cout << "id：";
		cin >> id;
		for (auto c : com[i])
		{
			if (c->getname() == name)
			{
				c->num++;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			com[i].push_back(new drinks(name, id, price));
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
			if (ve->getname() == name && ve->num >= number)
			{
				ve->num -= number;
				flag = 1;
				if (ve->num == 0)
				{
					delete ve;
					ve = NULL;
				}
			}
		}
		if (flag == 0)
			cout << "删除失败！！！" << endl;
		else
			cout << "删除成功！！！" << endl;
		if (ifback())
			menu();
		else
			del();
		
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
			rSort(com[i]);
			show(com[i]);
		}
	if (i == 5)
		cout << "不存在此类商品。" << endl;
	if (!ifback())
		Search();
}

void SupermarketManager::SortAndOut()
{
	cout << ">>>>>>商品排序输出<<<<<" << endl;
	cout << "类型：";
	string type;
	cin >> type;
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == type)
		{
			cout << "排序类型（1=由高到低，2=由低到高）:" << endl;
			int in;
			cin >> in;
			if (in == 1)
			{
				rSort(com[i]);
				cout << *com[i].begin();
				for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
					cout << " > " << *it;
			}
			else if (in == 2)
			{
				Sort(com[i]);
				cout << *com[i].begin();
				for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
					cout << " < " << *it;
			}
			else
				cout << "错误的输入" << endl;
		}
	}
	if (!ifback())
		SortAndOut();
	//cout << ">>>>>>商品排序输出<<<<<" << endl;
	//cout << "排序类型（1=由高到低，2=由低到高）:";
	// int in;
	//cin >> in;
	//for (int i = 0; i < 5; i++)
	//{
	// 	   for(auto co:com[i])
	//		if (a[i] == type)
	//			{
	//				int in;
	//				cin >> in;
	//				if (in == 1)
	//				{
	//					rSort(com[i]);
	//					show(com[i]);
	//				}
	//		else if (in == 2)
	//		{
	//			Sort(com[i]);
	//			show(com[i]);
	//		}
	//		else
	//			cout << "错误的输入" << endl;
	//	}
	//}
	//if (!ifback())
	//	SortAndOut();
}

void SupermarketManager::Sort(vector<Commodity*> com)
{
	sort(com.begin(), com.end());
}

void SupermarketManager::rSort(vector<Commodity*> com)
{
	sort(com.rbegin(), com.rend());
}

void SupermarketManager::PriceNum5()
{
	for (int i = 0; i < 5; i++)
		rSort(com[i]);

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
