#include <iostream> 
using namespace std;
class MyInt
{
	int nVal;
public:
	MyInt(int n) { nVal = n; }
	MyInt operator-(int i);// 在此处补充你的代码
	friend int Inc(MyInt MY);
};
int Inc(MyInt MY) {
	return MY.nVal + 1;
}
int main() {
	int n;
	while (cin >> n) {
		MyInt objInt(n);
		MyInt o=objInt - 2 - 1 - 3;
		cout << Inc(o);
		cout << ",";
		MyInt ob=o - 2 - 1;
		cout << Inc(ob) << endl;
		//MyInt objInt(n);
		//objInt - 2 - 1 - 3;
		//cout << Inc(objInt);
		//cout << ",";
		//objInt - 2 - 1;
		//cout << Inc(objInt) << endl;
	}
	return 0;
}

MyInt MyInt::operator-(int i)
{
	nVal -= i;
	return *this;// TODO: 在此处插入 return 语句
}
