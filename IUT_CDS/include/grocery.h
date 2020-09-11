#ifndef GROCERY_H
#define GROCERY_H


class purchase;
class customer;

class grocery
{
    public:
        grocery();
        virtual ~grocery();
        void disp();
        void input();
        void write();
        void modify();
        void modifyrecord();
        void writeempty();
        void readf();
        int recno(char *);
        void idelete();
        void search();
        grocery itemSearch(char *);

        friend void pwrite(purchase p,grocery g);
        friend void cwrite(customer c,grocery g);
        friend void searchbill(customer c,grocery g);

    protected:
        char rno[4];
        char iname[20];
        int quant;
        float cost;
        char status;
        int quantl;
    private:
};

#endif // GROCERY_H
