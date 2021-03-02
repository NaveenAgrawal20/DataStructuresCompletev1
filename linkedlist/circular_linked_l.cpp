#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int info;
    struct node* link;
};

void display(struct node *last);
// void count(struct node *last);
// void search(struct node *last,int data);

struct node *create_list(struct node *last);
struct node* addtoEmpty(struct node* last,int data);
struct node *addatbeg(struct node *last,int data);
struct node *addatend(struct node *last,int data);
struct node *addafter(struct node *last,int data,int item);
struct node *del(struct node *last,int data);

int main( )
{
	int choice,data,item;
	struct node	*last=NULL;
	
	// while(1)
	// {
	// 	printf("1.Create List\n");
	// 	printf("2.Display\n");
	// 	printf("3.Add to empty list\n");
	// 	printf("4.Add at beginning\n");
	// 	printf("5.Add at end\n");
	// 	printf("6.Add after \n");
	// 	printf("7.Delete\n");
	// 	printf("8.Quit\n");
		
	// 	printf("Enter your choice : ");
	// 	scanf("%d",&choice);

	// 	switch(choice)
	// 	{
	// 	 case 1:
	// 		last=create_list(last);
	// 		break;
	// 	  case 2:
	// 	 	display(last);
	// 	 	break;
	// 	  case 3:
	// 	 	printf("Enter the element to be inserted : ");
	// 	 	scanf("%d",&data);
	// 	 	last=addtoEmpty(last,data);
	// 	 	break;
	// 	  case 4:
	// 	 	printf("Enter the element to be inserted : ");
	// 	 	scanf("%d",&data);
	// 	 	last=addatbeg(last,data);
	// 	 	break;
	// 	  case 5:
	// 	 	printf("Enter the element to be inserted : ");
	// 	 	scanf("%d",&data);
	// 	 	last=addatend(last,data);
	// 	 	break;
	// 	  case 6:
	// 	 	printf("Enter the element to be inserted : ");
	// 	 	scanf("%d",&data);
	// 	 	printf("Enter the element after which to insert : ");
	// 	 	scanf("%d",&item);
	// 	 	last=addafter(last,data,item);
	// 	 	break;
	// 	  case 7:
	// 	 	printf("Enter the element to be deleted : ");
	// 	 	scanf("%d",&data);
	// 		last=del(last,data);
	// 		break;
	// 	 case 8:
	// 	 	exit(1);
	// 	 default:
	// 		printf("Wrong choice\n");
	// 	}/*End of switch*/
	// }
	/*End of while*/ 

	last = addtoEmpty(last,10);
    last = addatbeg(last,5);
    last = addatend(last,20);
    last = addatend(last,30);
    last = addatbeg(last,15);
    printf("List is  = \n");
    display(last);
    last = del(last,10);
    printf("List after deletion is  = \n");
    display(last);
    return 0;
}/*End of main( )*/
struct node* addtoEmpty(struct node *last,int data)
{
	struct node *newnode;
    newnode = new node();
	newnode->info = data;
	last = newnode;
	last->link = last; 	//itself
	return last;
}
struct node *addatbeg(struct node *last,int data)
{
     struct node *newnode;
     newnode = new node();
     newnode->info = data;
     newnode->link = last->link;
     last->link = newnode;
     return last;
}
struct node *addatend(struct node *last,int data)
{
	struct node *newnode;
	newnode = new node();
	newnode->info = data;
	newnode->link = last->link;
	last->link = newnode;
	last = newnode;  // last points to the end element inserted
	return last;
}
struct node *create_list(struct node *last)
{
	int n,i,data;
	cout<<"Enter number of nodes ";
	cin>>n;
	last = NULL;
	if(n==0)
	{
		cout<<"No node inserted";
		return last;
	}cout<<"Enter element to be inserted ";
	cin>>data;
	last = addtoEmpty(last,data);
	for(i=2;i<=n;i++)
	{
		cout<<"Enter element to be inserted ";
		cin>>data;
		last = addatend(last,data);
	}
	return last;
}
void display(struct node *last)
{
	struct node *temp;
	if(last==NULL)
	{
		cout<<"List is Empty "<<endl;
		return;
	}
	temp = last->link;  // Not from last but from first which is last->link
	do
	{
		cout<<temp->info<<"\t";
		temp = temp->link;
	}while(temp != last->link);  // as we already initailize temp with last->link
	cout<<endl;
}
struct node *addafter(struct node *last,int data,int item)
{
	struct node *newnode,*p;
	newnode = new node();
	p = last->link;		
	do
	{
		if(p->info == item)
		{
			newnode->info = data;
			newnode->link = p->link;
			p->link = newnode;
			if(p==last)
				last = newnode;
			return last;
		}
		p = p->link;
	}while(p != last->link);
	cout<<item<<" DO not exists"<<endl;
	return last;
}
struct node *del(struct node *last,int data)
{
	struct node *temp,*p;
	//only node
	if(last->info == data && last->link == last)
	{
		temp = last;
		last = NULL;
		delete temp;
		return last;
	}
	//first
	if(last->link->info==data)
	{
		temp = last->link;
		last->link = temp->link;
		delete temp;
		return last;
	}
	//middle 
	p = last->link;
	while (p->link != last)
	{
		if(p->link->info==data)
		{
			temp = p->link;
			p->link = temp->link;
			delete temp;
			return last;
		}
		p = p->link;
	}
	//end
	if(last->info==data)
	{
		temp = last;
		p->link = last->link;
		last = p;
		delete temp;
		return last;
	}
}
