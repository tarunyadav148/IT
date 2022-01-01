#include<iostream>
using namespace std;

bool LinearSearch(int array[],int size,int key)
{
    bool flag = false;

    for(int i=0;i<size;i++)
        if(key==array[i])
            flag = true;
    
    return flag;
}

int main(){

    int length;
    cout<<"Enter lenght of array:";
    cin>>length;

    int array[length];

    cout<<"Enter elements of array:";
    for(int i=0;i<length;i++)
        cin>>array[i];

    int key;
    cout<<"Enter element want to search in array:";
    cin>>key;

    if(LinearSearch(array,length,key))
        cout<<"Element found in array";
    else
        cout<<"Element not found in array";

    return 0;
}