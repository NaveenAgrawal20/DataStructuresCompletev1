#ifndef STACH_H
#define STACH_H

struct SNode{
    int data;
    struct SNode *next;
};
typedef struct SNode SNode;
SNode *top = NULL;

int stackEmpty(){
    return top == NULL;   
}

void push(int key)
{
    SNode *newSNode = (SNode *)malloc(sizeof(SNode));
    if(newSNode == NULL){
        printf("Stack OVERFLOW\n");
        return;
    }
    newSNode->data = key;
    newSNode->next = top;
    top = newSNode;
}
int pop()
{
    int x;
    if(stackEmpty())
    {
        printf("STACK UNDERFLOW\n");
        return x;
    }
    x = top->data;
    SNode *temp = top;
    top = top->next;
    free(temp);
    return x;
}
#endif