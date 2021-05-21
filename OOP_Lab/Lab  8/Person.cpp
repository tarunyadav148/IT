#include<iostream>

using namespace std;

class Person{

private:
    string name;
    int age;

public:
    Person();
    Person(string name, int age);
    void SetValues(string name, int age);
    void Print();
    void Print() const;
};

Person::Person(){
    name = "None";
    age = 0;
}

Person::Person(string name, int age){
    this->name = name;
    this->age = age;
}

void Person::SetValues(string name, int age){
    this->name = name;
    this->age = age;
}

void Person::Print(){
    cout<<"----Details is printed from a non const memeber----"<<endl;
    cout<<"Name of person: "<<name<<endl;
    cout<<"Age of person: "<<age<<endl;
}

void Person::Print() const{
    cout<<"----Details is printed from a const memeber----"<<endl;
    cout<<"Name of person: "<<name<<endl;
    cout<<"Age of person: "<<age<<endl;
}


int main()
{
    const Person cp("Suraj",19);

    Person me;
    me.SetValues("Tarun",18);

    cp.Print();
    cout<<'\n';
    me.Print();

    return 0;
}