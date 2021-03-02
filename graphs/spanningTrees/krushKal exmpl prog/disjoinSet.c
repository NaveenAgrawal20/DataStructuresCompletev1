#include<stdio.h>
#include<stdlib.h>

/* u, v head of a set
let {u} be head of Set A
and let {v} be head of Set B.
*/
int set[11] = {-1,-1,-1,-3,-4,3,-1,4,4,3,4};
void display()
{
    for(int i = 1;i<11;i++)
        printf("%d\t",set[i]);
    printf("\n");        
}
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

int main()
{
    display();
    join(3,4);
    display();
    printf("\n%d ",find(9));
    return 0;
}