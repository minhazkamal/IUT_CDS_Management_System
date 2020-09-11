#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <grocery.h>


class customer : public grocery
{
    public:
        customer();
        virtual ~customer();
        void disp();
        void input();
        //void modify();
        void modifyrecord();
        void writeempty();
        void readf();
        //int recno(char *);
        //void idelete();
        //void search();
        int lastr();
        friend void cwrite(customer c,grocery g);
        friend void searchbill(customer c,grocery g);
        int lastbid();
        friend class ShopBalance;


    protected:
        int bid;
        int customerid;
        char customername[20];
        char cdate[10];

    private:
};

#endif // CUSTOMER_H
