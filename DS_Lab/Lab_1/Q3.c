/*
    WAP that checks whether any of digits in a number appear more than once. After the user enters
    a number, the program prints either Repeated digit or No repeated digit.
*/

#include<stdio.h>

int main()
{
    int num;

    printf("Enter a numeber: ");
    scanf("%d",&num);

    int arr[10]={0};
    int rem,not_repeated=1;

    while(num>0)
    {
        rem=num%10;
        arr[rem]++;
        num/=10;
        if(arr[rem]>1)
        {
            printf("Repeated digit");
            not_repeated=0;
            break;
        }

    }

    if(not_repeated)
    {
        printf("No repeated digit");
    }

    return 0;
}