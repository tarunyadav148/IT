#include<stdio.h>

int main()
{
    int num,sum;

    printf("Enter a number:");
    scanf("%d",&num);
    
    sum=num+(num+1);

    if(1)
        printf("Sum of number with a number one greater than this:%d",sum);

    return 0;
}