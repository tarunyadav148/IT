#include<stdio.h>

int main()
{
    int hh,mm,ss;

    //Enter time in 24 hour format
    printf("Enter hour:");
    scanf("%d",&hh);
    printf("Enter minutes:");
    scanf("%d",&mm);
    printf("Enter seconds:");
    scanf("%d",&ss);

    //Checking for valid input 
    if(hh>12||mm>60||ss>60&&hh<0||mm<0||ss<0)
    {
        printf("Invaild input");
        return 0;
    }
    
    //main algo
    if (hh<12)
    {
        printf("Time:- %d:%d:%d AM",hh,mm,ss);
    }
    else if (hh==12)
    {
       printf("Time:- %d:%d:%d PM",hh,mm,ss);
    }
    
    else
    {
        printf("Time:- %d:%d:%d PM",hh-12,mm,ss);
    }
    

    return 0;
}