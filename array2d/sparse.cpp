#include<iostream>
#define MAX 20
using namespace std;

void display(int **a,int row,int col)
{
	cout<<"Displaying "<<col<<" non 0 elements "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cout<<a[i][j]<<" ";
    	cout<<endl;
	}
	cout<<endl;
}

int main()
{
    int i,j,r,c,count=0;
	cout<<"Enter row and col ";
	cin>>r>>c;

	int spm[r][c];
	for(i=0;i<r;i++)
		for(j = 0;j<c;j++)
		{
			cout<<"Enter "<<i+1<<" "<<j+1<<" "<<" element ";
			cin>>spm[i][j];
			spm[i][j]!=0?count++:count;
		}
//	display(spm,r,c); //error
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<spm[i][j]<<" ";
		cout<<endl;
	}
	int **result,k=0;
    result = new int*[3];
    for(i = 0;i<3;i++)
        result[i] = new int[count];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(spm[i][j]!=0)
            {
                result[0][k] = i;
                result[1][k] = j;
                result[2][k] = spm[i][j];
                k++;
            }
    display(result,3,count);
    return 0;
}
/*
5 6
0
0
0
0
9
0
0
8
0
0
0
0
4
0
0
2
0
0
0
0
0
0
0
5
0
0
2
0
0
0
*/
