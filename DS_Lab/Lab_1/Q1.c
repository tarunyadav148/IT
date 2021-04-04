/*
    Write a program (WAP) that prompts the user to enter a series of numbers, then writes the
    numbers in reverse order. Further, use a macro to define the length of the array.
*/

#include<stdio.h>
#define SIZE 10

int main()
{
    int arr[SIZE];
    int temp;
    
    printf("Enter 10 numbers: ");   //Taking input
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < SIZE/2; i++)  //Rerversing the array
    {
        temp = arr[i];
        arr[i] = arr[SIZE-1-i];
        arr[SIZE-1-i] = temp;
    }

    printf("In reverse order: ");    //Printing output
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
    
}

