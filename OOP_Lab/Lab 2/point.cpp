#include<iostream>

using namespace std;

struct point
{
    double x;
    double y;
};


int main()
{
    point p1,p2,p3;

    cout<<"Enter coordinate of first point: ";
    cin>>p1.x>>p1.y;

    cout<<"Enter coordinate of second point: ";
    cin>>p2.x>>p2.y;

    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    cout<<"The third point which is sum of two point are: "<<p3.x<<","<<" "<<p3.y;

}