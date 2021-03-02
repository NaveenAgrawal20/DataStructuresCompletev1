#include <iostream>
#define MAX 20
using namespace std;

void display(int *a,int siz)
{
    for(int i=0;i<siz;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
// recursive
void merges(int *m1,int *m2,int l1,int u1,int l2,int u2)
{
    int i,j,k;
    k = l1;
    for(i=l1,j=l2;i<=u1 && j<=u2;)
    {
        if(m1[i] < m1[j])
            m2[k++] = m1[i++];
        else
            m2[k++] = m1[j++];
    }
    while(i<=u1)
        m2[k++] = m1[i++];
    while(j<=u2)
        m2[k++] = m1[j++];
}
void copy_array(int *a,int *t,int low,int high)
{
    for(int i=low;i<=high;i++)
        a[i] = t[i];
}
void ree_mergesort(int *a,int low,int high)
{
    int mid = (high+low)/2;
    int t[MAX];
    if(low >= high)
        return;
    ree_mergesort(a,low,mid);
    ree_mergesort(a,mid+1,high);
    // Merge arr[low:mid] and arr[mid+1:high]
    merges(a,t,low,mid,mid+1,high);
    copy_array(a,t,low,high);
}

int main()
{
    int n;
    cout << "Enter number of elements ";
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" ";
        cin>>a[i];
    }
    display(a,n);
    ree_mergesort(a,0,n-1);
    display(a,n);
    return 0;
}
