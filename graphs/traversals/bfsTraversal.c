/*
 * Create By Naveen
 * Created on Fri Feb 05 2021
 * Copyright © 2021
 */

#include<stdio.h>
#include<stdlib.h>
#include"llqueue.h"
#include"llstack.h"
#define MAX 10

// adjacency matrix
int a[MAX][MAX];
int visited[MAX];
// BFS
void bfs(int v,int siz)
{
    int dv;
    enqueue(v);
    visited[v] = 1;
    while(!isEmpty())
    {
        dv = dequeue();
        printf("%d ",dv);
        for(int i = 1;i<=siz;i++)
        {
            if(a[dv][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}
void dfs(int v,int siz)
{
    /*
    visited = 0
    explored = 1 
    */
    push(v);
    while(!stackEmpty())
    {
        v = pop();
        if(visited[v] == 0)
        {
            printf("%d ",v);
            visited[v] = 1;
        }
        for(int i=siz;i>=1;i--)
        {
            if( a[v][i] == 1 && visited[i] == 0)
            {
                push(i);
            }
        }
    }
}
// Recursive DFS function
void recdfs(int v,int siz)
{
    if(visited[v] == 0)
    {
        printf("%d ",v);
        visited[v] = 1;
        for(int i = 1;i<=siz;i++)
        {
            if(a[v][i] == 1 && visited[i] == 0)
            {
                recdfs(i,siz);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices ");
    scanf("%d",&n);
    for(int i =  1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int v;
    printf("Enter the starting vertex ");
    scanf("%d",&v);
    // BFS
    // bfs(v,n);
    // recdfs(v,n);
    dfs(v,n);

    return 0;
}
/*
BFS
6
0 1 1 0 0 0 
1 0 0 1 0 0
1 0 0 1 0 0
0 1 1 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0
4
bfs = 4 2 3 5 6 1
recdfs = 
dfs = 4 2 1 3 5 6
// mine
4
0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 0
1
bfs = 1 2 4 3
recdfs = 1 2 3 4
*/