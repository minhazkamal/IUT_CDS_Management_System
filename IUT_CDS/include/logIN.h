#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include "staff.h"
#include<bits/stdc++.h>
#include<conio.h>
#include "people.h"
#include "mainMenu.h"
#include "ShopAdmin.h"

void clearSCR();

using namespace std;

void logIN()
{
    system("CLS");
    cout<<"----------------------------------------------------\n\t  IUT CDS MANAGEMENT SYSTEM\n----------------------------------------------------";
    cout<<"\nADMINISTRATOR(A) or STAFF(S)   :";
    char ch;
    cin>>ch;
    char uname[20];
    int pass;
    if(ch=='a'||ch=='A')
    {
        cout<<"\nUsername     :";
        cin>>uname;
        cout<<"Password     :";
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

//        if(i>5||i<0)
//        {
//            cout<<"\nPassword must be 6 digit.\n";//\nEnter Again(Y/N)";
////            char d = getch();
////            if(d=='Y'||d=='y') setPassword();
//        }

        pass=stoi(pass_string);
        //cin>>pass;
        ShopAdmin temp;
        ifstream f("User Files\\Admin.dat");
        f.read((char*)&temp,sizeof(temp));
        f.close();

        if((uname==temp.getUsername())&&(pass==temp.getPassword()))
        {
            cout<<"\nAccess Granted.\n";
            clearSCR();
            mainMenu('a');
        }
        else
        {
            cout<<"\nInvalid Username/Password\n";
            clearSCR();
        }
    }
    else if(ch=='s'||ch=='S')
    {
        staff st;
        int s;
        char uname[20];
        int pass;
        cout<<"Username   :";
        cin>>uname;
        cout<<"Password   :";
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

//        if(i>5||i<0)
//        {
//            cout<<"\nPassword must be 6 digit.";//\nEnter Again(Y/N)";
////            char d = getch();
////            if(d=='Y'||d=='y') setPassword();
//        }

        pass=stoi(pass_string);
        //cin>>pass;
        s=st.searchStaff(uname, pass);
        if(s==1)
        {
            cout<<"\nAccess Granted.\n";
            clearSCR();
            mainMenu('s');
        }
        else
        {
            cout<<"\nInvalid Username/Password\n";
            clearSCR();
        }
    }
    else
        cout<<"\nWrong Option\nExiting............\n\n";


}

#endif // LOGIN_H_INCLUDED
