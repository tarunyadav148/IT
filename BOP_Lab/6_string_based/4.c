#include<stdio.h>

int main()
{
    char string[100],temp;
    int lenght=0,i;

    scanf("%s",string);

    while(string[lenght]!='\0')		//counting lenght of string
    {
    	lenght++;
	}
    
    for(i=0;i<lenght/2;i++)
    {
    	temp=string[i];
    	string[i]=string[lenght-1-i];
    	string[lenght-1-i]=temp;
	}
    
    printf("%s",string);

    return 0;
}
