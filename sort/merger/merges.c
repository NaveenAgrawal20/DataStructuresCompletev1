/*
 * Create By Naveen
 * Created on Thu Feb 11 2021
 * Copyright © 2021
 */

#include <stdio.h>
#include <stdlib.h>

void display(int *a,int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void merge(int *a, int *c, int l1, int l2, int u1, int u2,int siz, int *k)
{
    for (;l1 <= u1 && l2 <= u2;)
        if (a[l1] < a[l2])
            c[(*k)++] = a[l1++];
        else
            c[(*k)++] = a[l2++];
    while (l1 <= u1)
        c[(*k)++] = a[l1++];
    while (l2 <= u2)
        c[(*k)++] = a[l2++];
}

void copyArr(int *a, int *c,int siz)
{
    for(int i = 0;i<siz;i++)
        a[i] = c[i];
}

int mergeSort(int *arr, int siz)
{
    int *temparr = (int *)malloc(siz * sizeof(int));
    int sz, l1, l2, u1, u2, i, j, k;
    sz = 1;
    while (sz < siz)
    {
        k = 0;
        l1 = 0;
        while (l1 + sz < siz)
        {
            l2 = l1 + sz;
            u1 = l2 - 1;
            u2 = u1 + sz < siz ? u1 + sz : siz - 1;
            merge(arr,temparr,l1,l2,u1,u2,siz,&k);
            l1 = u2+1;
        }
        while (k<siz)
        {
            temparr[k] = arr[k];
            k++;
        }
        copyArr(arr,temparr,siz);
        sz *= 2;
    }
}

int main()
{
    int n;
    printf("Enter size ");
    scanf("%d",&n);
    int *a = (int*)malloc(n * sizeof(int));
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    display(a,n);
    mergeSort(a,n);
    display(a,n);
    return 0;
}