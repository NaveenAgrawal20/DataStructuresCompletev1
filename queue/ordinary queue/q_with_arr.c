#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10

int q_arr[10];
int front = -1;
int rear = -1;
void insert(int);
void del();
int peek();
void display();

int isFull();
int isEmpty();

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
        case 4: printf("\n%d item at front peeked",peek());
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
int isFull()
{
    if(rear==MAX-1)
        return 1;
    else 
        return 0;
};
int isEmpty()
{
    if(front == -1 || front == rear+1)
        return 1;
    else 
        return 0;
};
void insert(int data)
{
    if(isFull())
	{
        printf("Queue Overflow");
        return;
	}
	if(front==-1)
        front = front+1;
    rear++;
    q_arr[rear] = data;
}
void del()
{
    if(isEmpty())
    {
        printf("Queue Underflow");
        exit(1);
    }
    front++;
}
int peek()
{
    if(isEmpty())
    {   printf("no peek Queue empty");
        exit(1);
    }
    else
        return q_arr[front]; 
}
void display()
{
    if(isEmpty())
    {
        printf("Nothing to display");
        exit(1);
    }
    else
    {
        printf("\nDisplaying all items in queue\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",q_arr[i]);
        }
    }
};
