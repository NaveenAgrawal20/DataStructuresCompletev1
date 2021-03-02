#include <iostream>
#include <conio.h>
#define MAX 20

using namespace std;
/*logic = 
1. all ele to left of pivot is less than eqaul to pivot i.e. a[left] <= a[pivot] 
1. all ele to right of pivot is greater than eqaul to pivot i.e. a[right] >= a[pivot] 
*/
void quick(int arr[],int low,int high);
int partition(int arr[], int low, int high);
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int a[MAX], n, i;
    cout << "Enter number of elements ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter elements " << i + 1 << " ";
        cin >> a[i];
    }
    cout << "Sorted list is :\n";
    quick(a, 0, n-1);
    
    display(a, n);
    return 0;
}
void quick(int arr[],int low,int high)
{
    int pivot;
    // cout<<"--------------------------------------------------------"<<endl;
    // cout<<"quick called with low = "<<low<<" and high = "<<high;
    if(low>=high)
    {
        return;
    }
    pivot = partition(arr,low,high);
    quick(arr,low,pivot-1); //  left
    quick(arr,pivot+1,high); //  right
}
int partition(int arr[], int low, int high)
{
    int temp;
    int pivot, i, j;
    pivot = low;
    i = low+1;
    j = high;
    while (i <= j)
    {
        while (arr[i] < arr[pivot] && i < high) //to keep i under array bound
        {
		    i++;
    	}
		while (arr[j] > arr[pivot])
        {
		    j--;
    	}
		//exchange [i] and [j]
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else
        	i++;
    }
    // if i > j then we have find the suitable place for pivot so exchnage [j] with [pivot]
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    return j;
}
//3 12 5 19 1 17 
//3 18 8 17 10 18 17 2 18 5
//3 18 8 17 10 18 17 2
