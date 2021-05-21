#include<iostream>

using namespace std;

class Distance 
{
 private: 
    int feet;
    float inches;
public: 
    Distance();
    void getDist();
    void showDist();
    void divide(int n);
    friend Distance dist_add(Distance d[100],int n);
};

Distance dist_add(Distance d[100],int n);

int main()
{
    int n;

    cout<<"Enter the number of distance you want enter: ";
    cin>>n;

    Distance d[100];

    cout<<'\n';

    for(int i=0;i<n;i++){
        cout<<"Input distance "<<i+1<<" :"<<endl;
        d[i].getDist();
        d[i].divide(n);
    }

    Distance average = dist_add(d,n);

    cout<<"\nAverage of "<<n<<" distance object is: "<<endl;
    average.showDist();
    
    return 0;
}

Distance::Distance(){
    this->feet  = 0;
    this->inches = 0;
}

void Distance::getDist(){
    cout<<"Enter feet:";
    cin>>this->feet;
    cout<<"Enter inches:";
    cin>>this->inches;
}

void Distance::showDist(){
    cout<<"Feet: "<<this->feet<<endl;
    cout<<"Inches: "<<this->inches<<endl;
}

void Distance::divide(int n){
    this->inches += ((this->feet%n)*12);
    this->inches =  this->inches/float(n);
    this->feet /= n;
}

Distance dist_add(Distance d[],int n){
    Distance avg;
    for(int i=0;i<n;i++){
        avg.feet += d[i].feet;
        avg.inches += d[i].inches;
    }
    avg.feet += avg.inches/12;
    avg.inches = avg.inches - int(avg.inches/12)*12;
    return avg;
}