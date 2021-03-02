/*
 * Created By Naveen
 * Created on 2021
 * Copyright © 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct node
{
    int data;
    struct node *link;
} *start = NULL;
typedef struct node node;
int largest_digit(int a[], int size) // find largest num in array
{
    int mx = INT_MIN;
    while (size)
        mx = mx < a[size--] ? a[size] : mx;
    return mx;
}

int count(int num) // count digits in largest num
{
    return log10(num) + 1;
}

int digit(int num, int k) // find kth digit
{
    int d;
    for (int i = 1; i <= k; i++)
    {
        d = num % 10;
        num /= 10;
    }
    return d;
}
node* eleToNode(int key)
{
    node *q;
	//acquire memory for the new node
	q=(node*)malloc(sizeof(node));
    q->data=key;
    q->link=NULL;
    return q;
}
int nodeToEle(node *m)
{
    return m->data;
}
void radixSort(int a[],int size)
{
    node *front[10], *rear[10], *p;
    int m,d,c,k,i,j;
    m = largest_digit(a,size);
    c = count(m);
    for(k = 1;k<=c;k++)
    {
        // make all queue initailly NULL (Empty)
        for(i = 0;i<10;i++)
        {
            front[i] = NULL;
            rear[i] = NULL;
        }
        // filling queue with digits
        for(i = 0;i<size;i++)
        {
            d = digit(a[i],k);
            node *p = eleToNode(a[i]);
            if(front[d] == NULL)
                front[d] = p;
            else
                rear[d]->link = p;
            rear[d] = p;
        }
        // join all
        for(i = 0;i<size;i++)
        {
            if(front[i] != NULL)
                a[i] = nodeToEle(front[i]);
        }
    }
}

int main()
{
    int n;
    printf("Enter size ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        printf("%d\t", count(a[i]));
    return 0;
}