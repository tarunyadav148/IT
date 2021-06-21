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

//Count leaf node
int countLeafNode(NodePtr root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL&&root->right==NULL)
        return 1;
    return countLeafNode(root->left)+countLeafNode(root->right);
}


int main()
{
    NodePtr root = makeTree(1);
    setLeft(root,2);
    setRight(root,3);
    setLeft(root->left,7);

    printf("Leaf node of Tree: %d\n",countNode(root));

    return 0;
}