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

int read_message(char message[])
{
    char character;
    int size = MAX_SIZE;
    printf("Enter a message: ");
    for(int i=0;i<MAX_SIZE;i++)
    {
        character = getchar();
        if(character == '\n')
        {
            size = i;
            break;
        }
        message[i] = character;
    }

    return size;
}

int check_pallindrome(char message[],int size)
{
    int l=0,r=size-1;
    while(l<r)
    {
        if(!check_aplha(message[l])){
            l++;
            continue;
        }
        else if(!check_aplha(message[r])){
            r--;
        }
        else{
            char cl = getlower(message[l]);
            char cr = getlower(message[r]);
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
    int size = read_message(message);
    int flag = check_pallindrome(message,size);
    if(flag)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}