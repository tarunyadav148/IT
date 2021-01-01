#include<stdio.h>

int main()
{
    int marks;

    printf("Enter the total marks:");
    scanf("%d",&marks);

    if(marks>=85)
    {
        printf("Grade:A+");
    }
    else if(marks>=75)
    {
        printf("Grade:A");
    }
    else if(marks>=65)
    {
        printf("Grade:B");
    }
    else if(marks>=50)
    {
        printf("Grade:C");
    }
    else if(marks>=40)
    {
        printf("Grade:C");
    }
    else
    {
        printf("Grade:E");
    }

    return 0;

}