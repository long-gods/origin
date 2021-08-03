#pragma once
#include"MakePlane.h"
#include"MakeTrain.h"
class Factory
{
private:
	static Make* m;
public:
	virtual Make* create_product(std::string something) = 0;
};
