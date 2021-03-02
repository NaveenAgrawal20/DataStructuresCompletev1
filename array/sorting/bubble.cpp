#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// logic 1
void bubble_s1(int *a,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
}
// logic 2
void bubble_s2(int *a,int n)
{
	int i,j,swa = 1,cnt = 0;
    for(i=0;i<n-1&&swa == 1;i++)
    {
    	swa = 0;
        for(j=0;j<n-i-1;j++)
        {
        	cnt++;
            if(a[j] > a[j+1])
            {
            	swap(&a[j],&a[j+1]);
            	swa = 1;
			}
        }
    }
    cout<<"Comparison are = "<<cnt<<endl;
}
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}

int main()
{
    int n,i,j;
    cout<<"Enter array size ";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<"\t";
        cin>>a[i];
    }
    // logic 1
//    bubble_s1(a,n);
//    display(a,n);
    // logic 2
	bubble_s2(a,n);
    display(a,n);
    return 0;
}
