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
void sortCol(int arr[][MAX],int row,int col)
{
	int i,j,k,count;
    for(k=0;k<col;k++)
    {
    	count = 1;
        for(i=0;i<row-1 && count==1 ;i++)
        {
        	count = 0;
            for(j=0;j<row-i-1;j++)
                if(arr[j][k] > arr[j+1][k])
                {
                    swap(&arr[j][k],&arr[j+1][k]);
					count = 1;
				}
    	}
	}
}
int main()
{
    int i,j,r,c,a[MAX][MAX];
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
    sortCol(a,r,c);
    display(a,r,c);
    return 0;
}
