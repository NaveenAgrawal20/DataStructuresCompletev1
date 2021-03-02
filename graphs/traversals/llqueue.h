/*
 * Create By Naveen
 * Created on Fri Feb 05 2021
 * Copyright © 2021
 */

#ifndef QUEUE_H
#define QUEUE_H
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

Node *front = NULL, *rear = NULL;
int isEmpty() { return front == NULL; }
void enqueue(int key)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("Queue is FUll\n");
        return;
    }
    newnode->data = key;
    newnode->next = NULL;
    if (isEmpty())
        front = newnode;
    else
        rear->next = newnode;
    rear = newnode;
}
int dequeue()
{
    int x;
    if(isEmpty())
       printf("Queue is Empty\n");
    else
    {
        Node *temp = front;
        x = front->data;
        front = front->next;
        free (temp);
    }
    return x;
}
#endif