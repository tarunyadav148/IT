#include<iostream>

using namespace std;

class bank_account{
    string name_of_depositor;
    int account_number;
    string account_type;
    int balance_amount;
    public:
        bank_account();
        void get_data();
        void show_data();
        void deposit();
        void withdraw();
        bool valid_amount_for_withdraw(int);

};

int get_choice()
{
    int choice;
    cout<<"-------------------------------------------------------------\n";
    cout<<"\tEnter 0 for exit"<<endl;
    cout<<"\tEnter 1 for deposit"<<endl;
    cout<<"\tEnter 2 for withdraw"<<endl;
    cout<<"\tEnter 3 for show details"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}

int main()
{
    bank_account account;
    cout<<"-------------------Enter details of account----------------------------------\n";
    account.get_data();
    int choice;
    do{
        choice = get_choice();
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            account.deposit();
            break;
        case 2:
            account.withdraw();
            break;
        case 3:
            account.show_data();
            break;
        default:
            cout<<"Enter a valid choice"<<endl;
            break;
        }
    }while(true);
    return 0;
}

bank_account::bank_account(){
    this->name_of_depositor = "Null";
    this->account_number= 0;
    this->account_type = "Null";
    this->balance_amount = 0;
}

void bank_account::get_data(){
    cout<<"Enter name of depositor: ";
    fflush(stdin);
    getline(cin,this->name_of_depositor);
    cout<<"Enter account number: ";
    cin>>this->account_number;
    cout<<"Enter account type: ";
    cin>>this->account_type;

}

void bank_account::show_data(){
    cout<<"---------------Account details---------------------------\n";
    cout<<"Name of depositor: "<<this->name_of_depositor<<endl;
    cout<<"Account number: "<<this->account_number<<endl;
    cout<<"Account type: "<<this->account_type<<endl;
    cout<<"Balance amount: "<<this->balance_amount<<endl;
    cout<<"---------------------------------------------------------\n";
}

void bank_account::deposit(){
    int amount;
    cout<<"Enter the amount want to deposit: ";
    cin>>amount;
    if(amount>0){
        this->balance_amount += amount;
    }else{
        cout<<"Please enter a positive integer"<<endl;
    }
}

void bank_account::withdraw(){
    int amount;
    cout<<"Enter the amount want to withdraw: ";
    cin>>amount;
    if(this->valid_amount_for_withdraw(amount)){
        this->balance_amount -= amount;
    }else{
        cout<<"Please enter a valid amount for withdraw"<<endl;
    }
}

bool bank_account::valid_amount_for_withdraw(int amount){
    if(amount>0){
        if(amount<=this->balance_amount){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}