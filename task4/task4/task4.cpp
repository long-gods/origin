// task4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

class Animal
{
public:
    Animal() { cout << "Animal" << endl; }
    virtual int speak() { return 0; };
};

class Dog :public Animal{
public:
    Dog() { cout << "Dog" << endl; }
    int speak() {
        cout << "wang" << endl;
        return 1;
    }
    void swim() {
        cout << "swim" << endl;
    }
};

class Cat :public Animal {
public:
    Cat() { cout << "Cat" << endl; }
    int  speak() {
        cout << "miao" << endl;
        return 2;
    }
};
int main()
{
    int n=0;
    
    while (n <= 0)
    {
        cin >> n;
        if (n <= 0)
            cout << "输入错误，请重新输入：";
    }
    vector<Animal*> v;
    for (int i = 0; i < n; i++)
    {
        Dog d;
        v.push_back(&d);
        Cat c;
        v.push_back(&c);
    }

    for (vector<Animal*>::iterator it = v.begin(); it != v.end(); it++)
    {
        if ((*it)->speak() == 1)
        {
            Dog* d = dynamic_cast<Dog*>(*it);
            d->swim();
        }
    }
    cout << endl;
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
