#pragma once
#include<vector>

template<class T>
class KMatrix
{
private:
	vector<vector<T>> Col;
public:
	void init(int row_count, int col_count);

};

template<class T>
inline void KMatrix<T>::init(int row_count, int col_count)
{
	col = new vector<T>[row_count];
	for (int i = 0; i < row_cout; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			Col[i]
			cout << Col[i][j];
		}
		cout << endl;
	}
}
