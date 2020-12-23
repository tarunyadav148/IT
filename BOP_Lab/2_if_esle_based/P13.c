#include<stdio.h>
int main()
{
	//variable used
	int num,years,months,days,leap_years;
	int dd,mm,yyyy;
	
	//inputing requiered data
	printf("Enter number of days:");
	scanf("%d",&num);
	printf("Enter current date(dd mm yyyy):");
	scanf("%d%d%d",&dd,&mm,&yyyy);

	//calculating by taking standard values
	years=num/365;
	months=(num%365)/31;
	days=(num%365)%31;
	leap_years=((yyyy%4)+years)/4;
	
	//calculating corrections too make output more correct
	int c1=2-mm,c2=4-mm,c3=6-mm,c4=9-mm,c5=11-mm;
	if(c1<=0) c1+=12;
	if(c2<=0) c2+=12;
	if(c3<=0) c3+=12;
	if(c4<=0) c4+=12;
	if(c5<=0) c5+=12;

		if(months>=c1)
		{
			days-=3;
		}
		if(months>=c2)
		{
			days-=1;
		}
		if(months>=c3)
		{
			days-=1;
		}
		if(months>=c4)
		{
			days-=1;
		}
		if(months>=c5)
		{
			days-=1;
		}
	if(days<0)
	{
		months--;
		days+=31;
		if(months>=c1)
		{
			days-=3;
		}
		if(months>=c2)
		{
			days-=1;
		}
		if(months>=c3)
		{
			days-=1;
		}
		if(months>=c4)
		{
			days-=1;
		}
		if(months>=c5)
		{
			days-=1;
		}

		if(months<0)
		{
		years--;
		if(years<0)
			{
			  months=11;
			}
		}
		
	}

	printf("Output:- %d year:%d months:%d days",years,months,days);
	printf("\nNumber of leap year:%d",leap_years);
	
	return 0;
}
