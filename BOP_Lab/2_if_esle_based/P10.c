#include<stdio.h>

int main()
{
    int num1,num2,num3;
    
    printf("Enter three non distinct number:");
    scanf("%d%d%d",&num1,&num2,&num3);

    //All equal
    if(num1==num2&&num2==num3)
    {
        printf("All are equal");
    }
    else
    {
        //Two equal one distinct
         if (num1==num2&&num1>num3)
        {
            printf("The greatest number is: %d",num1);
        }
        else if (num1==num2&&num1<num3)
        {
             printf("The greatest number is: %d",num3);
        }
        
        else if (num2==num3&&num2>num1)
        {
            printf("The greatest number is: %d",num2);
        }
        else if (num2==num3&&num2<num1)
        {
            printf("The greatest number is: %d",num1);
        }
        else if (num1==num3&&num1>num2)
        {
            printf("The greatest number is: %d",num1);
        }
        else if (num1==num3&&num1<num2)
        {
            printf("The greatest number is: %d",num2);
        }
        else
        {
            printf("Invalid input: all numbers are distinct");
        }
    }
    
    

    return 0;
}