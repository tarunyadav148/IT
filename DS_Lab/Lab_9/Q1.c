#include<stdio.h>
#include<stdlib.h>

//structure of node
struct node
{
    int value;
    struct node *next;
};

//function to insert node at begining
void insert_at_begin(struct node **head, int num)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("malloc failed in allocation in insert_at_begin function\n");
        return;
    }
    new_node->value = num;
    new_node->next = *head;
    *head = new_node;
}

//function to insert node at end
void insert_at_end(struct node **head, int num)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("malloc failed in allocation in insert_at_begin function\n");
        return;
    }
    new_node->value = num;
    new_node->next = NULL;
    if(*head == NULL)
    { 
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

//function to insert node at Kth position
//head node is postion-1
void insert_at_KthPosition(struct node **head,int num,int k)
{
    if(*head == NULL)
    {
        insert_at_begin(head,num);
        return;
    }
    int counter = 1;
    struct node *temp = *head;
    while(temp!=NULL&&counter<k)
        temp = temp->next;
    if(counter == k-1)
    {
        struct node * new_node = (struct node*)malloc(sizeof(struct node));
        new_node->value = num;
        new_node->next = temp->next;
        temp->next = new_node;
    }
    else{
        printf("Lenght of Linked List is %d\nCannot insert at %d position\n",counter,k);
    }
}

//function to search an integer in list
/*
    return pointer to first node containing this integer
    if integer is not found then return NULL
*/
struct node* search(struct node *head,int n)
{
    while (head!=NULL&&head->value!=n)
        head = head->next;
    return head;
}

//function to delete first node
void delete_first_node(struct node **head)
{
    if(*head == NULL)
    {
        printf("Linked List is empty\nCannot delete first node\n");
        return;
    }
    struct node *temp = *head;
    *head = temp->next;
    free(temp);
}

//function to delete last node
void delete_last_node(struct node **head)
{
    if(*head == NULL)
    {
        printf("Linked List is empty\nCannot delete last node\n");
        return;
    }
    struct node *curr = *head, *prev = NULL;

    if(curr->next == NULL)
    {
        *head = NULL;
    }
    else{

        while (curr->next!=NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
    }

    free(curr);
}

//function to delete an intermediate node
/*
    funtion will delete first node in list whose value
    is equal to n
*/
void delete_from_list(struct node **head,int n)
{
    if(*head == NULL)
    {
        printf("Linked List is empty\nCannot delete node from it\n");
        return;
    }
    struct node *curr = *head,*prev = NULL;

    if(curr->next==NULL)
    {
        *head = NULL;
        free(curr);
    }
    else{
        while(curr!=NULL&&curr->value!=n)
        {
            prev = curr;
            curr = curr->next;
        }
    }
    if(curr == NULL)
    {
        printf("Number is not in list\n");
    }
    else{
        prev->next = curr->next;
        free(curr);
    }
}

//function to display linked list
void printLinkedList(struct node *head)
{
    if(head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    printf("List:");
    while (head != NULL)
    {
        printf("%d ",head->value);
        head = head->next;
    }
    printf("\n");
}

//function to count occurences of a element in list
int count_occurences(struct node * list, int n)
{
    if(list == NULL)
    {
        printf("Linked List is empty\n");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while(list!=NULL)
    {
        if(list->value == n)
            count++;
        list = list->next;
    }
    return count;
}

//function to find last element whose value is n
struct node *find_last(struct node * list, int n)
{
    if(list == NULL)
    {
        printf("Linked List is empty\n");
        exit(EXIT_FAILURE);
    }
    struct node *temp = NULL;
    while(list!=NULL)
    {
        if(list->value == n)
            temp = list;
        list = list->next;
    }
    return temp;
}

//function to delete a node from list
void delete_node(struct node **head,struct node *Node)
{
    if(*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if(*head == Node)
    {
        *head = (*head)->next;
        free(Node);
    }
    else
    {
        struct node *temp = *head;
        while(temp!=NULL&&temp->next!=Node)
            temp = temp->next;
        temp->next = temp->next->next;
        free(Node);

    }
}

//function to delete any element with single pointer
void delete_from_list_withSinglePointer(struct node **head,int n)
{
    struct node *temp = NULL;

    if(*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    if((*head)->value == n)
    {
        temp = (*head);
        (*head) = (*head)->next;
        return;
    }

    if((*head)->next==NULL||(*head)->next->value == n)
    {
        if((*head)->next==NULL)
            return;
        temp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(temp);
        return;
    }
    delete_from_list_withSinglePointer(&((*head)->next),n);
}

void Interface(struct node *head);
int getNum();

int main()
{
    system("clear");
    struct node *head = NULL;
    Interface(head);
    return 0;
}

enum Menu
{ 
    Exit = 0 , 
    InsertAtBegin = 1,
    InsertAtEnd = 2, 
    DeleteFirstNode = 3,
    DeleteLastNode = 4,
    DeleteFromList = 5,
    DisplayLinkedList = 6,
    SearchInList = 7,
    CountOccurences = 8,
    PrintLastEelementOfParticularValue = 9,
    DeleteFromListWithSinglePointer = 10
};

int getNum()
{
    int n;
    scanf("%d",&n);
    return n;
}

void Interface(struct node *head)
{
    printf("0:Exit\n");
    printf("1:Insert node at begining\n");
    printf("2:Insert node at end\n");
    printf("3:Delete first node\n");
    printf("4:Delete last node\n");
    printf("5:Delete a number from list\n");
    printf("6:Display List\n");
    printf("7:Search a number in list\n");
    printf("8:Count occurences of an element\n");
    printf("9:Delete last occurrence of an element\n");
     printf("10:Delete a number from list with single pointer\n");

    int choice;

    while(1){
        printf("\nEnter a choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case Exit:
                exit(EXIT_SUCCESS);
                break;
            case InsertAtBegin:
                printf("Enter number to insert at begining:");
                insert_at_begin(&head,getNum());
                break;
            case InsertAtEnd:
                printf("Enter number to insert at end:");
                insert_at_end(&head,getNum());
                break;
            case DeleteFirstNode:
                delete_first_node(&head);
                break;
            case DeleteLastNode:
                delete_last_node(&head);
                break;
            case DeleteFromList:
                printf("Enter number to delete from list:");
                delete_from_list(&head,getNum());
                break;
            case DisplayLinkedList:
                printLinkedList(head);
                break;
            case SearchInList:
                printf("Enter number to search in list:");
                if(search(head,getNum())!=NULL)
                    printf("Number found in List\n");
                else
                    printf("Number not found in list\n");
                break;
            case CountOccurences:
                printf("Enter number whose occurences want to know:");
                int n = getNum();
                printf("Occurence of %d : %d\n",n,count_occurences(head,n));
                break;
            case PrintLastEelementOfParticularValue:
                printf("Enter number to delete its last occurence:");
                struct node *temp = find_last(head,getNum());
                if(temp!=NULL)
                    delete_node(&head,temp);
                break;
            case DeleteFromListWithSinglePointer:
                printf("Enter number to delete from list with single pointer:");
                delete_from_list_withSinglePointer(&head,getNum());
                break;
        }
    }
}