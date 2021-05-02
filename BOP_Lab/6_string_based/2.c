#include<stdio.h>

int main()
{
    char string[100];
    int i=0,count=0;

    gets(string);

    while(string[i]!='\0')
    {
    	if(string[i]=='A'){
    		count++;
		}
		i++;
	}
    
    printf("%d",count);

    return 0;
}
