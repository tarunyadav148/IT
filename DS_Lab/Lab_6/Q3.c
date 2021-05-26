#include<stdio.h>
#include<stdlib.h>

struct  point{ int x, y; };
struct rectangle{ struct point upper_left, lower_right; };
struct rectangle *p;


int main()
{
    p = (struct rectangle*)malloc(sizeof(struct rectangle));
    p->upper_left.x = 10;
    p->upper_left.y = 25;
    p->lower_right.x = 20;
    p->lower_right.y = 15;

    printf("Coordinate of rectangle p are: \n");
    printf("Upper left corner: (%d,%d)\n",p->upper_left.x,p->upper_left.y);
    printf("Lower right corner: (%d,%d)\n",p->lower_right.x,p->lower_right.y);
    return 0;
}