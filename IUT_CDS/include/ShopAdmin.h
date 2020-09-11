#ifndef SHOPADMIN_H
#define SHOPADMIN_H

#include "People.h"

using namespace std;


class ShopAdmin:public People
{
public:
    ShopAdmin();
    virtual ~ShopAdmin();
    void write();
    void read();
    void changePassword();
    void writeDefault();


private:

};

#endif // SHOPADMIN_H
