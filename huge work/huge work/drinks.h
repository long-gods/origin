#pragma once
#include "Commodity.h"

class drinks :
    public Commodity
{
public:
    bool operator<(Commodity* com) {
        if (price < *com.getprice()) 
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
    void newprice(double newp);
    void newdescribe(string newd);

};