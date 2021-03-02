#include <iostream>
#define MAX 5000

using namespace std;
// using lomuto
/*algorithm quicksort(A, lo, hi) is
    if lo < hi then
        p := partition(A, lo, hi)
        quicksort(A, lo, p - 1)
        quicksort(A, p + 1, hi)

algorithm partition(A, lo, hi) is
    pivot := A[hi]
    i := lo
    for j := lo to hi do
        if A[j] < pivot then
            swap A[i] with A[j]
            i := i + 1
    swap A[i] with A[hi]
    return i*/
void quick(int arr[],int low,int high,int n);
int partition(int arr[], int low, int high,int n);
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
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
    return 0;
}
void quick(int arr[],int low,int high,int n)
{
    int pivot;
    if(low>=high)
    {
        return;
    }
    pivot = partition(arr,low,high,n);
    quick(arr,low,pivot-1,n); //  left
    quick(arr,pivot+1,high,n); //  right
    
}
int partition(int arr[], int low, int high,int n)
{
    int temp;
    int pivot, i, j;
    pivot = high;
    i = low;
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
    // if i > j then we have find the suitable place for pivot so exchnage [j] with [pivot]
    temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;
    display(arr,n);
    return i;
}
//3 12 5 19 1 17
//3 18 8 17 10 18 17 2 18 5
//3 18 8 17 10 18 17 2

//7
//1 3 9 8 2 7 5

//10
//1 2 3 4 5 6 7 8 9 10

//10
//10 9 8 7 6 5 4 3 2 1

//7
//5 3 8 4 6 3 2

//10
//6 1 7 9 3 8 2 5 4 0

//9
//9 8 6 7 3 5 4 1 2
//
//Output:
//
//1 2 6 7 3 5 4 9 8
//
//1 2 6 7 3 5 4 8 9
//
//1 2 3 4 6 5 7 8 9
//
//1 2 3 4 6 5 7 8 9
//
//1 2 3 4 5 6 7 8 9
