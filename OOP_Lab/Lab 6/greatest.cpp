#include<iostream>

using namespace std;

class B;

class A{
    int x;
    public:
        A(int x){
            this->x = x;
        }
        friend int Greatest(A a,B b);
};

class B{
    int y;
    public:
        B(int y){
            this->y = y;
        }
        friend int Greatest(A a,B b);
};

int main()
{
    A a(8);
    B b(15);

    int greatest = Greatest(a,b);

    cout<<"Greatest is: "<<greatest<<endl;

    return 0;
}

int Greatest(A a,B b){
    return (a.x>b.y)?a.x:b.y;
}