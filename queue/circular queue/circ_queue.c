#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5
int cirq_arr[MAX];
int front = -1;
int rear = -1;
int isFull()
{
    if( (front==rear+1) || (front==0 && rear==MAX-1) )
        return 1;
    else
        return 0;
};
int isEmpty()
{
    if (front==-1)
        return 1;
    else 
        return 0;
};
void insert(int item)
{
    if(isFull())
    {
        printf("Overflow");
        return;
    }
    if(front==-1)
        front = 0;
    if(rear == MAX-1)
        rear = 0;
    else
        rear++;
    cirq_arr[rear]=item;
};
void del()
{
    if(isEmpty())
    {
        printf("Underflow");
        return;
    }
    if(front==rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front==MAX-1)
    {
        front = 0;
    }
    else
        front++;
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("Empty");
        return;
    }
    i = front;
    if(front <=rear)
    {
        while(i<=rear)
            printf("%d\t",cirq_arr[i++]);
    }
    else
    {
        while(i<=MAX-1)
            printf("%d\t",cirq_arr[i++]);
        i =0;
        while(i<=rear)
            printf("%d\t",cirq_arr[i++]);
    }
}
int main()
{
    int choice,value;
    while(1)
    {
        printf("\n*****************MENU*****************\n");
        printf("Select \n1.Insert(enqueue)\n2.Delete(dequeue)\n3.Display\n4.Peek\n5.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted");
            scanf("%d",&value);
            insert(value);
            break;
        case 2: del();
				break;
        case 3: display();
				break;
        case 4: printf("\n%d item at front peeked");
                    break;
        case 5: exit(0);
					break;
        default:printf("try again");	
				break;
        }
    }
    getch();
    return 0;
}
