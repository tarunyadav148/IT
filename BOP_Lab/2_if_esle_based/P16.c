#include<stdio.h>
#include<conio.h>


int main()
{
	int a, b, c, d;
    int largest, smallest;

    printf( "Enter four integers (separate them with spaces): " );
    scanf( "%d %d %d %d", &a, &b, &c, &d );


    largest = smallest = a;

    if ( largest < b )
    {
        largest = b;
    }
    else if ( b < smallest )
    {
        smallest = b;
    }
    if ( largest < c )
    {
        largest = c;
    }
    else if ( c < smallest )
    {
        smallest = c;
    }
    if ( largest < d )
    {
        largest = d;
    }
    else if ( d < smallest )
    {
        smallest = d;
    }

    printf( "\nLargest: %d\n", largest );
    printf( "Smallest: %d", smallest );
	
	return 0;
}
