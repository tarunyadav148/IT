#include<stdio.h>
#include<limits.h>

//Fuction for getting largest and second largest
void find_two_largest(int a[],int n,int *largest,int *second_largest);

//Function for taking element of array from user
void get_array(int arr[],int size);

//Function to display element of array
void show_array(int arr[],int size);

int main()
{
    int size,largest,second_largest;

    printf("Enter size of array: ");
    scanf("%d",&size);

    int arr[size];

    printf("Enter element of array: ");
    get_array(arr,size);

    find_two_largest(arr,size,&largest,&second_largest);

    printf("Largest:%d      Second largest:%d",largest,second_largest);

    return 0;
}

void get_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void show_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

void find_two_largest(int a[],int n,int *largest,int *second_largest)
{
    *largest = INT_MIN;
    *second_largest = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>*largest){
            *second_largest = *largest;
            *largest = a[i];
        }
        else if(a[i]>*second_largest)
        {
            *second_largest = a[i];
        }
    }
}