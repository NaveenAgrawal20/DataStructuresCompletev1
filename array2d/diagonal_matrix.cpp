#include<iostream>
#define MAX 10
using namespace std;
/*
1 0 0 
0 3 0  // diagonal matrix
0 0 2 
*/
void display(int a[][MAX],int r,int c){
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
int check_diagonal(int a[][MAX],int r,int c)
{
	int i,j;
	if(r!=c)
		return 0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i!=j && a[i][j]!=0)
				return 0;
		}
	}
	return 1;
}

int main()
{
    int r,c,i,j;
    cout<<"Enter array row and col ";
    cin>>r>>c;

    int a[r][MAX];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter a[%d][%d] ",i+1,j+1);
            cin>>a[i][j];
        }
    }
    display(a,r,c);
    int ans = check_diagonal(a,r,c);
    if(ans==1)
    	cout<<"Diagonal matrix ";
    else
    	cout<<"Not diagonal ";
    return 0;
}
