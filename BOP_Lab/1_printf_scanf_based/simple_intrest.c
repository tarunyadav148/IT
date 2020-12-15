#include<stdio.h>
#include<conio.h>

int main()
{
	long long int p;
	float r;
	int t;
	double si;
	
	printf("Enter the principal amount:");
	scanf("%lld",&p);
	printf("Enter the rate (in %%):");
	scanf("%f",&r);
	printf("Enter the time interval (in years):");
	scanf("%d",&t);
	
	si=(p*r*t)/100;
	printf("\n\nSimple intrest is:%lf",si);
	
	getch();
	return 0;
}
