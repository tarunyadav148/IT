#include<iostream>
#include<limits>

using namespace std;

class student
{
    private:
        int roll_no;
        string student_name;
        string student_address;
        string student_city;
        int student_pin;
        int student_sem;
        int rank;  
        string branch;
    public:
        student();
        void get_data();
        void show_data();
        bool check_sem(int sem){
            return this->student_sem == sem;
        }
        bool check_branch(string branch){
            return this->branch == branch;
        }
};

void sem_display(student s[],int count);
void branch_display(student s[],int count);

int main()
{
    student s[500];

    int choice , count=0;

    cout<<"----------------------Student Database----------------------\n";

    do
    {
        cout<<"0:Exit\n";
        cout<<"1:Add a student record\n";
        cout<<"2:Display details of student of particular Semester\n";
        cout<<"3:Display details of student of particular Branch\n";
        cin>>choice;
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            s[count].get_data();
            count++;
            break;
        case 2:
            sem_display(s,count);
            break;
        case 3:
            branch_display(s,count);
            break;
        default:
            cout<<"Please enter only specified choices\n";
            break;
        }
        cout<<"------------------------------------------------\n";
    } while (true);
    

    return 0;
}

student::student()
{
    this->roll_no = 0;
    this->student_name = "Not given";
    this->student_city = "Not given";
    this->student_address = "Not given";
    this->student_pin = 0;
    this->student_sem = 0;
    this->branch = "Not given";
}

void student::get_data(){
    cout<<"Enter the Roll number:";
    cin>>this->roll_no;
    cout<<"Enter the Name: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,this->student_name);
    cout<<"Enter the Address: ";
    fflush(stdin);
    getline(cin,this->student_address);
    cout<<"Enter the City: ";
    cin>>this->student_city;
    cout<<"Enter the Pincode: ";
    cin>>this->student_pin;
    cout<<"Enter the Semester: ";
    cin>>this->student_sem;
    cout<<"Enter the Rank: ";
    cin>>this->rank;
    cout<<"Enter the Branch: ";
    cin>>this->branch;
}

void student::show_data(){
    cout<<"Roll number: "<<this->roll_no<<endl;  
    cout<<"Name: "<<this->student_name<<endl;
    cout<<"Address: "<<this->student_address<<endl;
    cout<<"City: "<<this->student_city<<endl;
    cout<<"Pincode: "<<this->student_pin<<endl;
    cout<<"Semester: "<<this->student_sem<<endl;
    cout<<"Rank: "<<this->rank<<endl;
    cout<<"Branch: "<<this->branch<<endl;

}

void sem_display(student s[],int count){
    int sem;
    cout<<"Enter Semester: ";
    cin>>sem;
    for (int i = 0; i < count; i++)
    {
        if(s[i].check_sem(sem)){
            cout<<'\n';
            s[i].show_data();
            cout<<'\n';
        }
    }
        
}

void branch_display(student s[],int count){
    string branch;
    cout<<"Enter the branch: ";
    cin>>branch;
    for (int i = 0; i < count; i++)
    {
        if(s[i].check_branch(branch)){
            cout<<'\n';
            s[i].show_data();
            cout<<'\n';
        }
    }
}