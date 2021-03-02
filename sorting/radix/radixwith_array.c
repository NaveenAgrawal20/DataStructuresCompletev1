#include<stdio.h>
#include<math.h>
#define MAX 20

int max(int *a,int size)
{
    int i,max = a[0];
    for(i=1;i<size;i++)
    {
        if(max<a[i])
            max = a[i];
    }
    return max;
}
int count(int num)
{
    return floor(log10(num))+1;
}
int digit(int num,int k)
{
    int d;
    for(int i=1;i<=k;i++)
    {
        d = num % 10;
        num = num/10;
    }
    return d;
}
void radix_sort(int a[],int n)
{
    int i,j,k,d,m,mat[10][n],r,c;
    m = max(a,n);
    d = count(m);
    for(k=1;k<=d;k++)
    {
        // initialize 2d matrix with -1 value
        for(i=0;i<10;i++)
            for(j=0;j<n;j++)
                mat[i][j] = -1;
        for(i=0;i<n;i++)
        {            
            r = digit(a[i],k);
            c = 0;
            while(mat[r][c]!=-1)
            {
                c++;
            } 
            mat[r][c] = a[i];
        }

        int l = 0;
        for(i=0;i<10;i++)
            for(j=0;j<n;j++)
                if(mat[i][j]!=-1)
                    a[l++] = mat[i][j];
    }
}
// simple display function
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
int main()
{   

    int a[MAX],n;
    printf("Enter array size ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter array element %d ",i+1);
        scanf("%d",&a[i]);
    }
    display(a,n);
    printf("\nAfter sort\n");
    radix_sort(a,n);
    display(a,n);
    return 0;
}