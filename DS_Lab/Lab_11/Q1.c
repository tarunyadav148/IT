#include<stdio.h>
#include<stdlib.h>

//strcuture of node of a tree
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* NodePtr;

//Make tree
NodePtr makeTree(int n)
{
    NodePtr node = malloc(sizeof(struct Node));
    node->data = n;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Set left child
void setLeft(NodePtr node,int n)
{
    if(node == NULL)
        printf("void inserion\n");
    else if(node->left!=NULL)
        printf("Invalid insertion\n");
    else
        node->left = makeTree(n);
}

//Set right child
void setRight(NodePtr node,int n)
{
    if(node == NULL)
        printf("void inserion\n");
    else if(node->right!=NULL)
        printf("Invalid insertion\n");
    else
        node->right = makeTree(n);
}

//Pre Order Traversal
void preOrderTraversal(NodePtr root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

//In Order Traversal
void inOrderTraversal(NodePtr root)
{
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

//Post Order Traversal
void postOrderTraversal(NodePtr root)
{
    if(root!=NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    // NodePtr root = makeTree(1);
    // setLeft(root,2);
    // setRight(root,3);

    
       NodePtr root = makeTree(1);
       root->left = makeTree(2);
       root->right = makeTree(3);
    

    printf("Pre Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}