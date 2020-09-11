#include<bits/stdc++.h>
#include "customer.h"
#include "grocery.h"
#include "Date.h"

using namespace std;

customer::customer():grocery()
{
    customerid=0;
    strcpy(customername," ");
    strcpy(cdate," ");
    cost=0;
    quant=0;
    bid=0;
}

customer::~customer()
{
    //dtor
}

void customer::disp()
{
    cout<<"\n"<<left<<"  "<<bid<<"\t"<<rno<<"\t"<<iname<<setw(10)<<"\t"<<setw(20)<<customername<<customerid<<"\t   "<<setw(7)<<quant<<"\t"<<setw(6)<<cost<<"\t"<<setw(5)<<quant*cost<<"\t"<<cdate;
}

int customer::lastbid()
{

    ifstream fin("User Files\\customer.dat");
    customer p;
    fin.read((char*)&p,sizeof(customer));
    int c=0;
    while(fin.eof()==0)
    {
        fin.read((char*)&p,sizeof(customer));
        c++;
    }
    fin.seekg((c-1)*sizeof(customer));
    fin.read((char*)&p,sizeof(customer));

    return p.bid;

}

int customer::lastr()
{
    ifstream fin("User Files\\customer.dat");
    customer p;
    fin.read((char*)&p,sizeof(customer));
    int c=0;
    while(fin.eof()==0)
    {
        c++;
        fin.read((char*)&p,sizeof(customer));
    }
    return c;
}

void customer::modifyrecord()
{
//cin.ignore();	cout<<"\ncustomeromer Name    : ";cin.getline(customername,20);
    //cout<<"customeromer ID     : ";cin>>customerid;
    //cout<<"Purchase Date       : ";cin>>cdate;
    cout<<"Quantity buying   :";
    cin>>quant;
    //cout<<"Cost Price       :";cin>>cost;


}

void customer::readf()
{
    int count=0;
    ifstream fin("User Files\\customer.dat");
    if(!fin)
    {
        cout<<"File could not be opened.";
        //writeempty();
        cout<<"File written for FIRST TIME.\n";
        return;
    }
    customer temp;
    cout<<"\nBillNo. RNo.    Item Name       Customer Name     CustomerID    Quantity       Cost    Total      Date\n";

    fin.read((char *)&temp,sizeof(customer));

    while(fin.eof()==0)
    {
        temp.disp();
        count++;
        fin.read((char *)&temp,sizeof(customer));
    }
    cout<<"\n--> "<<count<<" record(s) found.\n";
    fin.close();

}

void customer::writeempty()
{
    ifstream fin("User Files\\customer.dat");
    if(!fin)
    {
       fin.close();
       ofstream fout("User Files\\customer.dat");
        for(int i=0; i<2600; i++)
        fout.write((char *)this,sizeof(customer));

        fout.close();
    }
    fin.close();
}

