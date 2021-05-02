#include<stdio.h>

int main()
{
    char string1[100],string2[100],string3[100];
    int lenght1=0,lenght2=0;

    gets(string1);
    gets(string2);

    while(string1[lenght1]!='\0')
    {
    	string3[lenght1]=string1[lenght1];			//storing string1 in string3
    	lenght1++;
	}
	
	while(string2[lenght2]!='\0')
    {
    	string3[lenght1+lenght2]=string2[lenght2];		//then storing string2 in string3
    	lenght2++;
	}
	
	string3[lenght1+lenght2]='\0';
    
    printf("%s",string3);

    return 0;
}
