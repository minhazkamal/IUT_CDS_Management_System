#ifndef SEARCHBILL_H_INCLUDED
#define SEARCHBILL_H_INCLUDED
#include <bits/stdc++.h>
#include "customer.h"
#include "grocery.h"

using namespace std;

void searchbill(customer c1,grocery g)
{
    ifstream fout("User Files\\customer.dat",ios::in);
    cout<<"\nEnter Bill Number to be searched : ";
    int bno;
    cin>>bno;


    fout.seekg(0);
    fout.read((char*)&c1,sizeof(customer));
    int i=1,sum=0;
    while(fout.eof()==0)
    {
        if(c1.bid==bno)
        {
            if(i==1)
            {
                cout<<"_________________________________________________________________________\n\t\t\tIUT CDS \n_________________________________________________________________________\n";
                cout<<"Bill Number :"<<setw(4)<<c1.bid<<setfill(' ')<<"\tCustomer ID :"<<c1.customerid<<"\tCustomer Name:"<<c1.customername<<"\n"<<"Date of Purchase :"<<c1.cdate<<"\n";
                cout<<"_______________________________________________________________________\n";
                cout<<"\nS.No.     ItemCode    Item Name     Cost(per)    Quantity    Cost\n-------------------------------------------------------------------------\n";

            }
            sum+=c1.quant*c1.cost;
            cout<<right<<setw(5)<<i<<setw(10)<<c1.rno<<setw(15)<<c1.iname<<setw(15)<<c1.cost<<setw(10)<<c1.quant<<setw(10)<<c1.quant*c1.cost<<"\n";
            i++;
        }
        fout.read((char*)&c1,sizeof(customer));
    }
    if(i!=1)
    {
        cout<<"\n-------------------------------------------------------------------------\n";
        cout<<"Total Cost :\t\t\t\t\t\t   "<<sum;
        cout<<"\n-------------------------------------------------------------------------\n";
    }
    if(i==1)
    {
        cout<<"\nSorry Bill doesn't exist.\n";
    }


}


#endif // SEARCHBILL_H_INCLUDED
