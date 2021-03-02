#include<stdio.h>
#include<conio.h>

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
void selectionsort(int arr[],int size)
{
	int i,j,*min;
	for(i=0;i<size-1;i++)
	{
		min = &arr[i];
		for(j=i+1;j<size;j++)
		{
			if(*min > arr[j])
				swap(&arr[j],min);
		}
	}
}
void insertionsort(int arr[],int size)
{
	int i,j,k;
	for(i=1;i<size;i++)
	{
		k = arr[i];
		for(j=i-1;j>=0 && k < arr[j];j--)
		{ 
			arr[j+1] = arr[j];
		}
		arr[j+1] = k;
	}
}
void display(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		int m = *(arr+i);
		printf("%d ",m);
	}
	printf("\n");
}
int main()
{
	int a[6] = {18,5,8,14,21,2};
    display(a,6);
    bubble(a,6);
    display(a,6);
	selectionsort(a,6);
    display(a,6);
    insertionsort(a,6);
    display(a,6);
    getch();
    return 0;
}
