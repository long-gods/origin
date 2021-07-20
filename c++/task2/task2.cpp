// task2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

template<class T>
void Quicksort(T* a, int low, int high)
{
    int i = low, j = high;
    if (i < j)
    {
        T key = a[i];
        while (j != i)
        {
            if (a[i] == key)
            {
                if (a[j] < key)
                {
                    a[i] = a[j];
                    a[j] = key;
                }
                else
                    j--;
            }
            else
            {
                if (a[i] > key)
                {
                    a[j] = a[i];
                    a[i] = key;
                }
                else
                    i++;
            }
        }

        Quicksort(a, 0, i - 1);
        Quicksort(a, i + 1, high);
    }
}

int main()
{
    int n;
    cout << "输入int型数据数量：";
    cin >> n;
    int* a = new int[n];
    cout << "输入" << n << "个数据";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    delete a;
    cout << "输入double型数据数量：";
    cin >> n;
    double* b = new double[n];
    cout << "输入" << n << "个数据";
    for (int i = 0; i < n; i++)
        cin >> b[i];
    Quicksort(b, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    delete b;
    return 0;
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
