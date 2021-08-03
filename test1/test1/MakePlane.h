#pragma once

#include"Make.h"
class MakePlane:public Make
{
public:
	void make() {
		std::cout << "我可以制造飞机" << std::endl;
	}
};

