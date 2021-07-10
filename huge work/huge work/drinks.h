#pragma once
#include "Commodity.h"
#include<iostream>
class drinks :
    public Commodity
{
public:
    bool operator<(drinks drink) {
        if (price < drink.price)
            return true;
        else
            return false;
    }
    drinks(string name, int id, double price) { this->name = name; this->id = id; this->price = price; this->num++; }
    string getname() { return name; }
    int getid() { return id; }
    double getprice() { return price; }
    int getnum() { return num; }
    void addnum() { num++; }
    void addname(string name){}
    friend ostream& operator<<(ostream& out, drinks* dri);
};