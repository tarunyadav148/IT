#include<stdio.h>
#define MAX_SIZE 100

void display_reverse_message(char message[],int size)
{
    for (int i = size; i>=0; i--)
    {
        printf("%c",message[i]);
    }
    printf("\n");
    
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
}

int main()
{
    char message[MAX_SIZE];
    int sucussfully_readed_len = read_message(message);
    printf("Reversal is: ");
    display_reverse_message(message,sucussfully_readed_len);
    return 0;
}
