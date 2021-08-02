#pragma once

#include"Make.h"
class MakeTrain:public Make
{
public:
	void make()
	{
		std::cout << "我可以制造火车" << std::endl;
	}
};

