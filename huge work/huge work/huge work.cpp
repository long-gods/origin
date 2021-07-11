// huge work.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"SupermarketManager.h"

void menu(SupermarketManager manager)
{
	int num1 = 1;
	while (num1)
	{
		cout << "1、新增商品信息" << endl;
		cout << "2、删除商品信息" << endl;
		cout << "3、修改商品信息（ps：例如按Id修改价格、描述等）" << endl;
		cout << "4、商品信息检索" << endl;
		cout << "5、商品按价格排序输出" << endl;
		cout << "6、输出价格前五的商品" << endl;
		cout << "0、退出" << endl;
		cout << "请选择功能(0 - 6)：";
		std::cin >> num1;
		switch (num1) {
		case 0:break; break;
		case 1:manager.add(); break;
		case 2:manager.del(); break;
		case 3:manager.changeinfor(); break;
		case 4:manager.Search(); break;
		case 5:manager.SortAndOut(); break;
		case 6:manager.PriceNum5(); break;
		case 7:manager.init(); break;
		}
	}
}
int main()
{
    SupermarketManager manager;
    menu(manager);
    return 0;
}

 //运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
 //调试程序: F5 或调试 >“开始调试”菜单

 //入门使用技巧: 
 //  1. 使用解决方案资源管理器窗口添加/管理文件
 //  2. 使用团队资源管理器窗口连接到源代码管理
 //  3. 使用输出窗口查看生成输出和其他消息
 //  4. 使用错误列表窗口查看错误
 //  5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
 //  6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
