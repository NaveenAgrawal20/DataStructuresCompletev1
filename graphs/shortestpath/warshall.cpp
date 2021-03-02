#include <iostream>
using namespace std;
#define MAX 10
#define INF 9999

int a[MAX][MAX], q[MAX][MAX];
int n;
void display(int a[][MAX],int n)
{
	cout << "MATRIX IS \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j]<<" ";
		cout << "\n";
	}
}

int main()
{
	cout << "Enter number of vertices ";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0 && i != j)
				q[i][j] = INF;
			else
				q[i][j] = a[i][j];
		}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i != j && j != k && i != k && q[i][j] > q[i][k] + q[k][j])
					q[i][j] = q[i][k] + q[k][j];
			}
	display(q,n);
}