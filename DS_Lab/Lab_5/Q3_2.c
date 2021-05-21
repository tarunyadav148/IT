#include<stdio.h>
#define MAX_SIZE 100

int check_aplha(char c)
{
    return ((c>='A'&&c<='Z')||(c>='a'&&c<='z'));
}

char getlower(char c)
{
    if(c>='A'&&c<='Z')
        return c+32;
    return c;
}

char* read_message(char message[])
{
    char character;
    char *p;
    printf("Enter a message: ");
    for(p=message;p<message+MAX_SIZE;p++)
    {
        character = getchar();
        if(character == '\n')
        {
            break;
        }
        *p = character;
    }
    return p;
}

int check_pallindrome(char message[],char* p)
{
    char *l=message,*r=p-1;
    while(l!=r)
    {
        if(!check_aplha(*l)){
            l++;
            continue;
        }
        else if(!check_aplha(*r)){
            r--;
        }
        else{
            char cl = getlower(*l);
            char cr = getlower(*r);
            if(cl!=cr)
                return 0;
            l++;
            r--;
        }
    }
    return 1;
}

int main()
{
    char message[MAX_SIZE];
    char* p = read_message(message);
    int flag = check_pallindrome(message,p);
    if(flag)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}