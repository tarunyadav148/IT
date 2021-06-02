#include<iostream>
#include<cmath>

using namespace std;

class shape
{
protected:
    double side1;
    double side2;
public:
    void get_data();
    virtual void display_area() = 0;
};

class RECTANGLE : public shape
{
public:
    void display_area();
};

class TRIANGLE : public shape
{
private:
    double side3;
public:
    void get_data();
    void display_area();
};

void shape::get_data()
{
    cout<<"Enter side 1:";
    cin>>this->side1;
    cout<<"Enter side 2:";
    cin>>this->side2;
}

void TRIANGLE::get_data()
{
    this->shape::get_data();
    cout<<"Enter side 3:";
    cin>>this->side3;;
}

void RECTANGLE::display_area()
{
    cout<<"Area of Rectangle: "<<side1*side2<<endl;
}

void TRIANGLE::display_area()
{
    double semiperi = (side1+side2+side3)/2.0;
    double area = sqrt(semiperi*(semiperi-side1)*(semiperi-side2)*(semiperi-side3));
    cout<<"Area of Triangle: "<<area<<endl;
}

int main()
{
    RECTANGLE rec;
    TRIANGLE tri;
    cout<<"Enter details of rectangle:"<<endl;
    rec.get_data();
    rec.display_area();
    cout<<'\n';
    cout<<"Enter details of triangle"<<endl;
    tri.get_data();
    tri.display_area();
    return 0;
}