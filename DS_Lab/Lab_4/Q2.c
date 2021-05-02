#include<stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *sec = (total_sec)%60;
    *min = ((total_sec)/60)%60;
    *hr = (total_sec)/(60*60);
}

int main()
{
    int total_sec,hr,min,sec;

    printf("Enter total sec: ");
    scanf("%d",&total_sec);

    split_time(total_sec,&hr,&min,&sec);

    printf("hr:%d  min:%d  sec:%d  ",hr,min,sec);
    
    return 0;
}