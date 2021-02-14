#include<stdio.h>

int main()
{
    char s[100],temp;
    int lenght=0,i;

    scanf("%s",s);

    while(s[lenght]!='\0')
    {
    	lenght++;
	}
    
    for(i=0;i<lenght/2;i++)
    {
    	temp=s[i];
    	s[i]=s[lenght-1-i];
    	s[lenght-1-i]=temp;
	}
    
    printf("%s",s);

    return 0;
}
