#include<iostream>

using namespace  std;

class Array
{
private:
    int* arr;
    int size;
public:
    Array(int size);
    Array(Array& array);
    ~Array();
    int Size();
    int binarySearch(int key);
    void SelectionSort();
    int& operator[](int i);
};

Array::Array(int size)
{
    arr = (int*)malloc(sizeof(int)*size);
    this->size = size;
}

Array::Array(Array& array)
{
    this->size = array.size;
    arr = (int*)malloc(sizeof(int)*array.size);
    for(int i=0;i<array.size;i++)
        this->arr[i] = array.arr[i];
}

Array::~Array()
{
    free(arr);
}

int& Array::operator[](int i)
{
    return arr[i];
}

int Array::Size()
{
    return size;
}

int Array::binarySearch(int key)
{
    int low = 0;
    int high = size-1;
    int mid;
    while (low<=high)
    {
        int mid = (low+high)/2;

        if(arr[mid]==key)
            return mid;
        if(key>arr[mid])
            low = mid+1;
        else
            high = mid-1;
    }

    return -1;
}

void Array::SelectionSort()
{
    for(int i =0;i<size-1;i++)
    {
        int index_of_smallest = i;

        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[index_of_smallest])
                index_of_smallest = j;
        }
        
        int temp = arr[i];
        arr[i] = arr[index_of_smallest];
        arr[index_of_smallest] = temp;
    }
}



int main()
{
    int n;
    cout<<"Enter the size of Array:";
    cin>>n;
    Array a(n);

    cout<<"Enter element of Array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    a.SelectionSort();
    cout<<"Element of Array in sorted oreder: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;

    int key;
    cout<<"Enter element you want to find in array: ";
    cin>>key;
    if(a.binarySearch(key)==-1)
    {
        cout<<"ELement not found"<<endl;
    }
    else{
        cout<<"Element is at "<<a.binarySearch(key)<<" index"<<endl;
    }
    return 0;
}