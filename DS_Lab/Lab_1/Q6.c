/*
    Modify the program 3, so that the user can enter more than one number to be tested for repeated
    digits. The program should terminate when the user enters a number that is less than or equal to 0.
*/

#include<stdio.h>

int check_repeated(int num)
{
    int arr[10]={0};
    int rem,repeated=0;

    while(num>0)
    {
        rem=num%10;
        arr[rem]++;
        num/=10;
        if(arr[rem]>1)
        {
            repeated=1;
            break;
        }
    }

    return repeated;
}

int main()
{
    int num;

    printf("Enter a numeber: ");
    scanf("%d",&num);

    while(num>0)
    {
        if(check_repeated(num))
        {
            printf("Repeated digit\n");
        }
        else{
            printf("No repeated digit\n");
        }
        printf("Enter a numeber: ");
        scanf("%d",&num);
    }

    return 0;
}