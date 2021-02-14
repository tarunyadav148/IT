#include<stdio.h>

struct date
{
    int dd;
    int mm;
    int yyyy;

};

struct date input()			//function to take data input from user
{
    struct date d;
    printf("Enter (dd/mm/yyyy or d/mm/yyyy or d/m/yyyy):");
    scanf("%d/%d/%d",&d.dd,&d.mm,&d.yyyy);
    return d;
}

void compare_date(struct date d1,struct date d2)		//function comparing two dates
{
    if(d1.dd==d2.dd&&d1.mm==d2.mm&&d1.yyyy==d2.yyyy)	//! operator used as strcmp() return 0 if string are equal
    {
        printf("\nDates are equal\n");
    }
	else
	{
        printf("\nDate are not equal\n");
    }
}


int main()
{

    struct date d1=input();
    struct date d2=input(); 

    compare_date(d1,d2);  
    
    return 0;
}
