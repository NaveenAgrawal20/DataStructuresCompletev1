#include <iostream>
#define MAX 5000

using namespace std;
/*logic = 
1. all ele to left of pivot is less than eqaul to pivot i.e. a[left] <= a[pivot] 
1. all ele to right of pivot is greater than eqaul to pivot i.e. a[right] >= a[pivot] 
*/
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
    int pivot, i, j,flag=0;
    pivot = high;
    i = low-1;
    for(j=low;j<high;j++)
    {
        if(arr[j]<=arr[pivot])
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // if i > j then we have find the suitable place for pivot so exchnage [j] with [pivot]
    temp = arr[pivot];
    arr[pivot] = arr[i+1];
    arr[i+1] = temp;
    display(arr,n);
    return i+1;
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