#ifndef PURCHASE_H
#define PURCHASE_H


#include "grocery.h"

class grocery;

class purchase : public grocery
{
    public:
        purchase();
        virtual ~purchase();
        void disp();
//        void input();
        friend void pwrite(purchase p,grocery g);
        void modify();
        void modifyrecord();
        void writeempty();
        void readf();
//        int recno(char *);
//        void idelete();
        void search();
        int lastr();
        void modifyrecord_pw();
        friend class ShopBalance;


    protected:
        int sellid;
        char sellname[20];
        char bdate[10];
        float quantity;

    private:
};

#endif // PURCHASE_H
