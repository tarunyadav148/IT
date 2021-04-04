/*
    Modify the program 3, so that it shows which digits (if any) were repeated:
*/

#include<stdio.h>

int main()
{
    int num;

    printf("Enter a numeber: ");
    scanf("%d",&num);

    int arr[10]={0};
    int rem;

    while(num>0)
    {
        rem=num%10;
        arr[rem]++;
        num/=10;
    }

    printf("Repeated digit(s): ");

    for (int i = 0; i < 10 ; i++)
    {
        if(arr[i]>1)
        {
            printf("%d ",i);
        }
    }

    return 0;
}