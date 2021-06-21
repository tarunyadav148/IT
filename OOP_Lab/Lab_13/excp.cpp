#include<iostream>
#include<cstdlib>

using namespace std;

void func()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    if(n>0){
        throw n;
    }else{
        throw n/2.0f;
    }
}

int main()
{
    srand(time(NULL));
    int num = rand()%3;

    if(num==0){
        func();
    }
    else if(num==1){
        try
        {
            func();
        }
        catch(int i)
        {
            cout<<"Exception occur:"<<i<<endl;
        }
        catch(float f)
        {
            cout<<"Exception occur:"<<f<<endl;
        }
    }
    else if(num==2){
        try
        {
            func();
        }
        catch(...)
        {
            cout<<"Exception occur"<<endl;
        }

    }

    return 0;
}