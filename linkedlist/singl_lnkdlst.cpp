#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
// Program for Single Linked List
struct node
{
    int data;
    struct node *next;
};
//-------------Prototyping
// Basic Function
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);

struct node *create_list(struct node *start);

struct node *add_atBeg(struct node *start,int data);
struct node *add_atEnd(struct node *start,int data);
struct node *add_Before(struct node *start,int data,int item);
struct node *add_After(struct node *start,int data,int item);
struct node *add_atpos(struct node *start,int data,int pos);
//
struct node *del(struct node *start,int data);
//
struct node *reverse(struct node *start);

int main()
{
    struct node *start = NULL;
    int choice,data,item,pos;
    while(1)
    {
        cout<<"1.Create List\n2.Dispaly\n3.Count\n4.Search\n5.Add to Begining (Empty lnklist)\n6.Add at End\n7.Add before node\n8.Add after node"
        "\n9.Add at position\n10.Delete\n11.Reverse\n12.Quit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: start = create_list(start);break;
            case 2: display(start);break;
            case 3: count(start);break;
            case 4: cout<<"Enter data to be searched";
                    cin>>data;
                    search(start,data);
                    break;
            case 5: cout<<"Enter data to be inserted ";
                    cin>>data;
                    start = add_atBeg(start,data);
                    break;
            case 6: cout<<"Enter data to be inserted ";cin>>data;start = add_atEnd(start,data);break;
            case 7: cout<<"Enter data to be inserted ";cin>>data;cout<<"Enter the data Before which to be inserted ";cin>>item;start = add_Before(start,data,item);break;
            case 8: cout<<"Enter data to be inserted ";cin>>data;cout<<"Enter the data After which to be inserted ";cin>>item;start = add_After(start,data,item);break;
            case 9: cout<<"Enter data to be inserted ";cin>>data;cout<<"Enter the position at which to be inserted ";cin>>pos;start = add_atpos(start,data,pos);break;
            case 10: cout<<"Enter data to be deleted ";cin>>data;start = del(start,data);break;
            case 11: start = reverse(start);break;
            case 12: exit(0);break;
            default: cout<<"Try again ";break;
        }
    }
    getch();
    return 0;
}
/*--------------------------------------------------------------*/
/*--------------------------------------------------------------*/

struct node *create_list(struct node *start)
{
    int n,data;
    cout<<"Enter the no of nodes ";
    cin>>n;
    start = NULL;
    if(n==0)
        return start;
    cout<<"Enter the element to be inserted ";
    cin>>data;
    start = add_atBeg(start,data);
    for(int i = 2;i<=n;i++)
    {
        cout<<"Enter element to be inserted ";
        cin>>data;
        start = add_atEnd(start,data);
    }
    return start;
};
/*--------------------End of Createlist-------------------------*/
struct node *add_atBeg(struct node *start,int data)
{
    struct node *newnode = new node();
    newnode->data = data;
    newnode->next = start;
    start = newnode;
    return start;
}; 
/*--------------------End of add at Begin-------------------------*/
struct node *add_atEnd(struct node *start,int data)
{
    struct node *newnode,*p;
    newnode = new node();
    newnode->data = data;
    p = start;
    while(p->next != NULL)
        p = p->next;
    p->next = newnode;
    newnode->next = NULL;
    return start;
};
 /*--------------------End of add at End-------------------------*/
struct node *add_Before(struct node *start,int data,int item)
{
    struct node *newnode,*p;
    if(start == NULL)
    {
        cout<<"Empty list (B) ";
        return start;
    }
    // If node to be inserted is before first node
     if(item == start->data)
     {
        newnode = new node();
        newnode->data = data;
        newnode->next = start;
        start = newnode;
        return start;
     }
    p = start;
    while(p->next != NULL)
    {
        if(p->next->data == item)
        {
            newnode = new node();
            newnode->data = data;
            newnode->next = p->next;
            p->next = newnode;
            return start;
        }
        p = p->next;
    }
    cout<<"The given item := "<<item<<" is not present in list"<<endl;
    return start;
};
/*--------------------End of add Before-------------------------*/
struct node *add_After(struct node *start,int data,int item)
{
    struct node *newnode,*p;
    newnode = new node();
    p = start;
    while(p!= NULL)
    {  
        if(item==p->data)
        {
            newnode->data = data;
            newnode->next = p->next;
            p->next = newnode;
            return start;
        }
        p = p->next;
    }
	cout<<"The given item := "<<item<<" is not present in list"<<endl;
    return start;
};
/*--------------------End of add After-------------------------*/
struct node *add_atpos(struct node *start,int data,int pos)
{
    struct node* newnode,*p;
    newnode = new node();
    newnode->data = data;
    // for first position
    if(pos==1)
    {
        newnode->next = start;
        start = newnode;
        return start;
    }
    p = start;
    for(int i=1;i<pos-1 && p!=NULL;i++)
        p = p->next;
    if(p==NULL)
        cout<<"Not Enough items"<<endl;
    else
    {
        newnode->next = p->next;
        p->next = newnode;
    }
    return start;
}

/*-------------------END of add at Position------------------------*/
struct node *del(struct node *start,int data)
{
    struct node *temp,*p;
    if(start==NULL)    //Empty
    {
        cout<<"UNDERFLOW ";
        return start;
    }
    if(start->data == data)     //First Element
    {
        temp = start;
        start = start->next;
        delete temp;
        return start;
    }
    p = start;
    while(p->next!=NULL)
    {
        if(p->next->data==data)
        {
            temp = p->next;
            p->next = temp->next;
            delete temp;
            return start;
        }
        p = p->next;
    }
    cout<<"Item "<<data<<" not found";
    return start;
}
/*-----------------------------END of delete----------------------------------*/
void display(struct node *start)
{
    struct node *temp;
    if(start==NULL)
	{
	    cout<<"List is empty"<<endl;
		return;
	}
    temp = start;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n\n";
}
/*--------------------End of Display ----------------------------*/
void count(struct node* start)
{
    int count=0;
    struct node *p;
    p = start;

    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    cout<<"Number of Elements are "<<count<<endl;
}
/*--------------------End of Count----------------------------*/
void search(struct node *start,int skey)
{
    struct node *p = start;
    int position=1;
    while(p!=NULL)
    {
        if(p->data == skey)
        {
            cout<<"Element present at position = "<<position<<endl;
            return ;
        }
        position++;
        p = p->next;
    }
    cout<<"ELement not found"<<endl;
}
/*--------------------End of Search----------------------------*/

struct node *reverse(struct node *start)
{
    struct node *ptr,*prev,*forward;
    //initially
    prev = NULL;
    ptr = start;
    //
    while(ptr!=NULL)
    {
        forward = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = forward;
    }
    start = prev;
    return start; 
}
/*--------------------End of Reverse -----------------------------*/
