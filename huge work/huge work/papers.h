#pragma once
#include "Commodity.h"

class papers :
    public Commodity
{
public:
    bool operator<(papers dri) {
        if (price < dri.getprice())
            return true;
        else
            return false;
    }
    papers() {};
    papers(string name, int id, double price, int num = 1) { this->name = name; this->id = id; this->price = price; this->num = num; }
    ~papers() {};
};


