#ifndef PURCHASEWRITE_H_INCLUDED
#define PURCHASEWRITE_H_INCLUDED
#include <bits/stdc++.h>
#include "purchase.h"
#include "grocery.h"
#include "Date.h"
#include "ShopBalance.h"

using namespace std;

void pwrite(purchase p,grocery g)
{
    cout<<"\n\t1 - SEARCH ITEM";
    cout<<"\n\t0 - CONTINUE";
    cout<<"\nENTER 1 or 0 - ";
    int check;
    cin>>check;
    if(check==1) g.search();

    cout<<endl;

    int flag=0;
    fstream fout("User Files\\purchase.dat",ios::app);
    //fstream fout2("stock2.dat",ios::app);

    cout<<"\nPurchase Order # "<<setw(5)<<p.lastr()+1<<"\n"<<setfill(' ');;

    cout<<"\nRecord Number: ";
    cin>>p.rno;

//    fout2.seekg((g.recno(p.rno))*sizeof(grocery),ios::beg);
//    fout2.read((char*)&g,sizeof(grocery));
    grocery temp;
    temp=g.itemSearch(p.rno);

    if(strcmp(temp.rno,"000"))
    {
        p.modifyrecord();
        strcpy(p.iname,temp.iname);
    }
    else
    {
        flag=1;
        cout<<"\nData is absent.Add this a new record to stock database."<<endl;
        strcpy(temp.rno,p.rno);

        temp.input();
        //cout<<"Temp Cost: "<<temp.cost<<" Temp Quant: "<<temp.quant<<endl;
        if(temp.cost>0&&temp.quant>=0)
        {
            strcpy(p.rno,temp.rno);
            strcpy(p.iname,temp.iname);
            p.modifyrecord_pw();
        }
        else
        {
            cout<<"\nStock Quantity or/and Cost is(are) incorrect.Record NOT added.\n";
        }
    }
    //cout<<"Temp Cost: "<<temp.cost<<" Temp Quant: "<<temp.quant<<endl;
    if(flag==1) p.quant=temp.quant;
    if(p.quant>0&&p.cost>0&&temp.cost>0&&temp.quant>=0)
    {
        fout.seekp(p.lastr()*sizeof(purchase));
        fout.write((char *)&p,sizeof(purchase));
        float x=p.cost*p.quant;
//totalbaladd(x);
        if(flag!=1) temp.quant+=p.quant;

        ifstream fout2("User Files\\stock2.dat",ios::in);
        fstream fin("User Files\\temp.dat",ios::app);

        while(fout2.read((char*)&g,sizeof(grocery)))
        {
            if(strcmp(temp.rno,g.rno)) fin.write((char*)&g,sizeof(grocery));
        }
        fin.write((char*)&temp,sizeof(grocery));
        fin.close();
        fout2.close();
        remove("User Files\\stock2.dat");
        rename("User Files\\temp.dat","User Files\\stock2.dat");
        cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"Record No.\tItem name\t  Seller Name\t  SellID\tQuantity\t Cost\t Total Price\t   Date";
        cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
        p.disp();
        cout<<"\n\nItem Purchased Successfully\n";
        ShopBalance b;
        b.writeBuyingPrice(x, p.bdate);
//        fout2.seekp(g.recno(g.rno)*sizeof(grocery),ios::beg);
//        fout2.write((char*)&g,sizeof(grocery));
    }
    else
    {
        cout<<"\nPurchase Quantity or/and Cost is(are) incorrect.Record NOT added.\n";
    }
    fout.close();
}




#endif // PURCHASEWRITE_H_INCLUDED
