#include<iostream>
#include<limits>

using namespace std;

enum ManagerRole { AssitantManager, Manager, VicePresident };
enum EngineerRole { SDE1, SDE2, SDE3 , ProjectManager};

class Employee
{
private:
    int Id;
    string Name;
public:
    static int IdCounter;
    Employee();
    void setName(string name);
    void setId(int id);
    string getName() const;
    int getId() const;
    virtual void raiseSalary(float increament) = 0;
    virtual void promote() = 0;
    virtual void display();
    virtual void Promotion(){}
protected:
    double Salary;
};

int Employee::IdCounter = 1;

class Engineer : public Employee
{
private:
    EngineerRole Role;
public:
    Engineer();
    void Promotion();
    EngineerRole getRole() const;
    void raiseSalary(float increament) override;
    void promote() override;
    void display();
};

class Manager : public Employee
{
private:
    ManagerRole Role;
public:
    Manager();
    void Promotion();
    ManagerRole getRole() const;
    void raiseSalary(float increament) override;
    void promote() override;
    void display();
};

class Node
{
public:
    Employee *employee;
    Node *next;
};

enum MenuChoice { Exit, AddEmployee , RaiseSalary , Promote , ClearScreen};

void Interface(Node *EmployeeList);
void PrintControls();
MenuChoice getChoice();
bool isValidChoice(int choice);
void addEmployee(Node **EmployeeList);
void RaiseEmployeeSalary(Node *EmployeeList);
void PromoteEmployee(Node *EmployeeList);
Employee* FindEmployeeById(Node *EmployeeList);
EngineerRole StringtoEngineerRole(string role);
ManagerRole StringtoManagerRole(string role);
string EngineerRoletoString(EngineerRole Role);
string ManagerRoletoString(ManagerRole Role);

int main()
{
    Node *EmployeeList = NULL;
    Interface(EmployeeList);
    return 0;
}

MenuChoice getChoice()
{
    int choice;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    if(!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw "Wrong input only enter valid integer options";    
    }
    if(isValidChoice(choice))
        return (MenuChoice)choice;
    throw "Invalid Menu choice entered";

}

inline void PrintControls()
{
    cout<<"//////////////////////////////////////////////////////////////"<<endl;
    cout<<"---------Welcome Employee Management System--------------"<<endl;
    cout<<"Choose choice mention if front of options "<<endl;
    cout<<"0:Exit"<<endl;
    cout<<"1:Add Employee"<<endl;
    cout<<"2:Raise Salary of Employee"<<endl;
    cout<<"3:Promote Employee"<<endl;
    cout<<"4:Clear Screen"<<endl;
}

void Interface(Node *EmployeeList)
{
    PrintControls();
    while(true)
    {
        MenuChoice Choice;
        
        getChoiceAgain:
        try{
            Choice = getChoice();
        }
        catch(char const *error)
        {
            cout<<error<<endl;
            cout<<"Enter choice again"<<endl;
            goto getChoiceAgain;
        }

        switch (Choice)
        {
        case Exit:
            exit(EXIT_SUCCESS);
            break;
        case AddEmployee:
            addEmployee(&EmployeeList);
            break;
        case RaiseSalary:
            RaiseEmployeeSalary(EmployeeList);
            break;
        case Promote:
            PromoteEmployee(EmployeeList);
            break;
        case ClearScreen:
            system("clear");
            PrintControls();
        }
    }
}

void addEmployee(Node **EmployeeList)
{
    int choice;
    cout<<"Enter 1 for Engineer or 2 for Manager:";
    cin>>choice;
    while(!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Wrong input valid options are only 1 or 2"<<endl;
        cout<<"Enter 1 for Engineer or 2 for Manager:";
        cin>>choice;
    }
    Node *newNode = new Node;
    string name;
    try
    {
        if(choice == 1)
            newNode->employee = new Engineer();
        else if(choice == 2)
            newNode->employee = new class Manager();
        else
        {
            while(choice !=1 || choice!=2)
            {
                cout<<"Enter 1 or 2 only"<<endl;
                cout<<"Enter 1 for Engineer or 2 for Manager:";
                cin>>choice;
            }
        }
    }
    catch(bad_alloc e)
    {
        cout << "Bad alloction in addEmployee()" << '\n';
        exit(EXIT_FAILURE);
    }
    cout<<"Enter name of employee:";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,name);
    newNode->employee->setName(name);
    newNode->employee->setId(Employee::IdCounter++);
    newNode->next = *EmployeeList;
    *EmployeeList = newNode;
    cout<<"Employee Successfully Registered"<<endl;
    cout<<"--------Details of this employee-------"<<endl;
    newNode->employee->display();
}

bool isValidChoice(int choice)
{
    if( choice == Exit || choice == AddEmployee || 
        choice ==  RaiseSalary || choice == Promote || choice == ClearScreen)
        return true;
    return false;
}

Employee* FindEmployeeById(Node *EmployeeList)
{
    int id;
    cout<<"Enter ID of employee:";
    cin>>id;
    if(!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw "Wrong input id can only be positive integer";
    }
    Node *temp = EmployeeList;
    while(temp!=NULL&&temp->employee->getId()!=id)
    {
        temp = temp->next;
    }
    if(temp == NULL)
        throw "Employee Not Found";
    return temp->employee;
    
}

void RaiseEmployeeSalary(Node *EmployeeList)
{
    Employee *emp;
    try{
        emp = FindEmployeeById(EmployeeList);
    }
    catch(char const *error)
    {
        cout<<error<<endl;
        return;
    }
    int raise;
    cout<<"Enter how much % raise is given:";
    cin>>raise;
    emp->raiseSalary(raise/100.0);
    cout<<"---Detail of Employee after Salary Riase------"<<endl;
    emp->display();
}

void PromoteEmployee(Node *EmployeeList)
{
    Employee *emp;
    try{
        emp = FindEmployeeById(EmployeeList);
    }
    catch(char const *error)
    {
        cout<<error<<endl;
        return;

    }
    try{
        emp->Promotion();
    }
    catch(char const *error)
    {
        cout<<error<<endl;
        return;
    }
    cout<<"----Detail of Employee after Promotion----"<<endl;
    emp->display();
}

Employee::Employee()
{
    this->Name = "NULL";
    this->Id = 0;
    this->Salary = 30000;

}

void Employee::setName(string name)
{
    this->Name = name;
}

void Employee::setId(int id)
{
    this->Id = id;
}

inline string Employee::getName() const
{
    return this->Name;
}

inline int Employee::getId() const
{
    return this->Id;
}

Engineer::Engineer()
{
    this->Role = SDE1;
}

void Employee::display()
{
    cout<<"ID:"<<this->getId()<<endl;
    cout<<"Name:"<<this->getName()<<endl;
    cout<<"Salary:"<<this->Salary<<endl;
}

void Engineer::display()
{
    Employee::display();

    string role;
    try{
        role = EngineerRoletoString(this->Role);
    }
    catch(char const *error)
    {
        cout<<error<<endl;
        return;
    }

    cout<<"Role:"<<role<<endl;
}

inline EngineerRole Engineer::getRole() const
{
    return this->Role;
}

inline ManagerRole Manager::getRole() const
{
    return this->Role;
}

void Engineer::raiseSalary(float increament)
{   
    this->Salary += increament * this->Salary;
}

EngineerRole StringtoEngineerRole(string role)
{
    if(role == "SDE2")
        return SDE2;
    else if(role == "SDE3")
        return SDE3;
    else if (role == "ProjectManager")
        return ProjectManager;
    throw "Invalid Role for Engineer";
}

string EngineerRoletoString(EngineerRole Role)
{
    if(Role == SDE1)
        return "SDE1";
    if(Role == SDE2)
        return "SDE2";
    if(Role == SDE3)
        return "SDE3";

    throw "Invalid Role for Engineer";
}

void Engineer::Promotion()
{
    string role;
    cout<<"Enter New Role:";
    cin>>role;
    try{
        this->Role = StringtoEngineerRole(role);
    }
    catch(char const *error)
    {
        throw error;
    }
    this->promote();
}

void Engineer::promote()
{

    this->raiseSalary(0.25);
}

Manager::Manager()
{
    this->Role = AssitantManager;
}

void Manager::raiseSalary(float increament)
{
    this->Salary += increament * this->Salary;
}

ManagerRole StringtoManagerRole(string role)
{
    if(role == "Manager")
        return Manager;
    else if(role == "VicePresident")
        return VicePresident;
    throw "Invalid Role for Manager";
}

string ManagerRoletoString(ManagerRole Role)
{
    if(Role == AssitantManager)
        return "AssitantManager";
    else if(Role == Manager)
        return "Manager";
    else if(Role == VicePresident)
        return "VicePresident";

    throw "Invalid Role for Manager";
}

void Manager::Promotion()
{
    string role;
    cout<<"Enter New Role:";
    cin>>role;
    try{
        this->Role = StringtoManagerRole(role);
    }
    catch(char const *error)
    {
        throw error;
    }
    this->promote();
}

void Manager::promote()
{
    this->raiseSalary(0.25);
}

void Manager::display()
{
    Employee::display();

    string role;
    try{
        role = ManagerRoletoString(this->Role);
    }
    catch(char const *error)
    {
        cout<<error<<endl;
        return;
    }

    cout<<"Role:"<<role<<endl;
}
