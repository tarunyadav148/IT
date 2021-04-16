#include<iostream>
#include<cstring>
#include<limits>
#define SIZE 20    
using namespace std;                       

struct customer                           //Use of structure
{
    char name[SIZE];
    long long int mobile_number;
    int outstanding;
};

struct Khatabook
{
    struct customer customer_array[SIZE];       //Use of arrays
    int customer_count;
};

void UI();                                  //fuctions declarations
void menu(int chocie);
void init();
void add_customer();
void show_all_customer();
void show_particular_customer();
void show_defaulter();
customer customer_input();
void customer_ouptut(customer ctm);
int find_customer();
void pay();
void buy();

Khatabook khatabook;                   //Use of Global variable

int main()
{
    init();
    UI();
    return 0;
}

void init()
{
    khatabook.customer_count = 0;
    for(int i=0;i<SIZE;i++)
    {
        khatabook.customer_array[i].mobile_number=0;
        khatabook.customer_array[i].outstanding=0;
        strcpy(khatabook.customer_array[i].name,"NULL");        //use of string lib func
    }
}

void UI()
{
    int choice;
    cout<<"-----------Khatabook-----------\n";
    cout<<"1:Add customer\n";
    cout<<"2:Credit customer outstanding\n";
    cout<<"3:Debit customer outstanding\n";
    cout<<"4:Show of a particular customer\n";
    cout<<"5:Show data of all customer\n";
    cout<<"6:Show Defaulter\n";
    cout<<"0:Close the apllication\n";
    cout<<"---------------------------------\n";
    cout<<"Enter choice: ";
    cin>>choice;
    menu(choice);
}

void menu(int choice)
{
    while(1)                            //Use of while loop
    {
        switch (choice)                 //Use of switch case
        {
            case 0:
                exit(0);
            case 1:
                add_customer();
                break;
            case 2:
                buy();
                break;
            case 3:
                pay();
                break;
            case 4:
                show_particular_customer();
                break;
            case 5:
                show_all_customer();
                break;
            case 6:
                show_defaulter();
                break;
            default:
                cout<<"Invalid input please enter again";
                break;
        }
        cout<<"---------------------------------\n";
        cout<<"---------------------------------\n";
        cout<<"Enter choice: ";
        cin>>choice;
    }
    
}

customer customer_input()
{
    customer ctm;
    cout<<"Enter name of customer: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(ctm.name,SIZE);
    cout<<"Enter mobile number of customer: ";
    cin>>ctm.mobile_number;
    ctm.outstanding = 0;
    return ctm;
}

void customer_output(customer ctm)
{
    cout<<"---------------------------------\n";
    cout<<"Nmae of customer: "<<ctm.name<<endl;
    cout<<"Mobile number of customer: "<<ctm.mobile_number<<endl;
    cout<<"Outstanding amount: "<<ctm.outstanding<<endl;

}

void add_customer()
{
    customer ctm;
    ctm = customer_input();
    khatabook.customer_array[khatabook.customer_count] = ctm;
    khatabook.customer_count++;
}

void show_all_customer()
{
    for(int i=0;i<khatabook.customer_count;i++)             //Use of for loop
    {
        customer_output(khatabook.customer_array[i]);
    }
}

int find_customer()
{
    int index;
    long long int mobile_number;
    cout<<"Enter mobile number of customer:";
    cin>>mobile_number;
    for(int i=0;khatabook.customer_count;i++)
    {
        if(khatabook.customer_array[i].mobile_number==mobile_number)
        {
            index = i;
            break;
        }
    }
    return index;
}

void buy()
{
    int index = find_customer();
    int amount;
    cout<<"Enter the total billing amount: ";
    cin>>amount;
    khatabook.customer_array[index].outstanding += amount;
}

void pay()
{
    int index = find_customer();
    int amount;
    cout<<"Enter the total paid amount: ";
    cin>>amount;
    khatabook.customer_array[index].outstanding -= amount;
}

void show_defaulter()
{
    for(int i=0;i<khatabook.customer_count;i++)
    {
        if(khatabook.customer_array[i].outstanding>0)
        {
            customer_output(khatabook.customer_array[i]);
        }
    }
}

void show_particular_customer()
{
    int index = find_customer();
    customer_output(khatabook.customer_array[index]);
    
}