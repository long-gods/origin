#pragma once
#include <iostream> 
#include <vector>
#include <limits>
using namespace std;

template<class T>
class Array
{
private:
	T* data_=new T[100];
	int size_;
public:
    Array(vector<T> v) {
        size_ = v.size();
        data_ = static_cast<T*> (new T[size_]);
        for (int i = 0; i < size_; i++) {
            data_[i] = v[i];
        }
    }
    ~Array();           // 析构函数，释放已经申请到的内存
    void sort();        // 排序，将数组中所有元素由小到大排序
    int seek(T key);    // 查找指定的元素key，返回其所在位置（位置编号从0开始）; 如果没有找到，则返回 -1
	void display() {
		int i;
		for (i = 0; i < size_; i++) {
			cout << data_[i];
			if (i != size_ - 1)
				cout << " ";  // 输出一个空格
		}
	}
};

template<class T>
void Swap(T* a, T* b)
{
	T c = *a;
	*a = *b;
	*b = c;
}

template<class T>
inline Array<T>::~Array()
{
    delete[] data_;
}

template<class T>
inline void Array<T>::sort()
{
	for (int i = 0; i < size_ - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < size_ - 1 - i; ++j)
		{
			if (data_[j] > data_[j + 1])
			{
				Swap(&data_[j], &data_[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}

template<class T>
inline int Array<T>::seek(T key)
{
	for(int i=0;i<size_;i++)
		if (data_[i] == key)
			return i;
	return -1;
}


