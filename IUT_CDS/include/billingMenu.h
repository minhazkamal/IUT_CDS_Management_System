#ifndef BILLINGMENU_H_INCLUDED
#define BILLINGMENU_H_INCLUDED
#include <bits/stdc++.h>
#include "customer.h"

using namespace std;

void clearSCR();

void billingMenu(customer c, grocery g)
{
    system("CLS");
    cout<<"\n----------------\nBILLING\n----------------\n";
    cout<<"1-START A BILL  2-DISPLAY ALL  3-SEARCH BILL  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
    int y;
    cin>>y;
    while(y!=0)
    {
        switch(y)
        {
            case 1:
                cwrite(c,g);
                break;
            case 2:
                c.readf();
                break;
            case 3:
                searchbill(c,g);
                break;
            case 4:
//                g.search();
//                break;
            case 9:
                system("CLS");
                break;
            default:
                cout<<"\nInvalid Option.";
         }
         clearSCR();
         cout<<"\n----------------\nBILLING\n----------------\n";
         cout<<"1-START A BILL  2-DISPLAY ALL  3-SEARCH BILL  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
         cin>>y;
    }
}



#endif // BILLINGMENU_H_INCLUDED
