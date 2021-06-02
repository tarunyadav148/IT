#include<iostream>
#define MAX_SIZE 100

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue
{
private:
    Node* front;
    Node* back;
public:
    Queue();
    void insertqueue(int item);
    void deletequeue();
    void display();
};

Queue::Queue()
{
    front = NULL;
    back = NULL;
}

void Queue::insertqueue(int item)
{
    Node* temp = new Node;
    temp->data = item;
    if(front==NULL)
    {
        front = temp;
        back = temp;
        temp->next = NULL;
    }else{
        back->next = temp;
        back = temp;
        temp->next = NULL;
    }
}

void Queue::deletequeue()
{
    Node* temp = front;
    if(front==back)
    {
        front = NULL;
        back = NULL;
    }else{
        front = temp->next;
        temp->next = NULL;

    }
    cout<<"Element "<<temp->data<<" is deleted from queue"<<endl;
    delete temp;
}

void Queue::display()
{
    if(front==NULL&&back==NULL)
    {
        cout<<"Queue is empty "<<endl;
    }
    else{
        Node* temp = front;
        cout<<"Elements of Queue are: ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    cout<<'\n';

}



int main()
{
    Queue q;

    q.insertqueue(5);
    q.insertqueue(6);
    q.insertqueue(1);
    q.insertqueue(88);

    q.display();

    q.deletequeue();

    q.display();

    return 0;
}