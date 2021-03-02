#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 30

int read(int *a)
{
    int i,n;
    printf("Enter num o elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("ENter element ");
        scanf("%d",&a[i]);
    }
    return n;
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void insertsort(int a[],int n)
{
    int k,i,j;
    for(i=1;i<n;i++)
    {
        k = a[i];
        for(j=i-1;j>=0 && k<a[j];j--)
            a[j+1] = a[j];
        a[j+1] = k;
    }
}
void swap(int *x,int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
};
int bubble(int arr[],int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}
int main()
{
    int n;
	int a[MAX];
    n = read(a);
    printf("Array\n");
    display(a,n);
    insertsort(a,n);
    display(a,n);
    printf("Bubble sort\n");
    n = read(a);
    printf("Array\n");
    display(a,n);
    bubble(a,n);
    display(a,n);
    return 0;
}