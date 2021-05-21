#include<iostream>

using namespace std;

class Date{
    int day;
    int month;
    int year;
    public:
        Date();
        Date(int day,int month,int year);
        Date(string date);
        void get();
        void show();
};

Date::Date(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::Date(int day,int month,int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(string date){
    this->day = stoi(date.substr(0,2));
    this->month = stoi(date.substr(3,2));
    this->year = stoi(date.substr(6,4));
}

void Date::get(){
    string date;
    cout<<"Enter date in this format (dd/mm/yyyy): ";
    cin>>date;
    *this = Date(date);
}

void Date::show(){
    cout<<this->day<<'/'<<this->month<<'/'<<this->year<<endl;
}

int main()
{
    Date dob(14,8,2002);
    cout<<"DOB:";
    dob.show();
    Date viva("13/05/2021");
    cout<<"Viva on:";
    viva.show();
    Date today;
    today.get();
    cout<<"Today's date:";
    today.show();
    return 0;
}