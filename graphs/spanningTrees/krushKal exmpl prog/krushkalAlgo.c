#include<stdio.h>
#include<stdlib.h>
#define INF 99999
#define MAX 15
    // an edge[no of edges][3 components represents (origin , destination, weight)]
int edge[16][3] = {{0, 1, 9}, {0, 3, 4}, {0, 4, 2}, {1, 2, 10},
                {1, 4, 8}, {2, 4, 7}, {2, 5, 5}, {3, 4, 3}, 
                {3, 6, 18}, {4, 5, 6}, {4, 6, 11}, {4, 7, 12},
                {4, 8, 15}, {5, 8, 16}, {6, 7, 14}, {7, 8, 20}};
int included[16];   // no of edges which are included in solution 
// SET
int set[9];     // int set[no of vertices].

void initSet(){
    for(int i = 0;i<9;i++)
        set[i] = -1;
}
// union
void join(int u,int v)
{
    if(set[u] < set[v])
    {
        set[u] = set[u]+set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}
// u = vertix for which to find parent
int find(int u)
{
    int v, x = u;
    while(set[x] > 0)
        x =  set[x];
    while(u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

// DRIVER PROGRAM
int main()
{
    initSet();
    int n = 9, i, j; // n = no of vertices
    // Krushkal
    int t[2][n-1];
    int min,u,v,k;
    i = 0;
    while(i<n-1) // loop for t[][]
    {
        min = INF;
        for(j = 0;j<16;j++)
        {
            if(included[j] == 0 && edge[j][2] < min)
            {
                min = edge[j][2];
                u = edge[j][0];
                v = edge[j][1];
                k = j;
            }
        }
        if(find(u) != find(v)) // not subset of same set
        {
            included[k] = 1;
            join(find(u),find(v)); // union of head of subset
            t[0][i] = u;
            t[1][i] = v;
            i++;
        }
        else
        {
            included[k] = 1;
        }
    }
    for (i = 0; i < n - 1; i++)
        printf("(%d,%d)\n", t[0][i], t[1][i]);
    return 0;
}
/*
7
0 25 0 0 0 5 0
25 0 12 0 0 0 10
0 12 0 8 0 0 0
0 0 8 0 16 0 14
0 0 0 16 0 20 18
5 0 0 0 20 0 0
0 10 0 14 18 0 0

9    
0 9 0 4 2 0 0 0 0
9 0 10 0 8 0 0 0 0
0 10 0 0 7 5 0 0 0
4 0 0 0 3 0 18 0 0
2 8 7 3 0 6 11 12 15
0 0 5 6 6 0 0 0 16
0 0 0 18 11 0 0 14 0
0 0 0 0 12 0 14 0 20
0 0 0 0 15 16 0 20 0    
*/