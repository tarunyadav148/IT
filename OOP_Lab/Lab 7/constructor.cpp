#include<iostream>

using namespace std;

class Viva{
    string examiner[2];
    string subject;
    string student;
        public:
        Viva();
        ~Viva();
};

Viva::Viva(){
    this->examiner[0] = "Seema Mam";
    this->examiner[1] = "Lalan Sir";
    this->subject = "OOP";
    this->student = "Tarun";
}

Viva::~Viva(){
    cout<<examiner[0]<<" and "<<examiner[1]<<endl;
    cout<<"Please give "<<this->student<<" good marks"<<endl;
}

int main()
{
    Viva oop_viva;
    return 0;
}