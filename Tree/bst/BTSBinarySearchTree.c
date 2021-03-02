#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
};
typedef struct Node Node;
Node *root = NULL;
//traversal
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);

// Search
Node* search(Node *root,int item)
{
    Node *t = root;
    while(t!=NULL)
    {
        if(t->data == item)
            return t;
        else if(item < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

// Insert
void insert(int item)
{
    Node *r,*t;
    if(root == NULL)
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->data = item;
        newnode->lchild = NULL;
        newnode->rchild = NULL;        
        root = newnode;
        return;
    }
    t = root;
    r = NULL;
    while(t!=NULL)
    {
        r = t;
        if(t->data == item)         // Duplicate Item Not Allowed
            return;
        else if(item < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    if(r->data > item)
        r->lchild = newnode;
    else
        r->rchild = newnode;
}

int main()
{
    printf("TREE");
    insert(40);
    insert(10);
    insert(50);
    insert(60);
    insert(18);
    insert(70);
    insert(14);
    insert(11);
    printf("Preorder is  = ");
    preorder(root);
    printf("\nInorder is  = ");
    inorder(root);
    printf("\nPostorder is = ");
    postorder(root);
    return 0;
}

// TREAVESAL
void preorder(Node *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(Node *root)
{
    if(root)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}
void postorder(Node *root)
{
    if(root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}
