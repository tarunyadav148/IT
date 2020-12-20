#include<stdio.h>
int main()
{
    int num1,num2,result;

    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);

    if (num1>num2)
    {
        result=num1+num2;
        printf("Result:%d",result);
    }
    else  
    {
        result=num1-num2;
        printf("Result:%d",result);
    }

    return 0;
}