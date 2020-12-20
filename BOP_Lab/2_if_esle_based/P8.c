#include<stdio.h>
#include<math.h>

int main()
{
    double cent,feets,inches;

    printf("Enter length in centimeters:");
    scanf("%lf",&cent);
    
    if(cent<30.48)
    {
        inches=cent/2.54;
        printf("Length is: %lf feets %lf inches",feets,inches);
    }
    else
    {
        feets=round(cent/30.48);
        inches=cent/2.54;
        printf("Length is: %lf feets %lf inches",feets,inches);
    }
    
    return 0;
}