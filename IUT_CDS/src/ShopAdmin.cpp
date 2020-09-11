#include "ShopAdmin.h"
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;

ShopAdmin::ShopAdmin()
{

}

ShopAdmin::~ShopAdmin()
{

}

void ShopAdmin::writeDefault()
{
    ifstream fin("User Files\\Admin.dat");
    if(!fin)
    {
        ofstream f("User Files\\Admin.dat");
        setUsername("Admin");
        setPassword(1234);
        f.write((char*)this,sizeof(ShopAdmin));

        f.close();
    }
    fin.close();
}

void ShopAdmin::write()
{
    ofstream f("User Files\\Admin.dat");
    setUsername();
    setPassword();
    f.write((char*)this,sizeof(ShopAdmin));

    f.close();
}

void ShopAdmin::read()
{
    ifstream f("User Files\\Admin.dat");
    f.read((char*)this,sizeof(ShopAdmin));

    cout<<"Username: "<<getUsername()<<endl;
    cout<<"Password: "<<getPassword()<<endl;

    f.close();
}

void ShopAdmin::changePassword()
{
    fstream fr("User Files\\Admin.dat");
    fstream fw("User Files\\temp.dat",ios::app);
    fr.read((char*)this,sizeof(ShopAdmin));

    //ShopAdmin a=*this;

    int temp_pass;
    cout<<"Enter current Password: ";
    cin>>temp_pass;
    if(temp_pass==getPassword())
    {
        setPassword();
        //cout<<getPassword()<<endl;
        //cout<<getPassword()<<endl;
        fw.write((char*)this,sizeof(ShopAdmin));

    }
    fr.close();
    fw.close();
//    ifstream fg("temp.dat");
//    fg.read((char*)this,sizeof(ShopAdmin));
//    cout<<getPassword()<<endl;

    remove("User Files\\Admin.dat");
    rename("User Files\\temp.dat","User Files\\Admin.dat");
//    if(remove("Admin.dat")) cout<<1<<endl;
//    if(rename("temp.dat","Admin.dat")) cout<<2<<endl;
//    ifstream fp("Admin.dat");
//    fp.read((char*)this,sizeof(ShopAdmin));
//    fp.close();
//    cout<<getPassword()<<endl;
}
