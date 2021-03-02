#include<iostream>
using namespace std;
void display(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void merge_sort(int a[],int n)
{
    int l1,l2,u1,u2,t[n],i,sz,j,k;
    sz = 1;
    while(sz<n)
    {
        k = 0;
        l1 = 0;
        while(l1+sz<n)
        {
            l2 = l1+sz;
            u1 = l2-1;
            u2 = u1+sz<n?u1+sz:n-1;
            // merging two array into sorted order in 1 
            
            for(i=l1,j=l2;i<=u1 && j<=u2;)
            {
                if(a[i]<a[j])
                    t[k++] = a[i++];
                else
                    t[k++] = a[j++];
            }
            // copying remaining elements 
            while(i<=u1)
                t[k++] = a[i++];
            while(j<=u2)
                t[k++] = a[j++];
            l1 = u2+1;
        }
        // copying last element not in pair
        while(k<n)
        {
            t[k] = a[k];
            k++;
        }
        // copying "t" (now sorted) array into "a" array again
        for(i=0;i<n;i++)
            a[i] = t[i];
        
        sz *= 2;
    }
}

int main()
{
    int n;
    cout<<"Enter n ";cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cout<<"Enter "<<i+1<<" element ";
        cin>>a[i];
    } 
    
    display(a,n);
    merge_sort(a,n);
    display(a,n);
    
    return 0;
}