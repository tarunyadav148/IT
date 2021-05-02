#include<stdio.h>

void split_date(int day_of_year, int year,int *month,int *day)
{
    int leap = 0;

    if(year%400==0)
        leap = 1;
    else if(year%100==0)
        leap = 0;
    else if(year%4==0)
        leap  = 1;


    if(day_of_year>=0&&day_of_year<=31)
    {
        *day=day_of_year;
        *month=1;
    }
    else if(day_of_year>31&&day_of_year<=(59+leap))
    {
        *day=day_of_year-31;
        *month=2;
    }
    else if(day_of_year>(59+leap)&&day_of_year<=(90+leap))
    {
        *day=day_of_year-(59+leap);
        *month=3;
    }
    else if(day_of_year>(90+leap)&&day_of_year<=(120+leap))
    {
        *day=day_of_year-(90+leap);
        *month=4;
    }
    else if(day_of_year>(120+leap)&&day_of_year<=(151+leap))
    {
        *day=day_of_year-(120+leap);
        *month=5;
    }
    else if(day_of_year>(151+leap)&&day_of_year<=(181+leap))
    {
        *day=day_of_year-(151+leap);
        *month=6;
    }
    else if(day_of_year>(181+leap)&&day_of_year<=(212+leap))
    {
        *day=day_of_year-(181+leap);
        *month=7;
    }
    else if(day_of_year>(212+leap)&&day_of_year<=(243+leap))
    {
        *day=day_of_year-(212+leap);
        *month=8;
    }else if(day_of_year>(243+leap)&&day_of_year<=(273+leap))
    {
        *day=day_of_year-(243+leap);
        *month=9;
    }
    else if(day_of_year>(273+leap)&&day_of_year<=(304+leap))
    {
        *day=day_of_year-(273+leap);
        *month=10;
    }

    else if(day_of_year>(304+leap)&&day_of_year<=(334+leap))
    {
        *day=day_of_year-(304+leap);
        *month=11;
    }
    else if(day_of_year>(334+leap)&&day_of_year<=(365+leap))
    {
        *day=day_of_year-(334+leap);
        *month=12;
    }
}

int main()
{
    int day_of_year,year;
    int month,day;

    printf("Enter day of year and year: ");
    scanf("%d%d",&day_of_year,&year);

    split_date(day_of_year,year,&month,&day);

    printf("Month:%d  Day:%d",month,day);

    return 0;
}