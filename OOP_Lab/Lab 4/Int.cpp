#include<iostream>
using namespace std;

class Int
{
private:
    int i;
public:
    Int()
    {
        i = 0;
    }
    Int(int x);
    void show();
    Int add(Int);

};

Int::Int(int x)
{
    i = x;
}


int main()
{
    Int a(5),b(6),c;

    c = a.add(b);

    c.show();

    return 0;
}

void Int::show()
{
    cout<<"VALUE: "<<i;
}

Int Int::add(Int b)
{
    return Int(i+b.i);
}