#include<stdio.h>

int main()
{
    int n,temp=1,count=1;
    int sum=0;

    printf("Enter n:");
    scanf("%d",&n);

    while (count<=n)
    {
        if(count==1)
        {
            printf("%d",count);
            sum+=count;
        }
        else
        {
            printf("+%d",count);
            sum+=count;
        }
          count++;     
    } 
    
    printf("\n=%d",sum);
    count=1;
    sum=0;

    while (count<=n)
    {  
        if(temp==1)
        {
            printf("\n%d",temp);
            sum+=temp;
            temp=5*count;
        }
        else
        {
            printf("+%d",temp);
            sum+=temp;
            temp=5*count;
        }
        count++;
    }

    printf("\n=%d",sum);
    count=1;
    temp=1;
    sum=0;

     while (count<=n)
    {  
        if(temp==1)
        {
            temp*=2;
            printf("\n%d",temp);
            sum+=temp;
        }
        else
        {
            temp*=2;
            printf("+%d",temp);
            sum+=temp;
        }
        count++;
    }

    printf("\n=%d",sum);

    
    
    return 0;
}