#include<stdio.h>

int main()
{
    int num1,num2,num3;

    printf("Enter three distinct number\n");
    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    printf("Enter third number:");
    scanf("%d",&num3);

    if(num1>num2)
    {
        if(num1>num3)
        {
            printf("First number %d is greatest\n",num1); 
                if(num2>num3)
                {
                    printf("Second number %d is smallest",num2);
                }
                else
                {
                    printf("Third number %d is smallest",num3);
                }
            
        }
        else
        {
            printf("Third number %d is greatest\n",num3);
                printf("Second number %d is smallest",num2);
        }
        
    }
    else
    {
        if(num2>num3)
        {
            printf("Second number %d is greatest\n",num2);
                if(num1>num3)
                {
                    printf("First number %d is smallest",num1);
                }
                else
                {
                    printf("Third number %d is smallest",num3);
                }
        }
        else
        {
            printf("Third number %d is greatest\n",num3);
                printf("First number %d is smallest",num1); 
        }
        
    }
    
   return 0;
}