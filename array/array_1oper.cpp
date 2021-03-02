#include<iostream>
#define MAX 10
using namespace std;

void insert_unsorted(int a[],int *n,int item,int pos)
{
	if(pos > *n || pos <= 0)
	{
		cout<<"Invalid Position\n";
		return;
	}
	pos--;
	for(int i=*n-1;i>=pos;i--)
	{
		a[i+1] = a[i];
	}
	a[pos-1] = item;
	(*n)++;
}


int main()
{
    int n,a[MAX],pos,item,i;
    cout<<"Enter number of element ";
    cin>>n;
    // input 
    for(i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" element ";
        cin>>a[i];
    }
    //display
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\nEnter item to insert and its pos ";
    cin>>item>>pos;
    // shifting
    pos--;
//    for(i=n-1;i>=pos;i--)
//    {
//        a[i+1] = a[i];
//    }
//    a[pos] = item;
//    n++;
	insert_unsorted(a,&n,item,pos);
    //display
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}
