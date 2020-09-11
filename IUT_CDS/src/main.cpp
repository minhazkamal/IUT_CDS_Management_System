#define ll cout<<"1\n";

#include<bits/stdc++.h>
#include<windows.h>
#include "logIN.h"
#include "ShopAdmin.h"
#include "ShopBalance.h"
#include "staff.h"
#include "purchaseWrite.h"
#include "customerWrite.h"
#include "searchBill.h"
#include "welcome.h"
#include "clearScreen.h"


using namespace std;

void welcome();

int main()
{
//    purchase p;
//    grocery g;
//    pwrite(p,g);
//    ShopBalance b;
//    b.writeFirst();
//    b.profitByDate();

//  ShopAdmin A;
//   A.write();
//    A.changePassword();
//   A.read();
//    staff s;
//    s.write();
//    s.write();
//    s.read();
    if(CreateDirectory("User Files",NULL))
    {
            ShopAdmin ad;
            ad.writeDefault();
    }
    welcome();
    logIN();
//    char d[10];
//    calculateDate(d);
//    cout<<d;
}




