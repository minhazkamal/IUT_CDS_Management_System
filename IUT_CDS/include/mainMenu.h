#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include <bits/stdc++.h>
#include "billingMenu.h"
#include "stockData.h"
#include "stockPurchase.h"
#include "option.h"
#include "profitMenu.h"
#include "ending.h"

void clearSCR();

void mainMenu(char ch)
{
    system("CLS");

    customer c;
    purchase p;
    grocery g;


    if(ch=='a')
    {
        cout<<"\n----------------\nMAIN MENU\n----------------\n";
            cout<<"1-BILLING  2-STOCK PURCHASE  3-STOCK DATA  4-OPTIONS  5-CHECK PROFIT  0-EXIT.\nEnter option: ";
            int x;
            cin>>x;
            if(x==0) ending();
            while(x!=0)
            {
                switch(x)
                {
                case 1:
                    billingMenu(c,g);
                    break;
                case 2:
                    stockPurchase(p,g);
                    break;
                case 3:
                    stockData(g);
                    break;
                case 4:
                    option();
                    break;
                case 5:
                    profitMenu();
                    break;
                default:
                    break;

                }
                //clearSCR();
                system("CLS");
                cout<<"\n----------------\nMAIN MENU\n----------------\n";
                cout<<"1-BILLING  2-STOCK PURCHASE  3-STOCK DATA  4-OPTIONS  5-CHECK PROFIT  0-EXIT.\nEnter option: ";
                cin>>x;
                if(x==0) ending();
            }
    }
    else if(ch=='s')
    {
        cout<<"\n----------------\nMAIN MENU\n----------------\n";
            cout<<"1-BILLING  2-STOCK PURCHASE  3-STOCK DATA  4-CHANGE PASSWORD  0-EXIT.\nEnter option: ";
            int x;
            cin>>x;
            if(x==0) ending();
            while(x!=0)
            {
                switch(x)
                {
                case 1:
                    billingMenu(c,g);
                    break;
                case 2:
                    stockPurchase(p,g);
                    break;
                case 3:
                    stockData(g);
                    break;
                case 4:
                    {
                        staff s;
                        s.changePassword();
                        break;
                    }
                    break;
                default:
                    break;


                }
                clearSCR();
                cout<<"\n----------------\nMAIN MENU\n----------------\n";
                cout<<"1-BILLING  2-STOCK PURCHASE  3-STOCK DATA  4-CHANGE PASSWORD  0-EXIT.\nEnter option: ";
                cin>>x;
                if(x==0) ending();

            }
    }
    else
            cout<<"\nWrong Option\nExiting............\n\n";

}

#endif // MAINMENU_H_INCLUDED
