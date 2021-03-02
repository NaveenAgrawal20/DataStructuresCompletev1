#include<iostream>
#include<conio.h>
using namespace std;

struct node{
    node *prev;
    int data;
    node *next;
};
void display(struct node *start);
struct node *createdoublelList(struct node*start);
struct node* addtoEmpty(struct node* start,int data);

struct node *add_atBeg(struct node *start,int data);
struct node *add_atEnd(struct node *start,int data);
struct node *add_Before(struct node *start,int data,int item);
struct node *add_After(struct node *start,int data,int item);
struct node *add_atpos(struct node *start,int data,int pos);

struct node *del(struct node *start,int data);
//
struct node *reverse(struct node *start);
int main()
{
    struct node *start = NULL;
    /*int choice,data,item,pos;
    while(1)
    {
        cout<<"1.Create List\n2.Dispaly\n3.Count\n4.Search\n5.!!Warning Add to Begining (NOT MORE Case of Empty lnklist)\n6.Add at End\n7.Add before node\n8.Add after node"
        "\n9.Add at position\n10.Delete\n11.Reverse\n12.Quit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: start = createdoublelList(start);break;
            case 2: display(start);break;
            // case 3: count(start);break;
            // case 4: cout<<"Enter data to be searched";
                    // cin>>data;
                    // search(start,data);
                    // break;
            case 5: cout<<"Enter data to be inserted ";
                    cin>>data;
                    start = add_atBeg(start,data);
                    break;
            case 6: cout<<"Enter data to be inserted ";cin>>data;start = add_atEnd(start,data);break;
        	case 7: cout<<"Enter data to be inserted ";cin>>data;cout<<"Enter the data Before which to be inserted ";cin>>item;start = add_Before(start,data,item);break;
        	case 8: cout<<"Enter data to be inserted ";cin>>data;cout<<"Enter the data After which to be inserted ";cin>>item;start = add_After(start,data,item);break;
            // case 9: cout<<"Enter data to be inserted ";cin>>data;cout<<"Enter the position at which to be inserted ";cin>>pos;start = add_atpos(start,data,pos);break;
             case 10: cout<<"Enter data to be deleted ";cin>>data;start = del(start,data);break;
            case 11: start = reverse(start);break;
            case 12: exit(0);break;
            default: cout<<"Try again ";break;
        }
    }
    getch();*/
    start = addtoEmpty(start,10);
    start = add_atBeg(start,5);
    start = add_atEnd(start,20);
    start = add_atEnd(start,30);
    start = add_atBeg(start,15);
    printf("List is  = \n");
    display(start);
    start = del(start,10);
    printf("List after deletion is  = \n");
    display(start);
    
    return 0;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
struct node* createdoublelList(struct node *start)
{
    int n,data;
    cout<<"Enter no of nodes ";
    cin>>n;
    start = NULL;
    if(n==0)
        return start;
    cout<<"Enter data ";
    cin>>data;
    start = addtoEmpty(start,data); //!! addToEmpty not add_atBeg 
    for(int i=2;i<=n;i++)
    {
        cout<<"Enter data ";
        cin>>data;
        start = add_atEnd(start,data);
    }
    return start;
}
struct node* addtoEmpty(struct node* start,int data)
{
    struct node* newnode = new node();
    newnode->prev = NULL; 
    newnode->next = NULL;       // changes
    newnode->data = data;

    start = newnode;
    return start;
}
struct node* add_atBeg(struct node* start,int data) // Not now same for empty list insertion
{
    struct node* newnode = new node();
    newnode->prev = NULL;       // the prev pointer of first node is Null
    newnode->data = data;
    newnode->next = start;      // changes
    
    start->prev = newnode;      
    start = newnode;
    return start;
}

struct node* add_atEnd(struct node* start,int data)
{
    struct node *newnode,*p;
    newnode = new node();
    newnode->data = data;
    p = start;
    while(p->next != NULL)
        p = p->next;
    p->next = newnode;
    newnode->next = NULL;
    newnode->prev = p;
    return start;
}
struct node *add_Before(struct node *start,int data,int item)
{
	struct node *newnode,*p;
	newnode = new node();
    
    if(start == NULL)
    {
        cout<<"Empty list (B) ";
        return start;
    }
    if(item==start->data)       // If node to be inserted is first node in Llist
    {
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
        return start;
    }
	p = start;
	while(p->next!=NULL)
	{
		if(p->next->data == item)
		{
			newnode->data = data;
			newnode->next = p->next;
			newnode->prev = p;
			p->next->prev = newnode;
			p->next = newnode;
			return start;
		}
		p = p->next;
	}
	cout<<"Before-error No Element with given value = "<<item<<" found";
	return start;
}
struct node *add_After(struct node *start,int data,int item)
{
    struct node* newnode,*p;
    newnode = new node();
    p = start;
    while(p!=NULL)
    {
        if(p->data == item)
        {
            newnode->data = data;
            newnode->next = p->next;
            newnode->prev = p;
            p->next = newnode;
            if(p->next!=NULL)
                p->next->prev = newnode;
            return start;
        }
        p = p->next;
    }
    cout<<"After-error No Element with given value = "<<item<<" found";
    return start;
}
// /---------
struct node *del(struct node *start,int data)
{
    struct node *temp;
    if(start==NULL)    //Empty
    {
        cout<<"UNDERFLOW ";
        return start;
    }
    // deletion of only node
    if(start->next == NULL)
    {
        cout<<"Deletion is performed for only single node "<<endl;
        if(start->data == data)
        {
            temp = start;
            start = NULL;
            delete temp;
            return start;
        }
        else
        {
            cout<<"No element with item = "<<data<<" found"<<endl;
            return start;
        }
    }
    // delete first node
    if(start->data == data)     
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        delete temp; 
        return start;
    }
    
    temp = start->next;
    while(temp->next != NULL)
    {   
        if(temp->data == data )             // deletion in list
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return start;
        }
        temp = temp->next;
    }
    if(temp->data == data)        // deletion of last node
    {
        temp->prev->next = NULL;
        delete temp;
        return start;
    }
    cout<<"DELETE-error No Element with given value = "<<data<<" found"<<endl;
    return start;   
}
void display(struct node *start)
{
    if(start==NULL)
    {
        cout<<"Double LL is empty "<<endl;
        return ;
    }
    struct node *temp = new node();
    temp = start;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

struct node *reverse(struct node *start)
{
    struct node *p,*q;
    p = start;
    q = p->next; // start->next;
    p->next = NULL;
    p->prev = q;
    while(q!=NULL)
    {
        q->prev = q->next;
        q->next = p;
        p = q;
        q = q->prev;
    }
    start = p;
    return start;
}