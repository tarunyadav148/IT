/*
    Modify the program 1, and ask the user to enter how many numbers do you want to reverse.
    Use a variable length array (VLA) for writing the program.
*/

#include<stdio.h>

int main()
{
    int size;

    printf("Enter the size of array: ");
    scanf("%d",&size);

    int arr[size];
    int temp;

    printf("Enter %d numbers: ",size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<size/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }

    printf("In reverse order: ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}