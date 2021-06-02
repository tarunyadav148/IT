/*
   Assumptions and limitations:
   1)Operand must be single digit number
   2)Operator must be arithmetic operator (%,*,/,+,-)
   3)Expression must be a valid postfix expression
*/
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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
 
//Performing operation with 2 operand and given operator
int performOperation(int pop1,int pop2,char operator)
{
   switch (operator)
   {
   case '*':
       return pop1*pop2;
   case '/':
       return pop1/pop2;
   case '%':
       return pop1%pop2;
   case '+':
       return pop1+pop2;
   case '-':
       return pop1-pop2;
   }
}
 
//Evaluating postfix expression
int evaluatePostfix(char* expression)
{
   int len = strlen(expression);
   Stack *stack = createStack();
   int pop1,pop2,result;
   for(int i=0;i<len;i++)
   {
       if(isdigit(expression[i]))
       {
           if(!isFull(stack))
               push(stack,(expression[i]-48));
       }
       else
       {
           pop2 = pop(stack);
           pop1 = pop(stack);
           result = performOperation(pop1,pop2,expression[i]);
           if(!isFull(stack))
               push(stack,result);
       }
   }
 
   return pop(stack);
}
 
int main()
{
   char exp[MAX_SIZE];
 
   printf("Enter a valid postfix expression:");
   scanf("%s",exp);
   printf("Result of postfix expression: %d\n",evaluatePostfix(exp));
   return 0;
}
