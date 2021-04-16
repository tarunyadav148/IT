#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20                          

struct customer                           //Use of structure
{
    char name[SIZE];
    long long int mobile_number;
    int outstanding;
};

struct Khatabook
{
    struct customer customer_array[20];       //Use of arrays
    int customer_count;
};

void UI();                                  //fuctions declarations
void menu(int chocie);
void init();
void add_customer();
void show_all_customer();
void show_particular_customer();
void show_defaulter();
struct customer customer_input();
void customer_ouptut(struct customer ctm);
int find_customer();
void pay();
void buy();

struct Khatabook khatabook;                   //Use of Global variable

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
    printf("-----------Khatabook-----------\n");
    printf("1:Add customer\n");
    printf("2:Credit customer outstanding\n");
    printf("3:Debit customer outstanding\n");
    printf("4:Show of a particular customer\n");
    printf("5:Show data of all customer\n");
    printf("6:Show Defaulter\n");
    printf("0:Close the apllication\n");
    printf("---------------------------------\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
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
                printf("Invalid input please enter again");
                break;
        }
        printf("---------------------------------\n");
        printf("---------------------------------\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
    }
    
}

struct customer customer_input()
{
    struct customer ctm;
    printf("Enter name of customer: ");
    fflush(stdin);
    gets(ctm.name);
    printf("Enter mobile number of customer: ");
    scanf("%lld",&ctm.mobile_number);
    ctm.outstanding = 0;
    return ctm;
}

void customer_output(struct customer ctm)
{
    printf("---------------------------------\n");
    printf("Nmae of customer: %s\n",ctm.name);
    printf("Mobile number of customer: %lld\n",ctm.mobile_number);
    printf("Outstanding amount: %d\n",ctm.outstanding);

}

void add_customer()
{
    struct customer ctm;
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
    printf("Enter mobile number of customer:");
    scanf("%lld",&mobile_number);
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
    printf("Enter the total billing amount: ");
    scanf("%d",&amount);
    khatabook.customer_array[index].outstanding += amount;
}

void pay()
{
    int index = find_customer();
    int amount;
    printf("Enter the total paid amount: ");
    scanf("%d",&amount);
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