#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    
    try{
        if(n>0){
            throw 1;
        }
        else{
            throw 1.5f;
        }
    }
    catch(...){
        cout<<"Exception occur"<<'\n';
    }

    return 0;
}