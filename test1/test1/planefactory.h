#pragma once
#include"Factory.h"
class planefactory:public Factory
{
public:
	Make* create_product(std::string something)
	{
		return new MakePlane;
	}
};

