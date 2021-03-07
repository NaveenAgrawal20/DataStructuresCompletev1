#include<stdio.h>
#include<stdlib.h>
//////

typedef struct node{
    struct node* next;
    int data;
}node;

node *adj[20]; // array of pointers // 
int visited[20];
int n;

void insert(int u, int v)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = v;
    newnode->next = NULL;
    
    if(adj[u] == NULL) // empty uth ll.
        adj[u] = newnode;

    else
    {
        node *p = adj[u];
        while(p->next != NULL)
            p = p->next;
        p->next = newnode;
    }
}
void read_Graph()
{
    int i;
    printf("Enter num of vertices ");
    scanf("%d",&n);
    for(i = 0;i<n;i++)
        adj[i] = NULL; // init array of pointers
   
    int e,u,v;
    printf("Enter num of eddges ");
    scanf("%d",&e);
    for(i = 0;i<e;i++)
    {
        printf("Enter an edge(u,v) ");
        scanf("%d%d",&u,&v);
        insert(u,v);
    }
}

void dfs(int v)
{
    printf("%d ",v);
    visited[v] = 1;
    node *p = adj[v];

    int i;
    while(p != NULL)
    {
        i = p->data;
        if(visited[i] == 0)
            dfs(i);
        p = p->next;
    }
}
int main()
{
    read_Graph();
    dfs(0);
    return 0;
}
/*
8
10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7
// output 0 1 5 7 2 3 6 4
*/