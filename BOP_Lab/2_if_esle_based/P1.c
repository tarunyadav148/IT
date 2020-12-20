#include<stdio.h>

int main()
{
    int num1,num2;

    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);

    if (num1>num2)
    printf("First number %d is greater",num1);
    if (num2>num1)
    printf("Second number %d is greater",num2);

    return 0;
}