#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 15

void readsparse(int mat[][3])
{
    int r,c,i,n;
    cout<<"Enter no of rows and columns and non 0 elements";
    cin>>r>>c>>n;
    mat[0][0] = r;
    mat[0][1] = c;
    mat[0][2] = n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter the next triplets ";
        cin>>mat[i][0]>>mat[i][1]>>mat[i][2];
    }
}
void sum_sparse(int sm1[][3],int sm2[][3],int sm3[][3])
{
    int i,j,k,n1,n2;
    if(sm1[0][0]!=sm2[0][0] || sm1[0][1]!=sm2[0][1]){
        cout<<"Cannot add ";
        exit(1);
    }
    sm3[0][0] = sm1[0][0];
    sm3[0][1] = sm1[0][1];

    k = 1;
    n1 = sm1[0][2];
    n2 = sm2[0][2];
    for(i=1,j=1;i<=n1 && j<=n2;k++)
    {
        if(sm1[i][0] < sm2[j][0] || sm1[i][0] == sm2[j][0] && sm1[i][1] < sm2[j][1])
        {
            sm3[k][0] = sm1[i][0];
            sm3[k][1] = sm1[i][1];
            sm3[k][2] = sm1[i][2];
            i++;
        }
        else if(sm1[i][0] > sm2[j][0] || sm1[i][0] == sm2[j][0] && sm1[i][1] > sm2[j][1])
        {
            sm3[k][0] = sm2[j][0];
            sm3[k][1] = sm2[j][1];
            sm3[k][2] = sm2[j][2];
            j++;
        }
        else
        {
            sm3[k][0] = sm2[j][0];
            sm3[k][1] = sm2[j][1];
            sm3[k][2] = sm1[i][2]+sm2[j][2];
            i++;
            j++;
        }
    }
    // copy remaining matrix
    while(i<=n1)
    {
        sm3[k][0] = sm1[i][0];
        sm3[k][1] = sm1[i][1];
        sm3[k][2] = sm1[i][2];
        k++;
        i++;
    }
    while(j<=n1)
    {
        sm3[k][0] = sm1[j][0];
        sm3[k][1] = sm1[j][1];
        sm3[k][2] = sm1[j][2];
        k++;
        j++;
    }
    sm3[0][2] = k-1;
}
void printsparse(int a[][3])
{
    cout<<"\n\t --- Sparse----\n";
    printf("%d\t%d\t%d\n",a[0][0],a[0][1],a[0][2]);
    int n = a[0][2];
    for(int i=1;i<=n;i++)
        printf("%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2]);
}
void transpose(int sm1[][3],int sm2[][3])
{
    int i,j,col,n;
    sm2[0][0] = sm1[0][1];
    sm2[0][1] = sm1[0][0];
    sm2[0][2] = sm1[0][2];

    j = 1;
    n = sm1[0][2];
    if(n>0)
    {
        for(col=0;col<sm1[0][1];col++)
            for(i=1;i<=n;i++)
                if(col==sm1[i][1])
                {
                    sm2[j][0] = sm1[i][1];
                    sm2[j][1] = sm1[i][0];
                    sm2[j][2] = sm1[i][2];
                    j++;
                }
    }

}
int main()
{
    int m1[MAX][3],m2[MAX][3],m3[MAX][3],m4[MAX][3],m5[MAX][3];
    readsparse(m1);
    printsparse(m1);
    readsparse(m2);
    printsparse(m2);
    sum_sparse(m1,m2,m3);
    printsparse(m3);

    printf("Transpose  = \n");
    readsparse(m4);
    transpose(m4,m5);
    printsparse(m5);
    return 0;
}
/*
5 6 4
1 3 7
1 5 8
3 2 1
4 3 2

5 6 5
1 2 7
1 3 3
3 2 1
3 3 2
4 1 9
*/
