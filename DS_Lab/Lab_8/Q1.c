#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

//Stack structure
typedef struct {
    int *arr;
    int top;
}Stack;

//Create a stack
Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack==NULL)
        return NULL;
    stack->arr = (int*)malloc(sizeof(int)*MAX_SIZE);
    if(stack->arr==NULL)
        return NULL;
    stack->top = -1;
    return stack;
}

//Checking overflow condition
int isFull(Stack* stack)
{
    if(stack->top == MAX_SIZE-1)
        return 1;
    return 0;
}

//Checking underflow condition
int isEmpty(Stack* stack)
{
    if(stack->top == -1)
        return 1;
    return 0;
}

//Push a element in stack
void push(Stack* stack, int num)
{
    if(isFull(stack))
    {
        printf("Stack is full\n");
        exit(0);
    }
    stack->arr[++stack->top] = num;
}

//Pop a element from stack
int pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty\n");
        exit(0);
    }
    return stack->arr[stack->top--];
}

//Checking top element of stack
int top(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty\n");
        exit(0);
    }
    return stack->arr[stack->top];
}

int main()
{
    Stack *stack = createStack();
    while(stack==NULL)
        stack = createStack();

    //checking underflow condition
    if(isEmpty(stack))
        printf("Stack is Empty\n");

    //Pushing some element in stack
    if(!isFull(stack))
        push(stack,4);
    if(!isFull(stack))
        push(stack,9);
    if(!isFull(stack))
        push(stack,17);
    if(!isFull(stack))
        push(stack,5);

    //Checking current top element
    printf("Current top of stack:%d\n",top(stack));

    //Poping each element from stack
    printf("Poping each element of stack:\n");

    while (!isEmpty(stack))
    {
        printf("%d\n",pop(stack));
    }
    
    return 0;
}