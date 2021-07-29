#pragma once
#include "Commodity.h"

class drinks :
    public Commodity
{
public:
    bool operator<(drinks dri) {
        if (price < dri.getprice())
            return true;
        else
            return false;
    }
    bool operator>(drinks dri) {
        if (price >dri.getprice())
            return true;
        else
            return false;
    }
    drinks() {};
    drinks(string name, int id, double price,int num=1) { this->name = name; this->id = id; this->price = price; this->num=num; }
    ~drinks() {};
};
