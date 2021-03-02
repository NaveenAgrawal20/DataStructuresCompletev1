/*
 * Created By Naveen
 * Created on 2021
 * Copyright © 2021
 */
/* COUNT SORT */
// view array (int[17]) *count DEBUGGER
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void display(int *a,int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int max(int *a, int size)
{
    int mx = INT_MIN;
    while (size--)
        mx = mx < a[size] ? a[size] : mx;
    return mx;
}
void copyCount(int *a, int *count, int countsize)
{
    for(int i= 0,k = 0;i<countsize;i++)
        if(count[i] != 0)
        {
            a[k++] = i;
            count[i]--;
            i--;
        }
}
void countSort(int *a, int size)
{
    int i, maxsize = max(a, size)+1;
    int *count = (int *)calloc(sizeof(int), maxsize); // for 0
    for (i = 0; i < size; i++)
        count[a[i]]++;
    copyCount(a,count , maxsize);
}
int main()
{
    int n;
    printf("Enter size ");
    scanf("%d",&n);
    int *a = (int*)malloc(n *sizeof(int)); 
    for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
    countSort(a,n);
    printf("RESULT \n");
    display(a,n);
}
/*
10
11 4 17 16 12 5 12 2 11 6
*/