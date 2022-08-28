#undef UNICODE



#include <windows.h>

#include<iostream>

int main(void)
{
	HINSTANCE hDllInst;
	hDllInst = LoadLibrary("DLL2.dll"); //调用DLL
	typedef int(*PLUSFUNC)(); //后边为参数，前面为返回值
	PLUSFUNC plus_str = (PLUSFUNC)GetProcAddress(hDllInst, "test"); //GetProcAddress为获取该函数的地址
	std::cout << plus_str();
}