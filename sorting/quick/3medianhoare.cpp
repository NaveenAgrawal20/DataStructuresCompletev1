#include <iostream>
#define MAX 5000

using namespace std;
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
}
int partition(int arr[],int low,int high,int n)
{
    int pivot,mid,i,j,temp;
    mid = (low+high)/2;
    i = low;
    j = high;
    if(arr[mid] < arr[low])
        {temp = arr[low];
        arr[low] = arr[mid];
        arr[mid] = temp;}
    if(arr[low] > arr[high] )
    {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    if(arr[mid] > arr[high])
    {
        temp = arr[mid];
        arr[mid] = arr[high];
        arr[high] = temp;
    }
    pivot = arr[high];
    for(j=low;j<=high;j++)
    {
        if(arr[j]<arr[pivot])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        	i++;
        }
    }
    return j;
}
void quick(int arr[],int low,int high,int n)
{
    if(low>=high)
        return;
    int pivot = partition(arr,low,high,n);
    quick(arr,low,pivot,n);
    quick(arr,pivot+1,high,n);
}
int main()
{
    int a[MAX], n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quick(a, 0, n-1,n);  
    display(a,n);
    return 0;
}