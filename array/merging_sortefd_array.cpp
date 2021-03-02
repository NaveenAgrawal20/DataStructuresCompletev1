#include<iostream>
using namespace std;

void display(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int n,m,i,j,k;
    cout<<"Enter 1st array size  ";
    cin>>n;
    int *a1 = new int[n];
    for( i=0;i<n;i++)
    {
        cout<<"Enter array "<<i+1<<" element ";
        cin>>a1[i];
    }
    cout<<"Enter 2nd array size ";
    cin>>m;
    int *a2 = new int[n];
    for( i=0;i<m;i++)
    {
        cout<<"Enter array "<<i+1<<" element ";
        cin>>a2[i];
    } 
    display(a1,n);
    display(a2,m);

    // sort
    int t = n+m;
    int *b = new int[n+m];
    k = 0;
    for(i=0,j=0;i<n && j<m;)
    {
        if(a1[i] < a2[j])
            b[k++] = a1[i++];
        else
            b[k++] = a2[j++];
    }
    while(i<n)
        b[k++] = a1[i++];
    while(j<m)
        b[k++] = a2[j++];
    display(b,t); 
    return 0;
}
//5
//1 3 7 9 12
//7
//2 4 5 6 8 10 11
