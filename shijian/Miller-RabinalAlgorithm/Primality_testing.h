#pragma once
#include"bigmoden.h"
#include<math.h>
class Primality_testing
{
public:
	bigmoden test;
	bool Miller_Rabin(long long x);     //判断素数miller法
	bool commontest(int x);		//普通素性检测
};

