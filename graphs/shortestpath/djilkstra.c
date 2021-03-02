#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define NIL -1
#define INF 9999
#define PERM 1
#define TEMP 0


int minimnumVertex(int *pathArr,int v,int *status)
{
    int k = NIL;
    int min = INT_MAX;
    for(int i = 0;i<v;i++)
    {
        if(status[i] == TEMP && min>pathArr[i])
        {
            min = pathArr[i];
            k = i;
        }
    }
    return k;
}
void djikstra(int **a,int pathLen[],int *pred,int *status,int v,int src)
{
    int i,j;
    for(i = 0;i<v;i++)
    {
        pathLen[i] = INF;
        pred[i] = NIL;
        status[i] = TEMP;
    }
    pathLen[src] = 0;
    
    int currentV;
    i = 0;
    while(i<v)
    {
        currentV = minimnumVertex(pathLen,v,status);
        status[currentV] = PERM;
        for(int j = 0;j<v;j++)
        {
            if(status[j] == TEMP && a[currentV][j] != 0)
            {
                if( pathLen[currentV] + a[currentV][j] < pathLen[j])
                {
                    pathLen[j] = pathLen[currentV] + a[currentV][j];
                    pred[j] = currentV;
                }
            }
        }
        i++;
    }
}
void displayTable(int pathLen[],int *pred,int *status,int v)
{
    printf("VERTEX  PATHLENGTH  PREDESSOR  STATUS\n");
    for(int i = 0;i<v;i++)
    {
        printf("%d\t%d\t",i,pathLen[i]);
        if(pred[i] == -1)
            printf("\tNIL");
        else
            printf("\t%d",pred[i]);
        if(status[i] == 1)
            printf("\tPERM\n");
        else
            printf("\tTEMP\n");
    }
}
int main()
{
    int src, n;
	printf("Enter number of vertices ");
	scanf("%d",&n);
    int **a = (int **)malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        a[i] = (int *)malloc(sizeof(int)*n);
    }

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		    scanf("%d",&a[i][j]);
    
        // Initializing other arrays.
    int *status = (int*)malloc(sizeof(int)*n);
    int *pathLen = (int*)malloc(sizeof(int)*n);
    int *pred = (int*)malloc(sizeof(int)*n);

    printf("Enter source vertex ");
    scanf("%d",&src);
    djikstra(a,pathLen,pred,status,n,src);
    displayTable(pathLen,pred,status,n);
    return 0;
}
/*
8
0 8 2 7 0 0 0 0
0 0 0 0 0 16 0 0
5 0 0 4 0 0 3 0
0 0 0 0 9 0 0 0
4 0 0 0 0 5 0 8
0 0 0 0 0 0 0 0
0 0 6 3 4 0 0 0
0 0 0 0 0 2 5 0
0
*/