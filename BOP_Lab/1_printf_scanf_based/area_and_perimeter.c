#include<stdio.h>
#include<conio.h>
#include<math.h>
#define pi 22/7

int main()
{
	double rad,side_sqr,side_rect_1,side_rect_2;
	double side_tri_1,side_tri_2,side_tri_3,semi_peri;    //Sides of triangle
	double peri_cir,peri_tri,peri_sqr,peri_rect;
	double area_cir,area_tri,area_sqr,area_rect;
	
	//Taking inputs from user
	printf("Enter radius of circle:");
	scanf("%lf",&rad);
	printf("\nEnter sides of triangle:");
	scanf("%lf %lf %lf",&side_tri_1,&side_tri_2,&side_tri_3);
	printf("\nEnter side of square:");
	scanf("%lf",&side_sqr);
	printf("\nEnter sides of rectangle:");
	scanf("%lf%lf",&side_rect_1,&side_rect_2);
	
	//Perimeter and area of circle
	peri_cir=2*pi*rad;
	area_cir=pi*rad*rad;
	printf("\n\nPerimeter of circle:%lf",peri_cir);
	printf("\nArea of circle:%lf",area_cir);
	
	//Perimeter and area of triangle
	peri_tri=side_tri_1+side_tri_2+side_tri_3;
	semi_peri=peri_tri/2;
	area_tri=sqrt(semi_peri*(semi_peri-side_tri_1)*(semi_peri-side_tri_2)*(semi_peri-side_tri_3));
	printf("\n\nPerimeter of triangle:%lf",peri_tri);
	printf("\nArea of triangle:%lf",area_tri);
	
	//Perimeter and area of square
	peri_sqr=4*side_sqr;
	area_sqr=side_sqr*side_sqr;
	printf("\n\nPerimeter of square:%lf",peri_sqr);
	printf("\nArea of square:%lf",area_sqr);
	
	//Perimeter and area of rectangle
	peri_rect=2*(side_rect_1+side_rect_2);
	area_rect=side_rect_1*side_rect_2;
	printf("\n\nPerimeter of rectangle:%lf",peri_rect);
	printf("\nArea of rectangle:%lf",area_rect);
	
	getch();
	return 0;
}
