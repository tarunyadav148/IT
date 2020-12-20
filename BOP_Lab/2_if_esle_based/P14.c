#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,D,x1,x2;
    double y1,y2;  // in case of img root x1 real part of root y1 img part of root

    printf("Enter coefficient of x^2:");
    scanf("%lf",&a);
    printf("Enter coefficient of x:");
    scanf("%lf",&b);
    printf("Enter constant term:");
    scanf("%lf",&c);

    D=b*b-4*a*c;

    if(D>=0)
    {
        x1=((-b)+sqrt(D))/2.0;
        x2=((-b)-sqrt(D))/2.0;
        printf("Roots of equation are: %.2lf\t%.2lf",x1,x2);
    }
    else
    {
        x1=(-b)/2.0;
        x2=(-b)/2.0;
        y1=sqrt(-D)/2.0;
        y2=sqrt(-D)/2.0;
        printf("Roots of equation are:\n%.2lf + %.2lfi\n%.2lf + %.2lfi",x1,y1,x2,y2);
        
    }
    
    return 0;
}