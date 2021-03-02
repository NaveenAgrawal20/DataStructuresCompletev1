#include<iostream>
#define MAX 20
using namespace std;

void readsparse(int mat[][3])
{
    int r,c,i,n;
    cout<<"Enter size of matrix row,col ";
    cin>>r>>c;
    mat[0][0] = r;
    mat[0][1] = c;
    cout<<"\nEnter non 0 elements ";
    cin>>n;
    mat[0][2] = n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter next triplet (row,col,value) ";
        cin>>mat[i][0]>>mat[i][1]>>mat[i][2];
    }
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

void displaysparse(int a[][3])
{
    int n = a[0][2];
    for(int i=0;i<=n;i++)
        printf("%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2]);
}

int main()
{
    int m1[MAX][3],m2[MAX][3];
    readsparse(m1);
    displaysparse(m1);
    transpose(m1,m2);
    cout<<"\n\t\tTranspose\n";
    displaysparse(m2);
    return 0;
}
/*
5 6
4
1 2 7
1 4 8
3 2 1
4 3 4
*/
