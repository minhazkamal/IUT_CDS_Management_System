#ifndef SHOPBALANCE_H
#define SHOPBALANCE_H
#include<bits/stdc++.h>

using namespace std;

class customer;
class purchase;

class ShopBalance
{
public:
    ShopBalance();
    virtual ~ShopBalance();
    void writeSellingPrice(double, char*);
    void writeBuyingPrice(double, char*);
    void writeFirst();
    void display(string s);
    void setProfit();
    bool checkDate(char *d);
    void profitByDate();
    void profitByMonth();
    void profitByYear();
    string extractMonth(string s);

protected:
    double sellingCost;
    double buyingCost;
    double profit;
    char date[10];
};

#endif // SHOPBALANCE_H
