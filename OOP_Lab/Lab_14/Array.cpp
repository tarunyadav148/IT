#include<iostream>

using namespace  std;

template<typename T>
class Array
{
private:
    T* arr;
    int size;
public:
    Array(int size);
    Array(Array<T>& array);
    ~Array();
    int Size();
    int binarySearch(T key);
    void SelectionSort();
    T& operator[](int i);
};

template<typename T>
Array<T>::Array(int size)
{
    arr = (T*)malloc(sizeof(T)*size);
    this->size = size;
}

template<typename T>
Array<T>::Array(Array<T>& array)
{
    this->size = array.size;
    arr = (T*)malloc(sizeof(T)*array.size);
    for(int i=0;i<array.size;i++)
        this->arr[i] = array.arr[i];
}

template<typename T>
Array<T>::~Array()
{
    free(arr);
}

template<typename T>
T& Array<T>::operator[](int i)
{
    return arr[i];
}

template<typename T>
int Array<T>::Size()
{
    return size;
}

template<typename T>
int Array<T>::binarySearch(T key)
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

template<typename T>
void Array<T>::SelectionSort()
{
    for(int i =0;i<size-1;i++)
    {
        int index_of_smallest = i;

        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[index_of_smallest])
                index_of_smallest = j;
        }
        
        T temp = arr[i];
        arr[i] = arr[index_of_smallest];
        arr[index_of_smallest] = temp;
    }
}



int main()
{
    int n;
    cout<<"Enter the size of Array:";
    cin>>n;
    Array<int> a(n);

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