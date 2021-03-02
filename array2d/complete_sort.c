#include<stdio.h>
#define MAX 10

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int arr[][MAX],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}

void sort(int arr[][MAX],int row,int col)
{
	int i,j,k,l;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            for(k = j==col-1?i+1:i;k<row;k++)
            	for(l= k==i?j+1:0;l<col;l++)
            		if(arr[i][j] > arr[k][l])
                		swap(&arr[i][j],&arr[k][l]);
}
int main()
{
    int i,j,r,c,a[MAX][MAX] = {0};
    printf("Enter no of rows ");
    scanf("%d",&r);
    printf("Enter no of columns ");
    scanf("%d",&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter element a[%d][%d] ",i+1,j+1);
            scanf("%d",&a[i][j]);
    	}
    }
    printf("Matrix is \n");
    display(a,r,c);
    printf("Sorted column elements matrix is \n");
    sort(a,r,c);
    display(a,r,c);
    return 0;
}
