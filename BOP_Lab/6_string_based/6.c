#include<stdio.h>

int main()
{
    char string[100];
    int i=0,count=0;

    gets(string);

    while(string[i]!='\0')
    {
    	if(string[i]>'A'&&string[i]<'Z')		//counting how many uppercase character is present in string
		{
    		count++;
		}
		i++;
	}
    
    printf("%d",count);

    return 0;
}
