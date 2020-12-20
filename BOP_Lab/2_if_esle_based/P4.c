#include<stdio.h>
int main()
{
    int num1,num2;

    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    if(num1==num2)
        printf("Numbers are equal");
    else
        if (num1>num2)
        {
            printf("First number %d is greater",num1);

        }
        else  
        {
            printf("Second number %d is greater",num2);
        }

        return 0;
}