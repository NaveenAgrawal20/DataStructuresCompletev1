#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//front 1st node and rear 2nd node 
struct node
{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;

void insert(int);
void del();
void display();
int isEmpty();
int main()
{
   int choice, value;
   printf("\n:: Queue Implementation using Linked List ::\n");
   while(1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
          printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
	    case 1: printf("Enter the value to be insert: ");
	    scanf("%d", &value);
	    insert(value);
		 break;
	    case 2: del(); break;
	    case 3: display(); break;
	    case 4: exit(0);
	    default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
    getch();
    return 0;
};
int isEmpty()
{
    if(front == NULL)
        return 1;
    else
        return 0;
}
void insert(int item)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("No memory available");
        return;
    }
    if(front==NULL)
    {
        front = newnode;
    }
    else
    {
		rear->next = newnode;
	}
	newnode->data = item;
	newnode->next = NULL;
	rear = newnode;
}
void del()
{
    if(isEmpty())
    {
        printf("Underflow");
        return;
    }
    struct node* temp = front;
    front = front->next;
    free(temp);
}
void display()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else
    {
        struct node *temp = front;
        while(temp->next != NULL)
        {
	        printf("%d--->\t",temp->data);
	        temp = temp -> next;
        }
        printf("%d--->NULL\n",temp->data);
    }
}
