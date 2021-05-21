#include<stdio.h>
#define MAX_SIZE 100

void display_reverse_message(char message[],char* p)
{
    for (p--;p>=message;p--)
    {
        printf("%c",*p);
    }
    printf("\n");
    
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

int main()
{
    char message[MAX_SIZE];
    char* p = read_message(message);
    printf("Reversal is: ");
    display_reverse_message(message,p);
    return 0;
}
