#include <stdio.h>
#include <stdlib.h>

//Structure of node
/*
    int value: data of a node
    struct node* next: pointer to next node
*/
struct node
{
    int value;
    struct node *next;
};

/* 
    EvenOddSeprate function modify list in such a manner 
    that even values comes first then odd values.

    argument required:address of head of linked list
*/
void EvenOddSeprate(struct node **head)
{
    /*
        Even pointer get even linked list and odd get odd
    */
    struct node *even_begin = NULL;
    struct node *even_end = NULL;
    struct node *odd_start = NULL;
    struct node *odd_end = NULL;
    struct node *current_node = *head;
     
    while(current_node != NULL){
        int num = current_node -> value;
        if(num % 2 == 0) {
            if(even_begin == NULL){
                even_begin = current_node;
                even_end = even_begin;
            } 
            else {
                even_end -> next = current_node;
                even_end = even_end -> next;
            }
        }
        else{
            if(odd_start == NULL){
                odd_start = current_node;
                odd_end = odd_start;
            }
            else{
                odd_end -> next = current_node;
                odd_end = odd_end -> next;
            }
        }
        current_node = current_node -> next;   
    }
    if(odd_start == NULL || even_begin == NULL){
        return;
    }
    even_end -> next = odd_start; // even end points to odd begin
    odd_end -> next = NULL;       // odd end set to NULL
    *head = even_begin;            // even head is now list head
}


/* 
    printLinkedList function print the linked list 
    argument required: head of linked list
*/
void printLinkedList(struct node *node)
{
    //print until next of current node is not NULL
    while (node!=NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
}

/*
    insert futnction insert the number to linked list
    at end 

    argument required:address of head of linked list and
                     number to be inserted            
*/
void insert(struct node** head, int num) 
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));;
    struct node *last = *head;
    new_node->value = num;
    new_node->next = NULL;
    if (*head == NULL) 
    { 
        *head = new_node; 
        return; 
    }
    while (last->next != NULL) //finding end of linked list
        last = last->next;
    last->next = new_node; 
    return;
} 

int main()
{
    int n;
    struct node* head = NULL;

    //Input n:which number of nodes inserted in linked list
    printf("Enter n : ");
    scanf("%d",&n);

    printf("Enter Linked List : \n");
    for(int i=0;i<n;i++) {
        int num;
        scanf("%d",&num);
        insert(&head, num);
    }
 
    printf("\nOriginal Linked list : ");
    printLinkedList(head);
 
    EvenOddSeprate(&head);
 
    printf("\nModified Linked list : ");
    printLinkedList(head);
}