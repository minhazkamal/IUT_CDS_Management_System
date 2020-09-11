#include "ShopBalance.h"
#include<bits/stdc++.h>
#include "purchase.h"
#include "customer.h"

using namespace std;

ShopBalance::ShopBalance()
{
    sellingCost=0;
    buyingCost=0;
    setProfit();
    strcpy(date,"");
}

ShopBalance::~ShopBalance()
{

}

void ShopBalance::setProfit()
{
    profit=sellingCost-buyingCost;
}

bool ShopBalance::checkDate(char *d)
{
    ifstream fin("User Files\\totalBalance.dat");
    if(!fin) return false;
    else
    {
        while(fin.read((char*)this,sizeof(ShopBalance)))
        {
            if(strcmp(this->date, d)==0)
            {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }
}

void ShopBalance::profitByDate()
{
    string s_d;
    ifstream fin("User Files\\totalBalance.dat");
    if(!fin)
    {
        cout<<"\nFile doesn't Exist!!!\n";
        return;
    }
    else
    {
        fflush(stdin);
        double sum_sc=0, sum_bc=0, sum_p=0;
        cout<<"\nEnter the month and the year in (DD/MM/YYYY) format: ";
        cin>>s_d;
        if(s_d.length()==10)
        {
            while(fin.read((char*)this,sizeof(ShopBalance)))
            {
                if(this->date==s_d)
                {
                    sum_sc=this->sellingCost;
                    sum_bc=this->buyingCost;
                    sum_p=this->profit;
                    break;
                }
            }
            display(s_d);
            cout<<right<<setw(10)<<sum_sc<<setw(15)<<sum_bc<<setw(16)<<sum_p<<endl;
            fin.close();
        }
        else
        {
            cout<<"\nInvalid Format!!!\n";
            fin.close();
        }
    }
}

void ShopBalance::profitByMonth()
{
    string s_d;
    ifstream fin("User Files\\totalBalance.dat");
    if(!fin)
    {
        cout<<"\nFile doesn't Exist!!!\n";
        return;
    }
    else
    {
        fflush(stdin);
        double sum_p=0,sum_s=0,sum_b=0;
        cout<<"\nEnter the month and the year in (MM/YYYY) format: ";
        cin>>s_d;
        if(s_d.length()==7)
        {
        while(fin.read((char*)this,sizeof(ShopBalance)))
        {
            string c_d;
            for(int i=3;i<10;i++) c_d=c_d+this->date[i];
            if(s_d==c_d)
            {
                sum_p=sum_p+this->profit;
                sum_s=sum_s+this->sellingCost;
                sum_b=sum_b+this->buyingCost;
            }
        }
        display(s_d);
        cout<<right<<setw(10)<<sum_s<<setw(15)<<sum_b<<setw(16)<<sum_p<<endl;
        fin.close();
        }
        else cout<<"\nInvalid Format!!!\n";
        fin.close();
        //return sum;
    }
}

void ShopBalance::profitByYear()
{
    string s_d;
    ifstream fin("User Files\\totalBalance.dat");
    if(!fin)
    {
        fin.close();
        cout<<"\nFile doesn't Exist!!!\n";
        return;
    }
    else
    {
        fflush(stdin);
        double sum_p=0,sum_s=0,sum_b=0;
        cout<<"\nEnter the month and the year in (YYYY) format: ";
        cin>>s_d;
        if(s_d.length()==4)
        {
        while(fin.read((char*)this,sizeof(ShopBalance)))
        {
            string c_d;
            for(int i=6;i<10;i++) c_d=c_d+this->date[i];
//            cout<<c_d<<" AND "<<s_d<<endl;
            if(s_d==c_d)
            {
                //cout<<c_d<<" AND "<<s_d<<endl;
                sum_p=sum_p+this->profit;
                sum_s=sum_s+this->sellingCost;
                sum_b=sum_b+this->buyingCost;
            }
        }
        display(s_d);
        cout<<right<<setw(10)<<sum_s<<setw(15)<<sum_b<<setw(16)<<sum_p<<endl;
        }
        else cout<<"\nInvalid Format!!!\n";
        fin.close();
        //return sum;
    }
}

void ShopBalance::writeSellingPrice(double x, char* d)
{

    ifstream fin("User Files\\totalBalance.dat");
    if(!fin)
    {
        writeFirst();
    }
    if(checkDate(d))
    {
        fstream fout("User Files\\temp.dat",ios::app);
        while(fin.read((char*)this,sizeof(ShopBalance)))
        {
            if(strcmp(this->date,d)==0)
            {
                this->sellingCost+=x;
                this->setProfit();
            }
            fout.write((char*)this,sizeof(ShopBalance));
        }
        fout.close();
        fin.close();
        remove("User Files\\totalBalance.dat");
        rename("User Files\\temp.dat","User Files\\totalBalance.dat");
    }
    else
    {
        fin.close();
        fstream fout2("User Files\\totalBalance.dat",ios::app);
        ShopBalance temp;
        temp.sellingCost+=x;
        temp.setProfit();
        strcpy(temp.date, d);
        fout2.write((char*)&temp,sizeof(ShopBalance));
        fout2.close();
    }
}

void ShopBalance::writeBuyingPrice(double x, char* d)
{

    ifstream fin("User Files\\totalBalance.dat");
    if(!fin)
    {
        writeFirst();
    }
    if(checkDate(d))
    {
        fstream fout("User Files\\temp.dat",ios::app);
        while(fin.read((char*)this,sizeof(ShopBalance)))
        {
            if(strcmp(this->date,d)==0)
            {
                this->buyingCost+=x;
                this->setProfit();
            }
            fout.write((char*)this,sizeof(ShopBalance));
        }
        fout.close();
        fin.close();
        remove("User Files\\totalBalance.dat");
        rename("User Files\\temp.dat","User Files\\totalBalance.dat");
    }
    else
    {
        fin.close();
        fstream fout2("User Files\\totalBalance.dat",ios::app);
        ShopBalance temp;
        temp.buyingCost+=x;
        temp.setProfit();
        strcpy(temp.date, d);
        fout2.write((char*)&temp,sizeof(ShopBalance));
        fout2.close();
    }
}

void ShopBalance::writeFirst()
{
    purchase temp_p;
    customer temp_c;
    ofstream f("User Files\\totalBalance.dat");
    f.close();
    ifstream fin2("User Files\\purchase.dat");
    if(!fin2)
    {
        fin2.close();
        cout<<"Customer/Purchase File could not be opened.";
        remove("User Files\\totalBalance.dat");
        return;
        //temp_p.writeempty();
    }
    else
    {
        while(fin2.read((char*)&temp_p,sizeof(purchase)))
        {
            double total=(temp_p.quant) * (temp_p.cost);
            writeBuyingPrice(total, temp_p.bdate);
        }
        fin2.close();
    }

    ifstream fin("User Files\\customer.dat");
    if(!fin)
    {
        fin.close();
        cout<<"Customer/Purchase File could not be opened.";
        remove("User Files\\totalBalance.dat");
        return;
        //temp_c.writeempty();
    }
    else
    {
        while(fin.read((char*)&temp_c,sizeof(customer)))
        {
            double total=(temp_c.quant) * (temp_c.cost);
            writeSellingPrice(total, temp_c.cdate);
        }
        fin.close();

    }

}

void ShopBalance::display(string s)
{
    if(s.length()==10)
    {
        cout<<"\n---------------------------------------------\n";
        cout<<"\tPROFIT OF DATE: "<<s;
        cout<<"\n---------------------------------------------\n\n\n";
        cout<<"SELLING PRICE\t  BUYING PRICE\t  NET PROFIT\n";
        cout<<"-----------------------------------------------\n\n";
    }
    else if(s.length()==7)
    {
        string m = extractMonth(s);
        cout<<"\n---------------------------------------------\n";
        cout<<"\tPROFIT OF MONTH: "<<m;
        cout<<"\n---------------------------------------------\n\n\n";
        cout<<"SELLING PRICE\t  BUYING PRICE\t  NET PROFIT\n";
        cout<<"-----------------------------------------------\n\n";
    }
    else if(s.length()==4)
    {
        cout<<"\n---------------------------------------------\n";
        cout<<"\tPROFIT OF YEAR: "<<s;
        cout<<"\n---------------------------------------------\n\n\n";
        cout<<"SELLING PRICE\t  BUYING PRICE\t  NET PROFIT\n";
        cout<<"-----------------------------------------------\n\n";
    }
    else
    {
        cout<<"\nInvalid Format!!!\n";
    }
}

string ShopBalance::extractMonth(string s)
{
    string m,y;
    for(int i=0;i<s.length();i++)
    {
        if(i<3) m=m+s[i];
        else if(i>=3) y=y+s[i];
    }

    int d = stoi(m);

    switch(d)
    {
    case 1:
        m="January, ";
        break;
    case 2:
        m="February, ";
        break;
    case 3:
        m="March, ";
        break;
    case 4:
        m="April, ";
        break;
    case 5:
        m="May, ";
        break;
    case 6:
        m="June, ";
        break;
    case 7:
        m="July, ";
        break;
    case 8:
        m="August, ";
        break;
    case 9:
        m="September, ";
        break;
    case 10:
        m="October, ";
        break;
    case 11:
        m="November, ";
        break;
    case 12:
        m="December, ";
        break;
    default:
        m="";
        break;
    }
    if(m!="") m=m+y;

    return m;
}

