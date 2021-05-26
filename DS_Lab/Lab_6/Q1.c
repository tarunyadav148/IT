#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* duplicate(char* str)
{
    char* dup = (char*)malloc(strlen(str)+1);
    if(dup==NULL)
        return NULL;
    strcpy(dup,str);
    return dup;
}

int main()
{
    char str[100];
    printf("Enter a string:");
    fgets(str,100,stdin);

    char *duplicateString = duplicate(str);

    printf("Duplicate string:%s",duplicateString);
    return 0;
}