#include<iostream>

using namespace std;

template<typename T>
T largest(T num1,T num2)
{
    return num1>num2?num1:num2;
}

int main()
{
    float a =5.4, b=4.3;

    cout<<"Largest:"<<largest(a,b)<<endl;

    return 0;
}