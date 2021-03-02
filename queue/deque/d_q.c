#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5
// // Deque -> Double Ended QUEue (Deletion and Insertion is somewhat same as Circular queue) Imagine queue as circular
int dq_arr[MAX];
int front = -1, rear = -1;
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
        return 1;
    else
        return 0;
};
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
};
void insert_at_frontEnd(int item)       //push
{
    if (isFull())
    {
        printf("Overflow");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX - 1;
    else
        front--;
    dq_arr[front] = item;
};
void insert_at_rearEnd(int item)        //inject
{
    if (isFull())
    {
        printf("Overflow");
        return;
    }
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;
    dq_arr[rear] = item;
};
int del_at_frontEnd() //here i am returning the removed item        //(aka pop)
{
    int ritem;
    if (isEmpty())
    {
        printf("Underflow");
        return;
    }
    ritem = dq_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
    return ritem;
}
int del_at_rearEnd()            //eject
{
    int ritem;
    if (isEmpty())
    {
        printf("Underflow");
        return;
    }
    ritem = dq_arr[rear];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
    return ritem;
};
void display()
{
    int i;
    if (isEmpty())
    {
        printf("Empty");
        return;
    }
    i = front;
    if (front <= rear)
    {
        while (i <= rear)
            printf("%d\t", dq_arr[i++]);
    }
    else
    {
        while (i <= MAX - 1)
            printf("%d\t", dq_arr[i++]);
        i = 0;
        while (i <= rear)
            printf("%d\t", dq_arr[i++]);
    }
};
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n*****************MENU*****************\n");
        printf("Select \n1.Insert at Front End\n2.Insert at Rear End\n3.Delete at Front End\n");
        printf("4.Delete at Rear End\n5.Display\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted");
            scanf("%d", &value);
            insert_at_frontEnd(value);
            break;
        case 2:
            printf("Enter the number to be inserted");
            scanf("%d", &value);
            insert_at_rearEnd(value);
            break;
        case 3:
            printf("deleted item at Front is %d", del_at_frontEnd());
            break;
        case 4:
            printf("deleted item at Rear is %d", del_at_rearEnd());
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("try again");
            break;
        }
    }
    getch();
    return 0;
}
