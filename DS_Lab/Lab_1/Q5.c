/*
    Modify the program 3, so that it prints a table showing how many times each digit appears in
    the number:
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

    printf("Digits:      ");
    for(int i=0;i<10;i++)
    {
        printf("%d ",i);
    }

    printf("\n");

    printf("Occurrences: ");
    for (int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}