#pragma once
#include"bigmoden.h"
#include<math.h>
class Primality_testing
{
public:
	bigmoden test;
	bool Miller_Rabin(long long x);     //�ж�����miller��
	bool commontest(int x);		//��ͨ���Լ��
};

