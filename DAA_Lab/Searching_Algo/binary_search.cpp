#include<iostream>
#include<algorithm>
using namespace std;

bool BinarySearch(int array[],int size,int key)
{
    int low = 0 , high = size-1, mid;

    while(low<=high){
        mid = (low+high)/2;

        if(key == array[mid])
            return true;

        else if(array[mid]<key)
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
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

    if(BinarySearch(array,length,key))
        cout<<"Element found in array";
    else
        cout<<"Element not found in array";

    return 0;
}