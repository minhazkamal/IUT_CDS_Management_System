#include<bits/stdc++.h>
#include "grocery.h"
#include "Date.h"

using namespace std;

grocery::grocery()
{
    strcpy(rno,"000");
    strcpy(iname,"00");

    quant=0;
    cost=0;
    status='i';
    quantl=0;
}

grocery::~grocery()
{
    //dtor
}

void grocery::disp()
{
    cout<<"\n"<<left<<"  "<<setw(15)<<rno<<setw(20)<<iname<<setw(10)<<quant<<setw(10)<<cost;
    if(status=='a'||status=='A')
        cout<<setw(10)<<"Active";
    if(status=='u'||status=='U')
        cout<<setw(10)<<"Inactive";

}

void grocery::idelete()
{
    char record[4];
    int flag=0;
    fstream fout("User Files\\temp.dat",ios::app);
    ifstream fin("User Files\\stock2.dat");
    cout<<"\nEnter the record to be deleted:  ";
    cin>>record;
    while(fin.read((char *)this,sizeof(grocery)))
    {
        if(strcmp(this->rno,record)==0)
        {
            flag=1;
        }
        else
        {
            fout.write((char *)this,sizeof(grocery));
        }
    }

    fin.close();
    fout.close();

    if(flag==0) cout<<"Item doesn't exist\n";
    else if(flag==1) cout<<"Item has been deleted successfully\n";

    remove("User Files\\stock2.dat");
    rename("User Files\\temp.dat","User Files\\stock2.dat");
}

void grocery::input()
{
    cin.ignore();
    cout<<"\nItem Name               : ";
    cin.getline(iname,20);
    cout<<"Quantity(kg/lt/pieces)  : ";
    cin>>quant;
    cout<<"Selling Cost (kg/lt/pieces)  : ";
    cin>>cost;
    cout<<"Quantity Limit          : ";
    cin>>quantl;
    if(quantl<=quant)
        status='a';
    else
        status='u';

}


void grocery::modify()
{
    char record[4];
    int flag=0;
    fstream fout("User Files\\temp.dat",ios::app);
    ifstream fin("User Files\\stock2.dat");
    cout<<"\nEnter the record to be modify:  ";
    cin>>record;
    while(fin.read((char *)this,sizeof(grocery)))
    {
        if(strcmp(this->rno,record)==0)
        {
//            grocery o;
            modifyrecord();
            flag=1;
            fout.write((char *)this,sizeof(grocery));
        }
        else
        {
            fout.write((char *)this,sizeof(grocery));
        }
    }

    fin.close();
    fout.close();

    if(flag==0) cout<<"Item doesn't exist\n";
    else if(flag==1) cout<<"Item has been modified successfully\n";

    remove("User Files\\stock2.dat");
    rename("User Files\\temp.dat","User Files\\stock2.dat");

}


void grocery::modifyrecord()
{
    cin.ignore();
    cout<<"\nItem Name             : ";
    //cin.getline(iname,20);
    cout<<iname<<endl;
    cout<<"Quantity(kg/lt/pieces): ";
    cin>>quant;
    cout<<"Selling Cost(kg/lt/pieces)    : ";
    cin>>cost;
    cout<<"Quantity Limit          : ";
    cin>>quantl;
    if(quantl<=quant)
        status='a';
    else
        status='u';
}

void grocery::readf()
{
    int count=0;
    ifstream fin("User Files\\stock2.dat");
    if(!fin)
    {
        cout<<"File could not be opened.";
        writeempty();
        cout<<"File written for FIRST TIME.\n";
        return;
    }
    grocery temp;
    cout<<"\n\n-------------------------------------------------------------------------------\n";
    cout<<"Record No.\tItem name\t  Quantity    Cost\t  Status";
    cout<<"\n-------------------------------------------------------------------------------\n";
//    fin.read((char *)&temp,sizeof(grocery));

    while(fin.read((char *)&temp,sizeof(grocery)))
    {
        if(strcmp(temp.rno,"000"))
        {
            temp.disp();
            count++;
        }
        //fin.read((char *)&temp,sizeof(grocery));
    }
    cout<<"\n--> "<<count<<" record(s) found.\n";

    ifstream fin1("User Files\\stock2.dat");
    fin1.seekg(0);
    int count1=0;
    fin1.read((char*)&temp,sizeof(grocery));
    while(fin1.eof()==0)
    {

        if(temp.status=='u'||temp.status=='U')
        {
            if(count1==0)
                cout<<"The Quantity of following records are insufficient and status are set to INACTIVE ,please purchase.\n";
            temp.disp();
            count1++;
        }
        fin1.read((char*)&temp,sizeof(grocery));
    }


    fin.close();
    fin1.close();

}

int  grocery::recno(char *ptr)
{
    int c=ptr[0],first=ptr[1],second=ptr[2];
    c=tolower(c);
    int sum=((c-97)*100)+((first-48)*10)+(second-48);
    return sum;

}

void grocery::search()
{
    int count=0;
    ifstream fin("User Files\\stock2.dat");
    if(!fin)
        cout<<"File could not be opened.";
    grocery temp;
    grocery search;
    char c;
    cin.get(c);
    cout<<"Search Criteria :1-Record No. 2-Item Name  3-Quantity   4-Selling Cost  5-Status\nEnter option : ";
    cin.get(c);
    switch(c)
    {

    case '\n':
    case '1':
        cout<<"Enter Record No. to be searched: ";
        cin>>search.rno;
        fin.read((char *)&temp,sizeof(grocery));
        while(fin.eof()==0)
        {
            if(recno(temp.rno)==recno(search.rno))
            {
                if(count==0)
                    cout<<"\n\n-------------------------------------------------------------------------------\n";
                cout<<"Record No.\tItem name\t  Quantity    Cost\t  Status";
                cout<<"\n-------------------------------------------------------------------------------\n";
                count++;
                temp.disp();
            }
            fin.read((char *)&temp,sizeof(grocery));
        }
        if(count==0)
            cout<<"\nSorry,Data doesn't exist.";
        break;


    case '2':
        cout<<"Enter Item Name. to be searched: ";
        cin>>search.iname;
        fin.read((char *)&temp,sizeof(grocery));
        while(fin.eof()==0)
        {
            if(!strcmp(temp.iname,search.iname))
            {
                if(count==0)
                {
                    cout<<"\n\n-------------------------------------------------------------------------------\n";
                    cout<<"Record No.\tItem name\t  Quantity    Cost\t  Status";
                    cout<<"\n-------------------------------------------------------------------------------\n";
                }
                count++;
                temp.disp();
            }
            fin.read((char *)&temp,sizeof(grocery));
        }
        if(count==0)
            cout<<"\nSorry,Data doesn't exist.";
        break;


    case '3':

        cout<<"Enter Quantity of item to be searched: ";
        cin>>search.quant;
        fin.read((char *)&temp,sizeof(grocery));
        while(fin.eof()==0)
        {
            if(temp.quant==search.quant)
            {
                if(count==0)
                {
                    cout<<"\n\n-------------------------------------------------------------------------------\n";
                    cout<<"Record No.\tItem name\t  Quantity    Cost\t  Status";
                    cout<<"\n-------------------------------------------------------------------------------\n";
                }
                count++;
                temp.disp();
            }
            fin.read((char *)&temp,sizeof(grocery));
        }
        if(count==0)
            cout<<"\nSorry,Data doesn't exist.";
        break;
    case '4':

        cout<<"Enter Cost of item to be searched: ";
        cin>>search.cost;
        fin.read((char *)&temp,sizeof(grocery));
        while(fin.eof()==0)
        {
            if(temp.cost==search.cost)
            {
                if(count==0)
                {
                    cout<<"\n\n-------------------------------------------------------------------------------\n";
                    cout<<"Record No.\tItem name\t  Quantity    Cost\t  Status";
                    cout<<"\n-------------------------------------------------------------------------------\n";
                }
                count++;
                temp.disp();
            }
            fin.read((char *)&temp,sizeof(grocery));
        }
        if(count==0)
            cout<<"\nSorry,Data doesn't exist.";
        break;

    case '5':

        cout<<"Enter Status of item A/U to be searched: ";
        cin>>search.status;
        fin.read((char *)&temp,sizeof(grocery));
        while(fin.eof()==0)
        {
            if(temp.status==search.status||temp.status==(search.status+32))
            {
                if(count==0)
                {
                    cout<<"\n\n-------------------------------------------------------------------------------\n";
                    cout<<"Record No.\tItem name\t  Quantity    Cost\t  Status";
                    cout<<"\n-------------------------------------------------------------------------------\n";
                }
                count++;
                temp.disp();
            }
            fin.read((char *)&temp,sizeof(grocery));
        }
        if(count==0)
            cout<<"\nSorry,Data doesn't exist.";
        fin.close();

    }
    fin.close();
    cout<<"\n";
}

void grocery::write()
{
    char record[4];
    ofstream fout("User Files\\stock2.dat",ios::app);
    //ifstream fin("stock2.dat");
    //fout.seekp(0);
    //grocery temp;
    cout<<"\nRecord Number: ";
    cin>>record;
    //fin.seekg(recno(rno)*sizeof(grocery),ios::beg);
    //fin.read((char*)&temp,sizeof(grocery));
    grocery temp;
    temp=itemSearch(record);
    if(!strcmp(temp.rno,"000"))
    {
        strcpy(temp.rno,record);
        temp.input();
        if(temp.quant>0&&temp.cost>0)
        {
            //fout.seekp(recno(temp.rno)*sizeof(grocery),ios::beg);
            fout.write((char*)&temp,sizeof(grocery));
            cout<<"\n\tItem Added Successfully\n";
        }
        else
        {
            cout<<"Quantity or/and Cost entered incorrectly.Record NOT added.\n";
        }
    }
    else
        cout<<"\nData is already present, instead try modifying.";

    fout.close();
    //fin.close();
}

void grocery::writeempty()
{
    ofstream fout("User Files\\stock2.dat");
    for(int i=0; i<2600; i++)
        fout.write((char *)this,sizeof(grocery));

    fout.close();
}

grocery grocery::itemSearch(char* ptr)
{
    grocery temp;
    grocery n;
    ifstream fin("User Files\\stock2.dat");
    if(!fin)
    {
        //cout<<"File could not be copened.";
        return n;
    }
    fin.read((char *)&temp,sizeof(grocery));
        while(fin.eof()==0)
        {
            if(!strcmp(ptr,temp.rno))
            {
                fin.close();
                return temp;
            }
            fin.read((char *)&temp,sizeof(grocery));
        }
        fin.close();
        return n;
}
