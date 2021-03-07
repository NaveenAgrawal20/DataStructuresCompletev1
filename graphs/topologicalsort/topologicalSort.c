#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct queue
{
    int data[MAX];
    int front, rear;
} queue;

void add(struct queue *q, int k)
{
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
        q->rear++;
    q->data[q->rear] = k;
}
int delq(struct queue *q)
{
    if (q->front == -1)
        return -9999;
    int x = q->data[q->front];
    if (q->front == q->rear) // only 1 ele
        q->front = q->rear = -1;
    else
        q->front++;
    return x;
}

int main()
{
    struct queue q;
    q.front = q.rear = -1;
    int a[10][10], indegree[10], flag[10]; // flag, to dont insert again in queue
    int n, i, j, k;

    printf("Enter num of vertices ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
    { // init indgegree with 0
        indegree[i] = 0;
        flag[i] = 0;
    }
    // calculate indegree
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[j][i] == 1)
                indegree[i] = indegree[i] + a[j][i];
    // for (k = 0; k < n; k++)
    // {
    //     if (indegree[k] == 0)
    //     {
    //         add(&q, k);
    //     }
    // }
    do
    {
        for (k = 0; k < n; k++)
        {
            if (indegree[k] == 0 && flag[k] == 0)
            {
                add(&q, k);
                flag[k] = 1;
            }
        }
        k = delq(&q);
        printf("%d ", k);
        for (i = 0; i < n; i++)
        {
            if (a[k][i] == 1)
            {
                // a[k][i] = 0;
                indegree[i]--;
                // if (indegree[i])
                //     add(&q, i);
            }
        }
    } while (q.front != -1);
    return 0;
}
/*
6
0 0 0 0 1 0
0 0 0 1 1 0
0 0 0 1 0 1
0 1 1 0 0 0
1 1 0 0 0 0
1 0 1 0 0 0

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 1 0 0 0 0
1 1 0 0 0 0
1 0 1 0 0 0
*/