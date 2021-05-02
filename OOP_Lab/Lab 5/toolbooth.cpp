#include<iostream>

using namespace std;

class ToolBooth{
    unsigned int total_cars;
    double total_money;
    public:
        ToolBooth();
        void payingCar();
        void nopayCar();
        void display();
};

int main()
{
    ToolBooth booth;
    char choice;
    do{
        char choice;

        cout<<"Enter p/P for counting paying car"<<endl;
        cout<<"Enter n/N for counting non-paying car"<<endl;
        cout<<"Enter ESC key to print the total number of cars passed , total money collected and exit"<<endl;
        cin>>choice;
        if(choice =='p' || choice =='P')
        {
            booth.payingCar();
        }
        else if(choice =='n' || choice =='N')
        {
            booth.nopayCar();
        }
        else if(int(choice)==27)
        {
            break;
        }
        cout<<"---------------------------------------\n";
    }while(true);
    booth.display();
    return 0;
}

ToolBooth::ToolBooth(){
    this->total_cars = 0;
    this->total_money = 0;
}

void ToolBooth::payingCar(){
    this->total_cars += 1;
    this->total_money += 0.50;
    cout<<"Paying car is registered"<<endl;
}

void ToolBooth::nopayCar(){
    this->total_cars += 1;
    cout<<"Non paying car is registered"<<endl;
}

void ToolBooth::display(){
    cout<<"Total number of cars passed: "<<this->total_cars<<endl;
    cout<<"Total money collected: "<<this->total_money<<endl;
}