#include<bits/stdc++.h>
#include "purchase.h"
#include "grocery.h"
#include "Date.h"

using namespace std;

purchase::purchase():grocery()
{
    sellid=0;
    strcpy(sellname," ");
    strcpy(bdate," ");
    cost=0;
    quant=0;
}

purchase::~purchase()
{
    //dtor
}

void purchase::disp()
{
    cout<<"\n"<<left<<"  "<<setw(15)<<rno<<setw(20)<<iname<<setw(15)<<sellname<<setw(15)<<sellid<<setw(15)<<quant<<setw(13)<<cost<<setw(10)<<quant*cost<<setw(10)<<bdate;
//    if(status=='a'||status=='A')
//        cout<<setw(10)<<"Active";
//    if(status=='u'||status=='U')
//        cout<<setw(10)<<"Inactive";
//
//    cout<<"\n"<<rno<<"\t\t"<<iname<<"\t"<<sellname<<"\t"<<sellid<<"\t"<<quant<<"\t\t"<<cost<<"\t"<<status<<"\t"<<bdate;
}

void purchase::writeempty()
{
    ifstream fin("User Files\\purchase.dat");
    if(!fin)
    {
       fin.close();
       ofstream fout("User Files\\purchase.dat");
        for(int i=0; i<2600; i++)
        fout.write((char *)this,sizeof(purchase));

        fout.close();
    }
    fin.close();
}

int purchase::lastr()
{
    ifstream fin("User Files\\purchase.dat");
    purchase p;
    fin.read((char*)&p,sizeof(purchase));
    int c=0;
    while(fin.eof()==0)
    {
        fin.read((char*)&p,sizeof(purchase));
        c++;
    }
    return c;
}

void purchase::modifyrecord()
{
    cin.ignore();
    cout<<"\nSeller Name    : ";
    cin.getline(sellname,20);
    cout<<"Seller ID     : ";
    cin>>sellid;
    cout<<"Bought Date         : ";
    Date d;
    d.calculateDate(bdate); cout<<bdate;
    cout<<"\nQuantity bought   :";
    cin>>quant;
    cout<<"Buying Cost Price       :";
    cin>>cost;
}

void purchase::modifyrecord_pw()
{
    cin.ignore();
    cout<<"\nSeller Name    : ";
    cin.getline(sellname,20);
    cout<<"Seller ID     : ";
    cin>>sellid;
    cout<<"Bought Date         : ";
    Date d;
    d.calculateDate(bdate); cout<<bdate;
    cout<<"\nBuying Cost Price       :";
    cin>>cost;
}

void purchase::readf()
{
    int count=0;
    ifstream fin("User Files\\purchase.dat",ios::app);
    if(!fin)
    {
        cout<<"File could not be opened.";
        //writeempty();
        cout<<"File written for FIRST TIME.\n";
    }
    purchase temp;

    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Record No.\tItem name\t  Seller Name\t  SellID\tQuantity\t Cost\t Total Price\t   Date";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
    fin.read((char *)&temp,sizeof(purchase));

    while(fin.eof()==0)
    {
        temp.disp();
        count++;
        fin.read((char *)&temp,sizeof(purchase));
    }
    cout<<"\n--> "<<count<<" record(s) found.\n";
    fin.close();

}

void purchase::search()
{
    int cnt=0,flag=0,p;
    purchase temp;
    cout<<"Enter the purchase order no. to search: ";
    cin>>p;
    ifstream fin("User Files\\purchase.dat");
    if(!fin)
    {
        cout<<"File could not be opened.";
        return;
    }
    fin.read((char *)&temp,sizeof(purchase));
        while(fin.eof()==0)
        {
            cnt++;
            if(cnt==p)
            {
                flag=1;
                cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------\n";
                cout<<"Record No.\tItem name\t  Seller Name\t  SellID\tQuantity\t Cost\t Total Price\t   Date";
                cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
                temp.disp();
            }
            fin.read((char *)&temp,sizeof(purchase));
        }
        fin.close();
        if(flag==0) cout<<"The purchase does not exist\n";
}

