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
    Int(int a)
    {
        i = a;
    }
    void show();
    void add(Int,Int);

};
int main()
{
    Int p(14),q(19),r;
    r.add(p,q);
    r.show();
    return 0;
}

void Int::show()
{
    cout<<i;
}

void Int::add(Int p,Int q)
{
    i = p.i+q.i;
}