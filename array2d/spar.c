#include<stdio.h>
#define MAX 20


void display(int arr[MAX][MAX],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%2d\t",arr[i][j]);
		}
        printf("\n");
    }
}

int main()
{
    int i,j;
    int r=5,c=6,count=0;
    // printf("
    int spm[r][c] =
    {
        {0 , 0 , 0 , 0 , 9, 0 },
        {0 , 8 , 0 , 0 , 0, 0 },
        {4 , 0 , 0 , 2 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 5 },
        {0 , 0 , 2 , 0 , 0, 0 }
    };
    display(spm,5,6);

    /*
    for(i=0;i<r;i++)
        for(j=0;j<r;j++)
            if(spm[i][j]!=0)
                count++;
    */
    printf("\n\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d\t",spm[i][j]);
        printf("\n");
    }
    /*
    int result[3][6],k=0;
    for(i=0;i<r;i++)
        for(j=0;j<count;j++)
            if(spm[i][j]!=0)
            {
                result[0][k] = r;
                result[1][k] = c;
                result[2][k] = spm[i][j];
                k++;
            }
    display(result,3,count);*/
    return 0;
}
