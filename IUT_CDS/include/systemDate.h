#ifndef SYSTEMDATE_H_INCLUDED
#define SYSTEMDATE_H_INCLUDED


using namespace std;

void calculateDate(char* d);
//{
//    time_t now = time(0);
//
//    tm *ltm = localtime(&now);
//
//    int year = 1900 + ltm->tm_year;
//    int month = 1 + ltm->tm_mon;
//    int day = ltm->tm_mday;
//
//    string dt="";
//
////    string dt=to_string(day)+"/"+to_string(month)+"/"+to_string(year);
////    cout<<dt;
//    if(day<10) dt+=to_string(0)+to_string(day)+"/";
//    else dt+=to_string(day)+"/";
//
//    if(month<10) dt+=to_string(0)+to_string(month)+"/";
//    else dt+=to_string(month)+"/";
//
//    dt+=to_string(year);
//
////    cout<<dt;
//    for(int i=0;i<10;i++)
//    {
//        d[i]=dt[i];
//    }
//    d[10]='\0';
//
//
////    cout << "Year:" << 1900 + ltm->tm_year << endl;
////    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
////    cout << "Day: "<<  ltm->tm_mday << endl;
////    cout << "Time: "<< ltm->tm_hour << ":";
////    cout << ltm->tm_min << ":";
////    cout << ltm->tm_sec << endl;
//}



#endif // SYSTEMDATE_H_INCLUDED
