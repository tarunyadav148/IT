#include<stdio.h>

int main()
{
    int num,flag;

    printf("Enter a number:");
    scanf("%d",&num);
    
    flag=num%2;

    if(flag==0)
        printf("Number is even.");
    else
        printf("Number is odd.");
    
    return 0;
}