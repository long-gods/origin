#pragma once
#include "Factory.h"
class trainfactory :
    public Factory
{
public:
	Make* create_product(std::string something)
	{
		return new MakeTrain;
	}
};

