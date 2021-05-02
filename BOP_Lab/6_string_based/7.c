#include<stdio.h>

int main()
{
    char s[100];
    int i=0,vowels=0,consonants=0,digist=0,others=0;

    gets(s);

    while(s[i]!='\0')
    {
    	if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
		{
    		vowels++;
		}
		else if((s[i]>'A'&&s[i]<'Z')||(s[i]>'a'&&s[i])){
			consonants++;
		}
		else
		{
			others++;
		}
		i++;
	}
    
    printf("Vowels:%d\n",vowels);
    printf("Consonants:%d\n",consonants);
    printf("Others:%d\n",others);

    return 0;
}
