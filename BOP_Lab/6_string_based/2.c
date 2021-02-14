#include<stdio.h>

int main()
{
    char s[100];
    int i=0,count=0;

    gets(s);

    while(s[i]!='\0')
    {
    	if(s[i]=='A'){
    		count++;
		}
		i++;
	}
    
    printf("%d",count);

    return 0;
}
