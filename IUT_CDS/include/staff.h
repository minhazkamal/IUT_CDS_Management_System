#ifndef STAFF_H
#define STAFF_H

#include<bits/stdc++.h>
#include "People.h"

using namespace std;


class staff:public People
{
    public:
        staff();
        virtual ~staff();
        void write();
        void read();
        void setSalary();
        double getSalary();
        void changePassword();
        void deleteStaff();
        void changeSalary();
        int searchStaff(string name,int pass);

    protected:
        double salary;

    private:
};

#endif // STAFF_H
