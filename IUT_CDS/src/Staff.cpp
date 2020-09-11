#include<bits/stdc++.h>
#include "staff.h"

using namespace std;

//string File_Loc = "C:/Users/minha/Desktop/OOP Project/IUT_CDS/files";

staff::staff()
{

}

staff::~staff()
{
    //dtor
}

void staff::write()
{
    fstream f("User Files\\staff.dat",ios::app);

    setUsername();
    setPassword();
    setSalary();
    f.write((char*)this,sizeof(staff));
//    cout<<"\nSince Only one Staff is allowed,data was OVERWRITTEN.\n";

    f.close();
}

void staff::read()
{
    int cnt=0;
    ifstream f("User Files\\staff.dat");
    cout<<endl;
    while(f.read((char*)this,sizeof(staff)))
    {
        cnt++;
        cout<<"Userid of Staff :";
        cout<<getUsername()<<endl;
        cout<<"Staff's password:";
        cout<<getPassword()<<endl;
        cout<<"Salary of Staff: ";
        cout<<getSalary()<<endl<<endl;
    }
    cout<<"\n--> "<<cnt<<" staff(s) found.\n";

    f.close();
}

void staff::setSalary()
{
    cout<<"\nEnter Salary of the Staff: ";
    cin>>salary;
}

double staff::getSalary()
{
    return salary;
}

void staff::changePassword()
{
    staff temp;
    ifstream fr("User Files\\staff.dat",ios::in);
    fstream fw("User Files\\temp.dat",ios::app);
    //fr.read((char*)this,sizeof(ShopAdmin));
    int flag=0;
    int cnt=0;

    char temp_userName[20];
    cout<<"Enter Username: ";
    cin>>temp_userName;
    int temp_pass;
    cout<<"Enter current Password: ";
    cin>>temp_pass;
    while(fr.read((char*)&temp,sizeof(temp)))
    {
        flag++;
        if(temp.getUsername()==temp_userName&&temp_pass==temp.getPassword())
        {
            temp.setPassword();
            cnt=1;
        }

        fw.write((char*)&temp,sizeof(temp));
    }
    if(flag==0) cout<<"User doesn't exist\n";
    else if(flag!=0&&cnt==0) cout<<"Username/Password is incorrect\n";

    fw.close();
    fr.close();

    remove("User Files\\staff.dat");
    rename("User Files\\temp.dat","User Files\\staff.dat");
}

void staff::deleteStaff()
{
    staff temp;
    ifstream fr("User Files\\staff.dat",ios::in);
    fstream fw("User Files\\temp.dat",ios::app);
    //fr.read((char*)this,sizeof(ShopAdmin));
    int flag=0;

    char temp_userName[20];
    cout<<"Enter Username: ";
    cin>>temp_userName;
    while(fr.read((char*)&temp,sizeof(temp)))
    {
        if(temp.getUsername()==temp_userName)
        {
            flag=1;
        }
        else fw.write((char*)&temp,sizeof(temp));
    }
    if(flag==0) cout<<"User doesn't exist\n";
    else if(flag==1) cout<<"User has been deleted\n";

    fw.close();
    fr.close();

    remove("User Files\\staff.dat");
    rename("User Files\\temp.dat","User Files\\staff.dat");
}

void staff::changeSalary()
{
    staff temp;
    ifstream fr("User Files\\staff.dat",ios::in);
    fstream fw("User Files\\temp.dat",ios::app);
    //fr.read((char*)this,sizeof(ShopAdmin));
    int flag=0;

    char temp_userName[20];
    cout<<"Enter Username: ";
    cin>>temp_userName;
    while(fr.read((char*)&temp,sizeof(temp)))
    {
        if(temp.getUsername()==temp_userName)
        {
            temp.setSalary();
            flag=1;
        }
        fw.write((char*)&temp,sizeof(temp));
    }
    if(flag==0) cout<<"User doesn't exist\n";
    else if(flag==1) cout<<"Salary has been changed\n";

    fw.close();
    fr.close();

    remove("User Files\\staff.dat");
    rename("User Files\\temp.dat","User Files\\staff.dat");
}

int staff::searchStaff(string name,int pass)
{
    staff temp;
    ifstream fr("User Files\\staff.dat",ios::in);
    int flag=0;
    while(fr.read((char*)&temp,sizeof(temp)))
    {
        if(temp.getUsername()==name&&pass==temp.getPassword())
        {
            fr.close();
            return 1;
        }
    }
    fr.close();
    return 0;
}





