#include<stdio.h>

int sum_array(const int a[],int n)
{
    int sum,*p;
    
    sum=0;
    for(p=a;p<a+n;p++)
        sum += *p;
    return sum;
}

void get_array(int arr[],int size);

int main()
{
    int n;

    printf("Enter size of array:");
    scanf("%d",&n);

    int a[n];

    printf("Enter array elements: ");
    get_array(a,n);

    int sum = sum_array(a,n);

    printf("Sum of array: %d\n",sum);

    return 0;
}

void get_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}