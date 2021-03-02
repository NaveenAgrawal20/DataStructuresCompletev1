#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 99999

int main()
{ // cost adjacency matrix
    int cost[MAX][MAX];
    int n, i, j;
    printf("Enter number of vertices ");
    scanf("%d", &n);
    printf("Enter cost adjacenecy matrix ");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    /* Prims Implementation*/
    int near[n + 1]; // 0 not included
    // spanning tree
    int T[2][n - 1]; // vertex - 1

    int min = INF, u, v;
    // upper array
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    // set near
    near[u] = 0;
    near[v] = 0;
    for (i = 1; i <= n; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    int k;
    for (i = 1; i < n-1; i++)       // one already we got so and n-1 edges
    {
        min = INF;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                k = j;
                min = cost[j][near[j]];
            }
        }
        T[0][i] = k;
        T[1][i] = near[k];
        near[k] = 0;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }
    for (i = 0; i < n - 1; i++)
        printf("(%d,%d)\n", T[0][i], T[1][i]);
    return 0;
}
/*
Test Case
7
0 25 0 0 0 5 0
25 0 12 0 0 0 10
0 12 0 8 0 0 0
0 0 8 0 16 0 14
0 0 0 16 0 20 18
5 0 0 0 20 0 0
0 10 0 14 18 0 0
(1,6)
(5,6)
(4,5)
(3,4)
(2,3)
(7,2)
*/