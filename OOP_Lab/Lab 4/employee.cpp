#include<iostream>

using namespace std;

class Employee
{
private:
    string Employee_name;
    int Employee_id;
    int Employee_salary;
    string Employee_address;
public:
    void getInput();
    void PrintOutput();
};

int main()
{
    Employee emp;
    emp.getInput();
    cout<<"\n";
    emp.PrintOutput();
    return 0;
}

void Employee::getInput()
{
    cout<<"Enter name of the employee: ";
    fflush(stdin);
    getline(cin,Employee_name);
    cout<<"Enter the id of employee: ";
    cin>>Employee_id;
    cout<<"Enter the salary of employee: ";
    cin>>Employee_salary;
    cout<<"Enter the address of employee: ";
    fflush(stdin);
    getline(cin,Employee_address);
}

void Employee::PrintOutput()
{
    cout<<"Name of employee: "<<Employee_name<<endl;
    cout<<"Id of employee: "<<Employee_id<<endl;
    cout<<"Salary of empolyee: "<<Employee_salary<<endl;
    cout<<"Address of employee: "<<Employee_address<<endl;
}