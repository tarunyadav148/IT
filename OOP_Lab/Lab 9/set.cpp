#include<iostream>

using namespace std;

class set
{
private:
    int* arr;
    int size;
    int capacity;
    int binarySearch(int key) const;
public:
    set();
    set(set &st);
    ~set();
    int* begin();   //give pointer to first element
    int* end();     //give imaginary pointer to just after last element
    void insert(int element);      // to add a element
    void insert(int n,int* list);  // n:size of list and list: pointer of list
    void print();
    set& Union(const set& s);
    set& Intersection(const set& s);
    set& Subtraction(const set& s);
};

set::set()
{
    arr = NULL;
    size = 0;
    capacity = 1;
}

set::~set()
{
    free(arr);
}

set::set(set &st)
{
    size = st.size;
    capacity = st.capacity;
    arr = (int*)malloc(sizeof(int)*st.size);
    for(int i=0;i<st.size;i++)
    {
        arr[i] = st.arr[i];
    }
}

inline int* set::begin()
{
    return arr;
}

inline int* set::end()
{
    return arr+size;
}

int set::binarySearch(int key) const
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

void set::insert(int element)
{
    if(size==capacity-1)
    {
        capacity = capacity*2;
        arr = (int*)realloc(arr,capacity*sizeof(int));
    }

    if(this->binarySearch(element)==-1)
    {
        int i = size;
        while(arr[i-1]>element&&i>0)
        {
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = element;
        size++;
    }
    
}

void set::print()
{
    for(auto itr = this->begin() ; itr!= this->end() ; itr++)
    {
        cout<<*itr<<" ";
    }
}

void set::insert(int n,int* list)
{
    for(int i=0;i<n;i++)
    {
        this->insert(list[i]);
    }
}

set& set::Union(const set& s)
{
    set *un = new set;
    for(int i=0;i<s.size;i++)
        un->insert(s.arr[i]);
    for(int i=0;i<this->size;i++)
        un->insert(this->arr[i]);

    return *un;
}

set& set::Intersection(const set& s)
{ 
    set *intersection = new set;
    if(this->size<s.size)
    {   
        for(int i = 0; i<this->size; i++)
        {
            if(s.binarySearch(this->arr[i]) != -1)
            {
               intersection->insert(this->arr[i]);
            }
        }
    }
    else
    {
        for(int i = 0; i<s.size; i++)
        {
            if(this->binarySearch(s.arr[i]) != -1)
            {
                intersection->insert(s.arr[i]);
                
            }
        }
    }
    return *intersection;
}

set& set::Subtraction(const set& s)
{
    set *sub = new set;
    for(int i=0;i<this->size;i++)
    {
        if(s.binarySearch(this->arr[i])==-1)
            sub->insert(this->arr[i]);
    }

    return *sub;
}

int main()
{
    int a[]={5,4,4,4,3,2};
    int b[]={1,4,-1,6};

    set s1,s2;

    s1.insert(6,a);
    s2.insert(4,b);
    s1.insert(1);
    s1.insert(1);

    cout<<"Element of s1: ";
    s1.print();
    cout<<endl;

    cout<<"Element of s2: ";
    s2.print();
    cout<<endl;

    set Union = s1.Union(s2);
    cout<<"Element of union of s1 and s2: ";
    Union.print();
    cout<<endl;
    
    set intersection = s1.Intersection(s2);
    cout<<"Element of intersection of s1 and s2: ";
    intersection.print();
    cout<<endl;

    set subtration = s1.Subtraction(s2);
    cout<<"Subtraction of element of s2 from s1: ";
    subtration.print();
    cout<<endl;

    return 0;
}