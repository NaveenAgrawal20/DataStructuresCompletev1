#include<iostream>
#include<math.h>
using namespace std;

struct node{
    int data;
    struct node* link;
}*start = NULL;


int largest_dgit()
{
    int large=0;
    struct node *temp;
    temp = start;
    while(temp!=NULL)
    {
        if(large<temp->data)
                large = temp->data;
        temp = temp->link;
    }
    return large;
}
int digit(int num,int k)
{
    int d;
    for(int i=1;i<=k;i++)
    {
        d = num%10;
        num = num/10;
    }
    return d;
}
int count(int max)
{
    return floor(log10(max))+1;
}

void radix_sort()
{
    struct node *frnt[10],*rear[10],*p;
    int i,j,d,m,k,dig;
    m = largest_dgit();
    d = count(m);
    for(k=1;k<=d;k++)
    {
        // make all queues empty at beginning
        for(i=0;i<10;i++)
        {
            frnt[i] = NULL;
            rear[i] = NULL;
        }
        // filling queue with digits
        for(p = start;p!=NULL;p=p->link)
        {
            dig = digit(p->data,k);
            if(frnt[dig]==NULL)    // first entry in digit queue
                frnt[dig] = p;
            else
                rear[dig]->link = p;
            rear[dig] = p;
        }
        // Join all
        i = 0;
        while(frnt[i]==NULL)
            i++;
        start = frnt[i];
        while(i<9)
        {
            if(rear[i+1] != NULL)
                rear[i]->link = frnt[i+1];
            else
                rear[i+1] = rear[i];
            i++;
        }
        rear[9]->link = NULL;
    }

}

void display()
{
    cout<<endl;
    struct node *temp;
    temp = start;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->link;
    }
    cout<<endl;
}
int main()
{
    int n,i,item;
    struct node *newnode,*q;
    cout<<"Enter number of elements ";
    cin>>n;
    // linked list insertion
    for(i=0;i<n;i++)
    {
        cout<<"Enter data "<<i+1<<" : ";
        cin>>item;

        // inserting
        newnode = new node();
        newnode->data = item;
        newnode->link = NULL;
        if(start==NULL) //1st element
            start = newnode;
        else
        {
            q = start;
            while(q->link!=NULL)
                q = q->link;
            q->link = newnode;
        }
    }
    display();
    radix_sort();
    display();
    return 0;
}
//14 12  4  24  124  6  756  75  45  23  39  43  12  4  2
