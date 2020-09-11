#ifndef PEOPLE_H
#define PEOPLE_H

#include<bits/stdc++.h>

using namespace std;

class People
{
    public:
        People();
        People(char*, int);
        ~People();
        virtual void write()=0;
        virtual void read()=0;
        void setUsername();
        string getUsername();
        void setPassword();
        int getPassword();
        void setUsername(char *);
        void setPassword(int);
        virtual void changePassword()=0;

    protected:
        char userName[20];
        int pass;


    private:
};

#endif // PEOPLE_H
