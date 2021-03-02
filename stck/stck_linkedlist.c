#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next ;
};
struct node *top = NULL;
void push(int);
void pop();
void display();
int main()
{
    int choice, value;
    printf("\n:: Stack using Linked List ::\n");
    while (1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
             push(value);
            break;
        case 2:
             pop();
            break;
        case 3:
             display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
    return 0;
}
void push(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Stack Overflow");
        return;
    }
    newnode->data = item;
    newnode->next = top;
    top = newnode;
};
void pop()
{
    struct node *temp;
    if(top==NULL)
        printf("Stack Underflow");
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
};
void display()
{
	struct node *temp;
    if(top==NULL)
        printf("Staack empty");
    else
    {
        temp = top;
        while(temp->next!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
            printf("%d--->NULL",temp->data);
    }
};
