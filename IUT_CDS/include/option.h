#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED
#include <bits/stdc++.h>
#include "staff.h"
#include "ShopAdmin.h"

void clearSCR();

void option()
{
    system("CLS");
    cout<<"\n----------------\nOPTIONS\n----------------\n";
    cout<<"1-ADD STAFF 2-DELETE STAFF  3-CHANGE STAFF SALARY  4-SHOW STAFFS  5-CHANGE PASSWORD  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
    int x;
    cin>>x;
    while(x!=0)
    {
        switch(x)
        {
            case 1:
                {
                    staff s;
                    s.write();
                    break;
                }

            case 2:
                {
                    staff s;
                    s.deleteStaff();
                    break;
                }
            case 3:
                {
                    staff s;
                    s.changeSalary();
                    break;
                }
            case 4:
                {
                    staff s;
                    s.read();
                    break;
                }
            case 5:
                {
                    ShopAdmin a;
                    a.changePassword();
                    break;
                }
            case 9:
                system("CLS");
                break;
            default:
                break;
        }
        clearSCR();
        cout<<"\n----------------\nOPTIONS\n----------------\n";
        cout<<"1-ADD STAFF 2-DELETE STAFF  3-CHANGE STAFF SALARY  4-SHOW STAFFS  5-CHANGE PASSWORD  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
        cin>>x;
    }
    //if(x==0) system("CLS");
}



#endif // OPTION_H_INCLUDED
