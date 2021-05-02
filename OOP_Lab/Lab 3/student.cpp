#include<iostream>

using namespace std;

class student{
    char name[30];
    int rollno;
    char grade[2];
    public:
        void get_data();
        void show_data();
};

int main()
{
    student student_array[3];

    for(int i =0;i<3;i++)
    {
        cout<<"Enter the details of "<<i+1<<" student"<<endl;
        student_array[i].get_data();
        cout<<"\n";
    }

    cout<<"-----------------------------------------------"<<endl;

    for(int i =0;i<3;i++)
    {
        cout<<"Details of "<<i+1<<" student"<<endl;
        student_array[i].show_data();
        cout<<"\n";
    }

    return 0;
}

void student::get_data()
{
    cout<<"Enter name of student: ";
    fflush(stdin);
    cin.getline(name,30);
    cout<<"Enter the roll no. : ";
    cin>>rollno;
    cout<<"Enter the grade : ";
    cin>>grade;
}

void student::show_data()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Roll No. : "<<rollno<<endl;
    cout<<"Grade: "<<grade<<endl;
}