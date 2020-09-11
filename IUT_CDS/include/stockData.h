#ifndef STOCKDATA_H_INCLUDED
#define STOCKDATA_H_INCLUDED
#include <bits/stdc++.h>
#include "grocery.h"

void clearSCR();

void stockData(grocery g)
{
    //clearSCR();
    system("CLS");
    int y;
    cout<<"\n----------------\nSTOCK DATA\n----------------\n";
    cout<<"1-READ FILE  2-ADD  3-DELETE  4-MODIFY  5-SEARCH  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
    cin>>y;
    while(y!=0)
    {
        switch(y)
        {
             case 1:
                  g.readf();
                  break;
             case 2:
                  g.write();
                  break;
             case 3:
                  g.idelete();
                  break;
             case 4:
                  g.modify();
                  break;
             case 5:
                  g.search();
                  break;
             case 9:
                system("CLS");
                break;
             default:
                  cout<<"\nInvalid Option.";
        }
        clearSCR();
        cout<<"\n----------------\nSTOCK DATA\n----------------\n";
        cout<<"1-READ FILE  2-ADD  3-DELETE  4-MODIFY  5-SEARCH  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
        cin>>y;
        }
}



#endif // STOCKDATA_H_INCLUDED
