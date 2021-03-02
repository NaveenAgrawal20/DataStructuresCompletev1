#include<stdio.h>
#define MAX 20

int max(int a[],int size) // largest number in array
{
    int i,max;
    max = a[0];
    for(i=1;i<size;i++)
    {
        if(max<a[i])
            max = a[i];
    }
    return max;
}
int count(int max)  // find no of digits in largest number in array
{
    int cnt = 0;
    while(max!=0)
    {
        max  = max/10;
        cnt++;
    }
    return cnt;
}
int digit(int number,int k) // to find Kth digit of a number
{
    int kdig;
    for(int i=1;i<=k;i++)
    {
        kdig = number%10;
        number = number/10;
    }
    return kdig;
}

void radix_sort(int a[],int n)
{
    int i,j,m,d,k,r,c,mat[10][n],l;
    m = max(a,n);
    d = count(m);
    for(k=1;k<=d;k++)
    {
        // initialize 2d matrix with -1 value
        for(i=0;i<10;i++)
            for(j=0;j<n;j++)
                mat[i][j] = -1;

        // copy a array element in matrix according to kth digit
        for(i=0;i<n;i++)
        {
            r = digit(a[i],k);
            c = 0;
            while(mat[r][c] !=-1)
                c++;
            mat[r][c] = a[i];
        }
        // copying matrix into array except -1
        l=0;
        for(i=0;i<10;i++)
        {
            for(j=0;j<n;j++)
            {
                if(mat[i][j]!=-1)
                    a[l++] = mat[i][j];
            }
        }
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
    int a[MAX],n,i,j;
    printf("Enter array size ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter array element %d ",i+1);
        scanf("%d",&a[i]);
    }
    radix_sort(a,n);
    display(a,n);
    return 0;
}
