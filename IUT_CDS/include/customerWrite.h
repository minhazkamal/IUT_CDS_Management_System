#ifndef CUSTOMERWRITE_H_INCLUDED
#define CUSTOMERWRITE_H_INCLUDED
#include <bits/stdc++.h>
#include "grocery.h"
#include "customer.h"
#include "Date.h"


using namespace std;

void cwrite(customer c,grocery g)
{
//    cout<<"\n\t1 - SEARCH ITEM";
//    cout<<"\n\t0 - CONTINUE";
//    cout<<"\nENTER 1 or 0 - ";
//    int check;
//    cin>>check;
//    if(check==1) g.search();
//
//    cout<<endl;

    fstream fout("User Files\\customer.dat",ios::app);
    c.bid=c.lastbid()+1;

    cout<<"Bill No."<<c.bid;
//	cout<<"\n"<<c.lastr()<<"\n";
    cin.ignore();
    cout<<"\nCustomer Name    : ";
    cin.getline(c.customername,20);
    cout<<"Customer ID     : ";
    cin>>c.customerid;
    cout<<"Purchase Date       : ";
    Date d;
    d.calculateDate(c.cdate); cout<<c.cdate<<endl;
//    cin>>c.cdate;
    int bopt=1;
    fout.seekp((c.lastr())*sizeof(customer));
    while(bopt==1)
    {

        cout<<"\n\t1 - SEARCH ITEM";
        cout<<"\n\t0 - CONTINUE";
        cout<<"\nENTER 1 or 0 - ";
        int check;
        cin>>check;
        if(check==1) g.search();

        cout<<endl;

        ifstream fout2("User Files\\stock2.dat",ios::in);
        fstream fin("User Files\\temp.dat",ios::app);
        cout<<"\nRecord Number: ";
        cin>>c.rno;
        grocery temp;
        temp=temp.itemSearch(c.rno);
        if(strcmp(temp.rno,"000"))   //if equal 0,else 1
        {
            c.modifyrecord();
            //cout<<"C Quant= "<<c.quant<<" G Quant= "<<g.quant<<endl;
            int qtc=c.quant;
            int qtg=temp.quant;
            if(qtc<=qtg)
            {
                strcpy(c.rno,temp.rno);
                strcpy(c.iname,temp.iname);
                c.cost=temp.cost;
                fout.write((char*)&c,sizeof(customer));
                temp.quant-=c.quant;
                if(temp.quant<temp.quantl)
                    temp.status='u';
//                fout2.read((char*)&g,sizeof(grocery));
                while(fout2.read((char*)&g,sizeof(grocery)))
                {
                    if(strcmp(temp.rno,g.rno)) fin.write((char*)&g,sizeof(grocery));
                }
                fin.write((char*)&temp,sizeof(customer));
                fin.close();
                fout2.close();
                remove("User Files\\stock2.dat");
                rename("User Files\\temp.dat","User Files\\stock2.dat");

            }
            else
            {
                cout<<"\nThe quantity required is not there..\n";
            }


        }
        else
        {
            cout<<"\nRecord is missing .Cannot bill\n";
//            strcpy(g.rno,c.rno);
        }

//        fout2.seekg((g.recno(c.rno))*sizeof(grocery));
//        fout2.read((char*)&g,sizeof(grocery));
////        cout<<g.rno<<endl;
////        g.disp();
//        if(strcmp(g.rno,"000"))   //if equal 0,else 1
//        {
//            c.modifyrecord();
//            cout<<"C Quant= "<<c.quant<<" G Quant= "<<g.quant<<endl;
//            int qtc=c.quant;
//            int qtg=g.quant;
//            if(qtc<=qtg)
//            {
//                strcpy(c.rno,g.rno);
//                strcpy(c.iname,g.iname);
//                c.cost=g.cost;
//                fout.write((char*)&c,sizeof(customer));
//                g.quant-=c.quant;
//                if(g.quant<g.quantl)
//                    g.status='u';
//                fout2.seekp(g.recno(g.rno)*sizeof(grocery));
//                fout2.write((char*)&g,sizeof(grocery));
//            }
//            else
//            {
//                cout<<"\nThe quantity required is not there..\n";
//            }
//        }
//        else
//        {
//            cout<<"\nRecord is missing .Cannot bill\n";
//            strcpy(g.rno,c.rno);
//        }

        cout<<"Enter 1-Continue Billing or 0-Calculate Total\n";
        cin>>bopt;
    }
    fout.close();
    ifstream fout1("User Files\\customer.dat",ios::in);
    cout<<"_________________________________________________________________________\n\t\t\tIUT CDS\n_________________________________________________________________________\n";
    cout<<"Bill Number :"<<setw(4)<<c.bid<<setfill(' ')<<"\tCustomer ID :"<<c.customerid<<"\tCustomer Name:"<<c.customername<<"\n"<<"Date of Purchase :"<<c.cdate<<"\n";
    cout<<"_______________________________________________________________________\n";
    fout.seekg(0);
    customer c1;
    fout1.read((char*)&c1,sizeof(customer));
    int i=1;
    float sum=0;
    cout<<"\nS.No.     ItemCode    Item Name     Cost(per)    Quantity    Cost\n-------------------------------------------------------------------------\n";
    while(fout1.eof()==0)
    {
        if(c1.bid==c.bid)
        {
            sum+=float(c1.quant)*c1.cost;
            cout<<right<<setw(5)<<i<<setw(10)<<c1.rno<<setw(15)<<c1.iname<<setw(15)<<c1.cost<<setw(10)<<c1.quant<<setw(10)<<c1.quant*c1.cost<<"\n";
            i++;
        }
        fout1.read((char*)&c1,sizeof(customer));
    }
    cout<<"\n-------------------------------------------------------------------------\n";
    cout<<"Total Cost :\t\t\t\t\t\t\t"<<sum;
    cout<<"\n-------------------------------------------------------------------------\n";
    cout<<"Thank You for purchasing from IUT CDS. Welcome again !!!!!!\n";
    fout1.close();
    ShopBalance b;
    b.writeSellingPrice(sum, c.cdate);
}



#endif // CUSTOMERWRITE_H_INCLUDED
