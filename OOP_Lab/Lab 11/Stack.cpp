#include<iostream>
#define MAX_SIZE 100

using namespace std;

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack();
    void push(int item);
    int pop();
    bool stackfull();
    bool stackempty();
    int Top();
};

Stack::Stack()
{
    top = -1;
}

void Stack::push(int item)
{
    if(stackfull())
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        arr[++top] = item;
    }
}

int Stack::pop()
{
    if(stackempty())
    {
        cout<<"Stack is empty"<<endl;
        exit(0);
    }
    else
        return arr[top--];
}

bool Stack::stackfull()
{
    return top == MAX_SIZE;
}

bool Stack::stackempty()
{
    return top == -1;
}

int Stack::Top()
{
    if(!stackempty())
        return arr[top];
    exit(0);
}


int main()
{
    Stack s;

    s.push(5);
    s.push(7);
    s.push(1);
    s.push(3);

    cout<<"Top of stack: "<<s.Top()<<endl;
    cout<<"Item "<<s.pop()<<" is poped out"<<endl;
    cout<<"Top of stack: "<<s.Top()<<endl;
    if(s.stackempty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Stack is not empty"<<endl;

    return 0;
}