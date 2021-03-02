#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
typedef struct Node Node;
Node *root = NULL;
//traversal
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);

// Search
Node *Rsearch(Node *root, int item)
{
    if (root->data == item)
        return NULL;
    else if (item < root->data)
        Rsearch(root->lchild, item);
    else
        Rsearch(root->rchild, item);
}

// RECURSIVE Insert
Node *rec_insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        return newnode;
    }

    if (key < root->data)
    {
        root->lchild = rec_insert(root->lchild, key);
    }
    else if (key > root->data)
    {
        root->rchild = rec_insert(root->rchild, key);
    }
    return root;
}
/* We find Inorder Successor and Inorder Predecessor  */

Node *inSucc(Node *p) // move one right and then left // we pass p->right in our delete func
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node *inPred(Node *p) // move one left and then right // we pass p->left in our delete func
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

int height(Node *p)
{
    int x,y;
    if(p == NULL)
        return 0;

    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y+1;
}

// RECURSIVE Delete
Node *rec_delete(Node *p, int key)
{
    if (p == NULL) // empty
    {
        printf("Key is not found\n");
        return NULL;
    }

    /* If the deleted NODE has no child and has key */
    if (p->lchild == NULL && p->rchild == NULL && p->data == key)
    {
        if(root == p)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = rec_delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rec_delete(p->rchild, key);
    }
    else
    {
        Node *temp;
        if( height(p->lchild) > height(p->rchild) ) // left is larger better to take value from it
        {
            temp = inPred(p->lchild);  // find inorder Predecessor (temp)
            p->data = temp->data;       // replace delete node data by temp's data
            p->lchild = rec_delete(p->lchild,temp->data); // delete temp node from tree
        }
        else
        {
            temp = inSucc(p->rchild);
            p->data = temp->data;
            p->rchild = rec_delete(p->rchild,temp->data);
        }
    }
    return p;
}

int main()
{
    printf("\t\t---BINARY SEARCH TREE---\n");
    // root = rec_insert(root, 40);
    root = rec_insert(root, 10);
    rec_insert(root, 5);
    // rec_insert(root, 60);
    // rec_insert(root, 18);
    // rec_insert(root, 70);
    // rec_insert(root, 14);
    // rec_insert(root, 11);
   
    // Initial
    printf("\nPreorder is  = ");
    preorder(root);
    printf("\nInorder is  = ");
    inorder(root);
    printf("\nPostorder is = ");
    postorder(root);
    printf("\nHeight of tree is %d", height(root));
    
    // Delete
    rec_delete(root,5);
    printf("\nPreorder is  = ");
    preorder(root);
    printf("\nInorder is  = ");
    inorder(root);
    printf("\nPostorder is = ");
    postorder(root);

    //Root Deletion
    // rec_delete(root,40);
    // printf("\nPreorder is  = ");
    // preorder(root);
    // printf("\nInorder is  = ");
    // inorder(root);
    // printf("\nPostorder is = ");
    // postorder(root);

    return 0;
}

// TREAVESAL
void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}
void postorder(Node *root)
{
    if (root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}
