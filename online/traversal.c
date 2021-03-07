#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct node{
    int data;
    struct node *prev;
} node;
node *top = NULL;

void push(int k)
{
    node *newnode = (node*)malloc(sizeof(struct node));
    newnode->data = k;
    newnode->prev = top;
    top = newnode;
}
int isEmpty()
{
    return (top == NULL);
}
int pop(){
    int x;
    if(isEmpty()){
        printf("UNDER");
        return x;
    }
    x = top->data;
    node *temp = top;
    top = top->prev;
    free(temp);
    return x;
}
//////////////////////////////

int visited[MAX];
int a[MAX][MAX];

void dfs(int v,int n)
{
    push(v);
    while(!isEmpty())
    {
        v = pop();
        if(visited[v] == 0)
        {
            printf("%d ",v);
            visited[v] = 1;
        }
        for(int i = n-1;i>=0;i--)
            if(visited[i] == 0 && a[v][i] != 0)
                push(i);
    }
}
void recDfs(int v,int n)
{
    if(visited[v] == 0)
    {
        printf("%d ",v);
        visited[v] = 1;
        for(int i = 0;i<n;i++)
            if(visited[i] == 0 && a[v][i] != 0)
                recDfs(i,n);
    }
}
int main()
{
    int n;
    printf("Enter n vertices ");
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            scanf("%d",&a[i][j]);
    
    int v = 0;
    // pritf("Enter starting vertic ");
    // scanf("%d",&v);
    // dfs(0,n);
    recDfs(0,n);
    return 0;
}
/*
8
0 1 1 1 1 0 0 0
1 0 0 0 0 1 0 0
1 0 0 0 0 1 0 0
1 0 0 0 0 0 1 0
1 0 0 0 0 0 1 0
0 1 1 0 0 0 0 1
0 0 0 1 1 0 0 1
0 0 0 0 0 1 1 0
// dfs = 0 1 5 2 7 6 3 4
*/