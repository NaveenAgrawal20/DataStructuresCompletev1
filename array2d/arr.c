#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int **p,r,c;
    printf("Enter row and column ");
    scanf("%d %d",&r,&c);
   	p = (int **)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)
        p[i]= (int*)malloc(c*sizeof(int));
    printf("%d %d",r,c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Enter a[%d][%d]",i,j);
            scanf("%d",(*(p+i)+j));
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",*(*(p+i)+j) );
        }
    	printf("\n");
	}
    return 0;
}
