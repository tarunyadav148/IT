#include<iostream>

using namespace std;

class student{

private:
    string name;
    int rollNo;
public:
    student();
    void get_Studentdata();
    string Name();
    int RollNo();
};

class exam{

private:
    int marks[6];
public:
    int Marks(int index);
protected:
    void get_mark();
};

class result: public student, public exam{

private:
    int totalmarks;
public:
    result();
    int totalMarks();
    void get_marks();
};

student::student()
{
    name = "Not given";
    rollNo = 0;

}

void student::get_Studentdata()
{
    int rollno;
    cout<<"Enter name of the student: ";
    fflush(stdin);
    getline(cin,name);
    cout<<"Enter roll of the student: ";
    cin>>rollno;
    while(rollno<0)
    {
        cout<<"Please enter positive integer for roll number"<<endl;
        cin>>rollno;
    }
    this->rollNo = rollno;
}


string student::Name()
{
    return name;
}

int student::RollNo()
{
    return rollNo;
}


void exam::get_mark()
{
    cout<<"------Enter marks of 6 subject------"<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<"Enter mark of "<<i<<" subject: ";
        cin>>marks[i];
    }
}

int exam::Marks(int index)
{
    if(index>=0&&index<=6)
        return marks[index];
    else
        return -1;
}

result::result()
{
    totalmarks = 0;
}

void result::get_marks()
{
    exam::get_mark();
    for(int i=0;i<6;i++)
        totalmarks += exam::Marks(i);
}

int result::totalMarks()
{
    return totalmarks;
}


int main()
{
    result res;
    cout<<"--------Enter details of student-------"<<endl;
    res.get_Studentdata();
    res.get_marks();
    cout<<"------------Result of student----------"<<endl;
    cout<<"Name of student: "<<res.Name()<<endl;
    cout<<"Roll number of student: "<<res.RollNo()<<endl;
    cout<<"Total marks gain: "<<res.totalMarks()<<endl;
    return 0;
}