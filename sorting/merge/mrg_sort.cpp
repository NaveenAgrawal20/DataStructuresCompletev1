#include<iostream>
using namespace std;
#define MAX 10
//Sort two different sorted array into one sorted array
void display(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	printf("\n");
}

int main()
{
	int n,m;
   	int i,j,a[MAX],b[MAX];
   	cout<<"Enter size of array a ";
    cin>>n;
    cout<<"Enter elements of array in sorted order ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    display(a,n);
    
    cout<<"Enter size of array b ";
    cin>>m;
    cout<<"Enter elements of array in sorted order ";
    for(j=0;j<m;j++)
    {
        cin>>b[j];
    }
    display(b,m);
    
    // Merge sort
    int t = n+m;
    int k =0,c[t];
    for(i=0,j=0;i<n && j<m;)
    {
//    	cout<<a[i]<<" and "<<b[j]<<endl;
		cout<<" i = "<<i<<" and j = "<<j<<endl;
    	if(a[i] < b[j] )
    		c[k++] = a[i++];
		else
			c[k++] = b[j++]; 
	}
	cout<<"Out i = "<<i<<" and j = "<<j<<endl;
	while(i<n)
		c[k++] = a[i++];

	while(j<m)
		c[k++] = b[j++];
	cout<<"display"<<endl;
	display(c,t);
	return 0;
}
