#include<stdio.h>

int main()
{
    char s[100];
    int lenght=0;

    gets(s);

    while(s[lenght]!='\0')
    {
    	lenght++;
	}
    
    printf("%d",lenght);

    return 0;
}
