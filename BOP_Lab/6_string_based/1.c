#include<stdio.h>

int main()
{
    char string[100];
    int lenght=0;	

    gets(string);		

    while(string[lenght]!='\0')
    {
    	lenght++;
	}
    
    printf("%d",lenght);

    return 0;
}
