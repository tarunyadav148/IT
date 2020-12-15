#include<stdio.h>
#include<conio.h>

int main()
{
	int num1,num2,add,sub,mul;
	
	printf("Enter first number:");
	scanf("%d",&num1);
	
	printf("\nEnter second number:");
	scanf("%d",&num2);
	
	add=num1+num2;
	printf("\nAddition of two numbers is:%d",add);
	
	sub=num1-num2;
	printf("\nSubtraction of second number from first number is:%d",sub);
	
	mul=num1*num2;
	printf("\nMultiplication of two numbers is:%d",mul);
	
	getch();
	return 0;
}
