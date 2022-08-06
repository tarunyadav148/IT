#include<iostream>
#include<set>

using namespace std;

//Function for taking element of array from user
void get_array(int* arr,int size);

//Function to display element of array
void show_array(int* arr,int size);

void solve(int* a,int* b,int a_size,int b_size,int k){
    set<int> s;

    cout<<"All pairs who's sum is eqaul to "<<k<<": ";
    
    for(int i=0;i<b_size;i++){
        s.insert(k-b[i]);
    }

    for(int i=0;i<a_size;i++){
        auto itr = s.find(a[i]);
        if(itr!=s.end()){
            cout<<"("<<a[i]<<","<<k-(*itr)<<") ";
        }
    }
}

int main(){
    int a_size,b_size,k;

    cout<<"Enter size of array a: ";
    cin>>a_size;
    int* a = new int[a_size];

     cout<<"Enter size of array b: ";
    cin>>b_size;
    int* b = new int[b_size];

    cout<<"Enter element of array a: ";
    get_array(a,a_size);

    cout<<"Enter element of array b: ";
    get_array(b,b_size);

    cout<<"Enter the k:";
    cin>>k;

    solve(a,b,a_size,b_size,k);

    delete a;
    delete b;

    return 0;
}

void get_array(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}

void show_array(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}