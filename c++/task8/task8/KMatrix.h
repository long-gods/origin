#pragma once
#include<vector>
#include<iostream>
using namespace std;

struct MyStruct
{
	int x=5;
	int y=5;
	int a[5][5] = {
		{1,2,3,4,5},{6,7,8,9,0},{2,3,4,5,6},{4,2,1,65,34},{2,3,4,7,9}
	};
};



template<class T>
class KMatrix
{
private:
	vector<vector<T>> m_matrix;
	typename vector<vector<T>>::iterator it = m_matrix.begin();
	int row_count;
	int col_count;
public:
	KMatrix() {};
	KMatrix(KMatrix& mat);
	void init(int row_count, int col_count);
	void initpro(MyStruct my) {
		row_count = my.x;
		col_count = my.y;
		m_matrix.resize(row_count);
		for (int i = 0; i < row_count; i++)
		{
			m_matrix[i].resize(row_count);
			for (int j = 0; j < col_count; j++)
				m_matrix[i][j] = my.a[i][j];
		}
		it = m_matrix.begin();
	}
	int getRows() const {
		return row_count;
	};
	int getCols() const {
		return col_count;
	};
	void get() {
		typename vector<vector<T>>::iterator it = m_matrix.begin();
		typename vector<T>::iterator itit = (*it).begin();
		cout << *itit << endl;
	}
	typename vector<vector<T>>::iterator begin() {
		return it;
	}
	typename vector<vector<T>>::iterator end() {
		typename vector<vector<T>>::iterator test = m_matrix.end();
		return test;
	}
	void setData(int row, int col, T value);
	T getData(int row,int col) const;
	void erase_row(int row);
	void erase_col(int col);
	KMatrix operator+(KMatrix& mat);
	void dotMul(const KMatrix&);
	KMatrix transpose(); //交换行列
	void print() const;
public:
	class Iterator
	{
	private:
		typename vector<T>::iterator it;
		typename vector<vector<T>>::iterator its;
	public:
		Iterator(typename vector<vector<T>>::iterator its) { this->its = its; this->it = its->begin(); };
		void operator=(typename vector<vector<T>>::iterator it) {
			this->it = it->begin();
			this->its = it;
		}
		Iterator operator++(int) {
			it++;
			if (it == its->end())
				it = (++its)->begin();
			return *this;
		}
		int operator*() {
			return *it;
		}

		//bool operator==(typename vector<T>::iterator end) {
		//	if(it)
		//}
		bool operator!=(typename vector<vector<T>>::iterator end)
		{
			if (its == end)
				return false;
			else
				return true;
		}
	};
};

template<class T>
inline KMatrix<T>::KMatrix(KMatrix& mat)
{
	row_count = mat.row_count;
	col_count = mat.col_count;
	m_matrix.resize(row_count);
	for (int i = 0; i < row_count; i++)
	{
		m_matrix[i].resize(row_count);
		for (int j = 0; j < col_count; j++)
			m_matrix[i][j] = mat.m_matrix[i][j];
	}
	it = m_matrix.begin();
}

template<class T>
inline void KMatrix<T>::init(int row_count, int col_count)
{
	this->row_count = row_count;
	this->col_count = col_count;
	KMatrix<T>::m_matrix.resize(row_count);
	for (int i = 0; i < row_count; i++)
		KMatrix<T>::m_matrix[i].resize(col_count);
	it = m_matrix.begin();
}

template<class T>
inline void KMatrix<T>::setData(int row, int col, T value)
{
	m_matrix[row][col] = value;
}

template<class T>
inline T KMatrix<T>::getData(int row,int col) const
{
	return m_matrix[row][col];
}

template<class T>
inline void KMatrix<T>::erase_row(int row)
{
	typename vector<vector<T>>::iterator it = m_matrix.begin();
	while (row--)
	{
		it++;
	}
	row_count--;
	m_matrix.erase(it);
}

template<class T>
inline void KMatrix<T>::erase_col(int col)
{
	typename vector<vector<T>>::iterator it = m_matrix.begin();
	typename vector<T>::iterator itit = (*it).begin();
	for (int i = 0; i < col; i++)
	{
		while (col--);
			itit++;
		m_matrix[i].erase(itit);
	}
	col_count--;
}

template<class T>
inline KMatrix<T> KMatrix<T>::operator+(KMatrix& mat)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			m_matrix[i][j] += mat.m_matrix[i][j];
		}
	}//需要体现矩阵的基本结构
	return *this;
}





template<class T>
inline void KMatrix<T>::dotMul(const KMatrix& mat)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			m_matrix[i][j] *= mat.m_matrix[i][j];
		}
	}//需要体现矩阵的基本结构
}

template<class T>
inline KMatrix<T> KMatrix<T>::transpose() //交换行列
{
	T* a=new T[row_count*col_count];
	int k = 0;
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			a[k] = m_matrix[j][i];
			k++;
		}
	}
	k=0;
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			m_matrix[i][j] = a[k];
			k++;
		}
	}
	return *this;
}

template<class T>
inline void KMatrix<T>::print() const
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			cout <<m_matrix[i][j]<<" ";
		}
		cout << endl;
	}//需要体现矩阵的基本结构
}
