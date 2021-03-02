/*
 * Create By Naveen
 * Created on 2021
 */
/**
 * Implementation of AVL Tree.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild, *rchild;
    int data, height;
} Node;
Node *root = NULL;
//traversal
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);

// height
int NodeHeight(Node *p)
{
    int hleft, hright;
    hleft = p && p->lchild ? p->lchild->height : 0;
    hright = p && p->rchild ? p->rchild->height : 0;
    return hleft > hright ? hleft + 1 : hright + 1;
}
Node *inSuc(Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}
Node *inPred(Node *p)
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}
// balace Factor
int balanceFactor(Node *p)
{
    int hleft, hright;
    hleft = p && p->lchild ? p->lchild->height : 0;
    hright = p && p->rchild ? p->rchild->height : 0;
    return hleft - hright;
}
/* ROTATION */
// LL rotation
Node *LL_rotation(Node *p)
{
    Node *pl, *plr;
    pl = p->lchild;
    plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    // Height changes so update height also
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if (p == root)
        root = pl;

    return pl; // return PL
}
// RR rotation
Node *RR_rotation(Node *p)
{
    Node *pr, *prl;
    pr = p->rchild;
    prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if (root == p)
        root = pr;
    return pr;
}
// LR_Rotation
Node *LR_rotation(Node *p)
{
    Node *pl, *plr;
    pl = p->lchild;
    plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;
    return plr;
}

Node *RL_rotation(Node *p)
{
    p->rchild = LL_rotation(p->rchild);
    p = RR_rotation(p);
    if (root == p)
        root = p;
    return p;
}
// INSERT
Node *rec_insert(Node *p, int key)
{
    if (p == NULL)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        newnode->height = 1;
        /*Done for while menu*/
        if (root == NULL)
            root = newnode;
        /*END*/
        return newnode;
    }
    if (key < p->data)
        p->lchild = rec_insert(p->lchild, key);
    else if (key > p->data)
        p->rchild = rec_insert(p->rchild, key);
    // update height of all node of TREE
    p->height = NodeHeight(p);

    // check for their balance
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LL_rotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RR_rotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LR_rotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RL_rotation(p);
    return p;
}
// Delete
Node *rdelete(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL && p->data == key)
    {
        if (root == p)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->lchild = rdelete(p->lchild, key);
    else if (key > p->data)
        p->rchild = rdelete(p->rchild, key);
    else
    {
        Node *temp;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild))
        {
            temp = inPred(p->lchild);
            p->data = temp->data;
            p->lchild = rdelete(p->lchild, temp->data);
        }
        else
        {
            temp = inSuc(p->rchild);
            p->data = temp->data;
            p->rchild = rdelete(p->rchild, temp->data);
        }
    }
    p->height = NodeHeight(p);
    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LL_rotation(p);          // L1 rotation
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LR_rotation(p);          // L-1 rotation
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0)
        return LL_rotation(p);          //L0 rotation // we can perform any of L1 or L-1 rotation
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RR_rotation(p);          // R-1 rotation
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RL_rotation(p);          // R1 roation
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0)
        return RL_rotation(p);          //R0 rotation // we can perform any of R1 or R-1 rotation
    return p;
}

int main()
{
    int item;
    while (1)
    {
        printf("Enter value to insert and 0 to exit ");
        scanf("%d", &item);
        if (item <  0)
            rdelete(root,-1*item);
        else if(item > 0)
            rec_insert(root, item);
        else
            break;
    }
    printf("Preorder is  = ");
    preorder(root);
    printf("\nInorder is  = ");
    inorder(root);
    printf("\nPostorder is = ");
    postorder(root);
    return 0;
}

///////////
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


/*
LL ROTATION
30
20
40
10
25
50
28
15
5
4
-1
//LR rotation
40
20
50
10
30
60
5
25
35
27
-1
*/
// deletion algo
/*
R0 rotation
46
20
54
18
23
60
7
24
-60
0
*/