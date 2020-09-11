#ifndef PROFITMENU_H_INCLUDED
#define PROFITMENU_H_INCLUDED
#include "ShopBalance.h"

void clearSCR();

void profitMenu()
{
    system("CLS");
    ifstream fin("User Files\\totalBalance.dat");
    if(!fin)
    {
        fin.close();
        ShopBalance sb;
        sb.writeFirst();
    }
    fin.close();
    cout<<"\n----------------\nCHECK PROFIT\n----------------\n";
    cout<<"1-PROFIT BY DATE  2-PROFIT BY MONTH  3-PROFIT BY YEAR  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
    int x;
    cin>>x;
    while(x!=0)
    {
        switch(x)
        {
            case 1:
                {
                    ShopBalance b;
                    b.profitByDate();
                    break;
                }

            case 2:
                {
                    ShopBalance b;
                    b.profitByMonth();
                    break;
                }
            case 3:
                {
                    ShopBalance b;
                    b.profitByYear();
                    break;
                }

            case 9:
                system("CLS");
                break;
            default:
                break;
        }
        clearSCR();
        cout<<"\n----------------\nCHECK PROFIT\n----------------\n";
        cout<<"1-PROFIT BY DATE  2-PROFIT BY MONTH  3-PROFIT BY YEAR  9-CLEAR  0-BACK TO MAIN MENU.\nEnter option:  ";
        cin>>x;
    }
}


#endif // PROFITMENU_H_INCLUDED
