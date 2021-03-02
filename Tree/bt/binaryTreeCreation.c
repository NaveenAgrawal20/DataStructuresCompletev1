#include<stdio.h>
#include<stdlib.h>
// Tree Node
struct Node
{
    struct Node* lchild;
    int data;
    struct Node *rchild;
};
typedef struct Node Node;

// circular queue
struct Queue
{
    int size,front,rear;
    Node **Q;
};

void create(struct Queue *q,int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size*sizeof(Node *));
}
void enqueue(struct Queue *q,Node *x)
{
    if( (q->rear+1)%q->size == q->front)
        printf("Queue is full");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}
Node* dequeue(struct Queue *q)
{
    Node *x = NULL;
    if(q->front == q->rear)
        printf("Queue is Empty");
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

// End of Circular Queue Program

// Tree Creation
Node *root = NULL;

void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter root value ");
    scanf("%d",&x);
    root = (Node*)malloc(sizeof(Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (Node*)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (Node*)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }

}

// LevelOrder Traversal
void levelOrder(Node *root)
{
    Node *p;
    struct Queue q;
    create(&q,100);

    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("%d ",p->data);
        if(p->lchild != NULL)
        {
            enqueue(&q,p->lchild);
        }
        if(p->rchild != NULL)
        {
            enqueue(&q,p->rchild);
        }
    }
}
int height(Node *root)
{
    int x=0,y=0;
    if(root == NULL)
        return 0;
    x += height(root->lchild);
    y += height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}
// count nodes
int count(Node *root)
{
    if(root)
    {
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
    /* 2nd way
    int x = 0,y=0;
    if(root)
    {
        x = count(root->lchild);
        y = count(root->rchild);
        return x+y+1;
    }*/
}

// count LEAF and NON LEAF node
int countLeaf(Node *p)
{
    // if(node == NULL)
    //     return 0;
    // if(node->lchild == NULL && node->rchild==NULL)
    //     return 1;
    // else
    //     return countLeaf(node->lchild)+ countLeaf(node->rchild);
    int x = 0,y = 0;
    if(p!=NULL)
    {
        x = countLeaf(p->lchild);
        y = countLeaf(p->rchild);
        if(p->lchild == NULL && p->rchild == NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int countNonLeaf(Node *p)
{
//    if(p == NULL)
//        return 0;
//    if(p->lchild == NULL || p->rchild == NULL)
//        return countNonLeaf(p->lchild)+countNonLeaf(p->rchild)+1;
//    else
//        return countNonLeaf(p->lchild)+countNonLeaf(p->rchild);
    int x = 0,y = 0;
    if(p!=NULL)
    {
        x = countNonLeaf(p->lchild);
        y = countNonLeaf(p->rchild);
        if(p->lchild != NULL || p->rchild != NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;

}
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


int main()
{
    Treecreate();
    printf("Preorder is  = ");
    preorder(root);
    printf("\nInorder is  = ");
    inorder(root);
    printf("\nPostorder is = ");
    postorder(root);
    printf("\nLevelOrder is  = ");
    levelOrder(root);
    printf("\nHeight of TREE = %d",height(root));
    printf("\nCount (no of Nodes) in TREE = %d",count(root));
    printf("\nCount (no of LEAF Nodes or (EXTERNAL NODES)) in TREE = %d",countLeaf(root));
    printf("\nCount (no of NON LEAF Nodes (INTERNAL NODES) ) in TREE = %d",countNonLeaf(root));
    return 0;
}
/*
DEPTH
public int depth(node p) {
if (isRoot(p))
return 0;
else
return 1+depth(parent(p))
}
*/

/*
7
8
-1
9
-1
11
-1
1
8
-1
-1
-1
-1
*/

/*
10
20
30
40
50
60
70
-1
-1
-1
-1
-1
-1
-1
-1
*/
