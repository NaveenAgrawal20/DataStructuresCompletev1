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
    int pivot,i,j,temp;
    pivot = (low+high)/2;
    i = low - 1;
    j = high + 1;
    while(true)
    {
        do{
            i++;
        }while(arr[i] < arr[pivot]);
        do
        {
            j--;
        } while (arr[j] > arr[pivot]);
        if(i>=j)
            return j;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
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