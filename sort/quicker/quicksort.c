#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a,int low, int high)
{
    int i, pivot,j;
    pivot = low;
    i = pivot+1;
    j = high;
    while(i<=j)
    {
        while(a[i] < a[pivot] && i<high)
            i++;
        while(a[j] > a[pivot])
            j--;
        
        if(i<j)
        {
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
        else
            i++;
    }
    swap(&a[j],&a[pivot]);
    return j;
}

void quickSort(int *a, int low,int high)
{
    int pivot;
    if(low < high)
    {
        pivot = partition(a,low,high);
        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);
    }
}
void display(int *a,int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int n;
    printf("Enter size ");
    scanf("%d",&n);
    int *a = (int*)malloc(n *sizeof(int)); 
    for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
    display(a,n);
    quickSort(a,0,n-1);
    printf("\n RESULT \n");
    display(a,n);
    return 0;
}