#include<stdio.h>
#include<math.h>
#define MAX 10

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

int check_symmetric(int arr[][MAX],int r,int c)
{
    int i,j;
    if(r!=c)
		return 0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			if(arr[i][j] !=arr[j][i])
				return 0;
	}
	return 1;
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
    display(a,r,c);
    int ans = check_symmetric(a,r,c);
    if(ans==1)
    	printf("Symmetric matrix ");
    else
    	printf("Not Symmetric matrix ");
    return 0;
}
