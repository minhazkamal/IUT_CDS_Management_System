#ifndef STOCKPURCHASE_H_INCLUDED
#define STOCKPURCHASE_H_INCLUDED
#include <bits/stdc++.h>
#include "purchase.h"
#include "grocery.h"

void clearSCR();

void stockPurchase(purchase p, grocery g)
{
    system("CLS");
    int y;
    cout<<"\n----------------\nSTOCK PURCHASE\n----------------\n";
    cout<<"1-PURCHASE STOCK  2-DISPLAY ALL  3-SEARCH PURCHASE ORDER  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
    cin>>y;
    while(y!=0)
    {
        switch(y)
        {
             case 1:
                  pwrite(p,g);
                  break;
             case 2:
                  p.readf();
                  break;
             case 3:
                p.search();
                break;
//             case 4:
//                g.search();
//                break;
             case 9:
                system("CLS");
                break;
             default:
                  cout<<"\nInvalid Option.";
        }
        clearSCR();
    cout<<"\n----------------\nSTOCK PURCHASE\n----------------\n";
    cout<<"1-PURCHASE STOCK  2-DISPLAY ALL  3-SEARCH PURCHASE ORDER  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
    cin>>y;
    }
}



#endif // STOCKPURCHASE_H_INCLUDED
