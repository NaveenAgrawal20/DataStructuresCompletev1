#include<stdio.h>
#include<stdlib.h>

void display(int[], int);
void swap(int *a, int *b);

void insertHeap(int a[],int idx)
{
    int temp = a[idx];
    while( idx > 1 && temp > a[idx/2] )
    {
        a[idx] = a[idx/2];
        idx = idx/2;
    }
    a[idx] = temp;
}
void deleteHeap(int a[], int n)
{
    int temp = a[1],i,j,k;
    i = 1; // root
    j = 2*i; // root left
    k = 2*i+1; // left
    // int larg = 0;
    a[1] = a[n];    
    a[n] = temp; // insert deleted item to last in Heap.
    // while(larg < n)
    // {
    //     if(a[j] < a[k]) //  rchild greater than lchild
    //         larg = k;
    //     else
    //         larg = j;
    //     if(a[i] < a[larg])
    //     {
    //         swap(&a[i],&a[larg]);
    //         i = larg;
    //         j = 2*i;
    //         k = 2*i+1;
    //     }
    //     else
    //         break;
    // }
    while(j <= n-1)
    {
        if(j < n-1 && a[j] < a[j+1]) //  rchild greater than lchild
            j = j+1;
        if(a[i] < a[j])
        {
            swap(&a[i],&a[j]);
            i = j;
            j = 2*j;
        }
        else
            break;
    }
}

void createHeap(int a[],int n)
{
    for(int i = 1;i<=n;i++)
        insertHeap(a,i);
}
void heapSrt(int a[],int n)
{
    createHeap(a,n);
    for(int i = n;i >= 1;i--)
        deleteHeap(a,i); // here i = size
}

int main()
{
    int a[] = {0,20, 13, 12, 10, 1, 5, 1, 4, 2, 4, 9, 11,3,12};
    // int a[] = {0,30,20,15,5,10,12,6,40};
    // int a[] = {0,40,29,30,15,10,25,5};
    int n = sizeof(a) / sizeof(int) - 1; //+1 0 not included
    printf("SIZE = %d\n",n);
    // createHeap(a,n);
    // deleteHeap(a,n);
    heapSrt(a,n);
    display(a,n);
    return 0;
}
//////////////////////////
//////////////////////////
//////////////////////////
void display(int A[], int siz)
{
    for (int i = 1; i <= siz; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}