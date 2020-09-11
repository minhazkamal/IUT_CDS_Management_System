#include<bits/stdc++.h>
#include<conio.h>
#include "People.h"

using namespace std;

People::People()
{
    strcpy(userName,"");
    pass=0;
}

People::~People()
{
    //dtor
}

void People::setUsername(char *n)
{
    strcpy(userName,n);
}

void People::setPassword(int d)
{
    pass=d;
}

void People::setPassword()
{
    cout<<"Enter Password: ";
    string pass_string="";
    int i = 0;
    char a;
    for(i=0;;)
    {
        a=getch();
        if(a>='0'&&a<='9')
        {
            pass_string+=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass_string+='\0';
            break;
        }
    }
    //cout<<"\nYou entered : "<<pass_string;

    if(i>5||i<4)
    {
        cout<<"\nPassword must be maximum of 6 and minimum of 4 digit.\nEnter Again(Y/N)";
        char d = getch();
        if(d=='Y'||d=='y') setPassword();
    }

    pass=stoi(pass_string);
    //cin>>pass;
}

void People::setUsername()
{
    cout<<"Enter Username: ";
    cin>>userName;
}

string People::getUsername()
{
    return userName;
}

int People::getPassword()
{
    return pass;
}

