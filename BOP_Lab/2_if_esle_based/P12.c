#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter numbers");
	scanf("%d%d%d",&a,&b,&c);
	
	if(a>b)
	{
		if(c>a)	
		printf("Max no. is %d and min no. is %d",c,b);
		if(b>c)
		printf("Max no. is %d and min no. is %d",a,c);
	}
		
		if(b>a)
		{
			if(c>b)
				printf("Max no. is %d and min no. is %d",c,a);
				if(a>c)
					printf("Max no. is %d and min no. is %d",b,c);
		}
	
	}
		
	
