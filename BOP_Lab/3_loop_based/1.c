#include<stdio.h>

int main()
{
    int N,count=1;

    printf("Enter N:");
    scanf("%d",&N);

    while (count<=N)
    {
        printf("Hello\n");
        count++;
    }
    
    return 0;
}