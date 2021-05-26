#include<stdio.h>
#include<stdlib.h>

int *create_array(int n, int intial_value)
{
    int *array = (int*)malloc(sizeof(int)*n);
    if(array == NULL)
        return NULL;
    for(int i=0;i<n;i++)
        array[i] = intial_value;
    return array;
}

int main()
{
    int size,intial_value;

    printf("Enter size of array and intial value:");
    scanf("%d%d",&size,&intial_value);
    int *arr = create_array(size,intial_value);

    printf("Array: ");

    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);

    printf("\n");

    return 0;
}