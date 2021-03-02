#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    int priority;
    struct node* next;
}*front = NULL;
int isEmpty()
{
    if(front==NULL)
        return 1;
    else
        return 0;   
}
void insert(int item_priority,int item)
{
    struct node *newnode,*p;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("No memory available");
        return;
    }
    newnode->data = item;
    newnode->priority = item_priority;
    if( isEmpty() || item_priority < front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        p = front;
        while(p->next != NULL &&( item_priority >= p->next->priority) )
        	p = p->next;
        newnode->next = p->next;
        p->next = newnode;
    }
};
void del()
{
    if(isEmpty())
    {
        printf("Underflow");
        return;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = front;
    // if return the deleted item: ritem = temp->data;
    front = temp->next;
    free(temp);
};
void display()
{
   if(isEmpty())
    {
        printf("Empty");
        return;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = front;
    while(temp->next != NULL)
    {
        printf("%d priority = %d|\t",temp->priority,temp->data);
        temp = temp->next;
    }
    printf("%d priority = %d|\t",temp->priority,temp->data);
};
int main()
{
    int choice, value,priority;
    while (1)
    {
        printf("\n*****************MENU*****************\n");
        printf("Select \n1.Insert(enqueue)\n2.Delete(dequeue)\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the priority to be inserted");
            scanf("%d",&priority);
            printf("Enter the number to be inserted");
            scanf("%d", &value);
            insert(priority,value);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
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
