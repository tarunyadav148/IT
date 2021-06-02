/*
    Assumptions and limitations:
    1)Operand must be variable having single word name
    2)Operator must be arithmetic operator (%,*,/,+,-,)
    3)Expression must be a valid infix
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_SIZE 100

//Structure of stack
typedef struct{
    char *arr;
    int top;
}Stack;

//Create a stack
Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack==NULL)
        return NULL;
    stack->arr = (char*)malloc(sizeof(char)*MAX_SIZE);
    if(stack==NULL)
        return NULL;
    stack->top = -1;
    return stack;
}

//Checking stack is full
int isFull(Stack* stack)
{
    if(stack->top == MAX_SIZE-1)
        return 1;
    return 0;
}

//Checking stack is empty
int isEmpty(Stack* stack)
{
    if(stack->top == -1)
        return 1;
    return 0;
}

//Push an element in stack
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
char pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty\n");
        exit(0);
    }
    return stack->arr[stack->top--];
}

//Checking top of the stack
char top(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty\n");
        exit(0);
    }
    return stack->arr[stack->top];
}

//Check whether a bracket is opening or not
int isOpenParenthesis(char c)
{
    if(c=='(' || c=='{' || c=='[')
        return 1;
    return 0;
}

//Check whether a bracket is closing or not
int isCloseParenthesis(char c)
{
    if(c==')' || c=='}' || c==']')
        return 1;
    return 0;
}

/*
    Checking whether an operator on top
    has more precedence than current
    operator.
*/
int preced(char topOperator, char currOperator)
{
    if (topOperator=='+'||topOperator=='-')
    {
        if(currOperator=='-'||currOperator=='+')
            return 1;
        else
            return 0;
    }

    return 1;
}

//Converting infix to postfix
char* infix_to_postfix(char* expression)
{
    //Calculating length of infix expression
    int len = strlen(expression);

    Stack *operandstack = createStack();
    char* postfix = (char*)malloc(MAX_SIZE);
    char *postfixExpression = postfix;

    for(int i=0;i<len;i++)
    {
        /* if current term is operand
        append it in postfix expression */
        if(isalpha(expression[i]))
        {
            *postfix++ = expression[i];
        }

        /* if stack is empty or current term is an opening brace
        push current term in stack */
        else if(isEmpty(operandstack) || isOpenParenthesis(expression[i]))
        {
            push(operandstack,expression[i]);
        }

        /* if current term is a closing brace then pop
        stack until not get an opening brace */
        else if(isCloseParenthesis(expression[i]))
        {
            while(!isOpenParenthesis(top(operandstack)))
                *postfix++ = pop(operandstack);
            pop(operandstack);
        }

        /* if current term is an operator pop operators from stack
        until operator on stack has higher precedence than current
        operator and push current operator in stack */
        else
        {
            if(!isEmpty(operandstack)&&!isOpenParenthesis(top(operandstack)))
            {
                while(!isEmpty(operandstack)&&preced(top(operandstack),expression[i]))
                    *postfix++ = pop(operandstack);
            }
            push(operandstack,expression[i]);
        }
    }

    // Pop all operator remaining in stack
    while(!isEmpty(operandstack))
        *postfix++ = pop(operandstack);
    *postfix = '\0';

    return postfixExpression;
}

int main()
{
    char exp[MAX_SIZE];

    printf("Enter a valid infix expression:");
    scanf("%s",exp);

    printf("Postfix:%s\n",infix_to_postfix(exp));

    return 0;
}