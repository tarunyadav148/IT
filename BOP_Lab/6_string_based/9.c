#include<stdio.h>
#include<string.h>

void reverse(char string[])			//function to reverse the string
{
	char temp;
	int n=strlen(string),i;
	for(i=0;i<n/2;i++)
	{
		temp=string[i];
		string[i]=string[n-1-i];
		string[n-1-i]=temp;
	}
}

int main()
{
    char string1[100],string2[100];
    int i=0;

    gets(string1);					//let first string be abc
    gets(string2);					//let first string be xyz

    reverse(string1);				//reversing first string, now it is cba
    reverse(string2);				//reversing second string, now it is zyx
	strcat(string1,string2);		//concatinating second string in first string , now first string is cbazyx
	reverse(string1);				//reversing first string, now it is xyzabc
    
    printf("%s",string1);

    return 0;
}
