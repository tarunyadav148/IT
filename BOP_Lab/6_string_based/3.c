#include<stdio.h>

int main()
{
    char string1[100],string2[100];
    int i=0;

    gets(string1);

    while(string1[i]!='\0')
    {
    	string2[i]=string1[i];
    	i++;
	}
	
	string2[i]='\0';
    
    printf("%s",string2);

    return 0;
}
