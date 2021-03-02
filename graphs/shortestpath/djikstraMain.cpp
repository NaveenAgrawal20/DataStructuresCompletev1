#include <iostream>
using namespace std;
#define MAX 10
#define INF 9999
#define NIL -1
#define PERM 1
#define TEMP 0

int pred[MAX];
int a[MAX][MAX];
int pathLen[MAX];
int status[MAX];

void displayMatrix(int a[][MAX], int n)
{
	cout << "MATRIX IS \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
// utilty function to display table
void displayTable(int num)
{
	cout << "Vertex PathLength Predessor status\n";
	for (int i = 0; i < num; i++)
	{
		cout << i << "\t\t" << pathLen[i] << "\t\t";
		if (pred[i] == NIL)
			printf("NIL\t\t");
		else
			printf("%d\t\t", pred[i]);
		if (status[i] == 0)
			printf("Temp\n");
		else
			printf("Perm\n");
	}
	cout<<"\n\n";
}
/*	Returns the temporary vertex with minimum value of pathLength.
*	Returns NIL if no temporary vertex left or all temporary vertices
*	left have pathLength infinity
*/
int minimumVertex(int pathlenArr[], int numVertex)
{
	int k = NIL;
	int min = INT32_MAX;
	for (int i = 0; i < numVertex; ++i)
	{
		if (status[i] == TEMP && pathLen[i] < min)
		{
			min = pathLen[i];
			k = i;
		}
	}
	return k;
}

void djikstra(int adj[][MAX], int v, int src)
{
	int i, j;
	
	for (i = 0; i < v; i++)
	{
		pred[i] = NIL;
		pathLen[i] = INF;
		//status[i] = TEMP; // no need if global
	}
	pathLen[src] = 0; // source path must be 0.

	int selectedVertex;
	i = 0;
	while (i < v)	//1 for src itdelf,and last one is only left
	{
		selectedVertex = minimumVertex(pathLen, v);
		status[selectedVertex] = PERM;// mark the vertex as status //PERM = 1

		for (j = 0; j < v; j++)
		{
			if (adj[selectedVertex][j] != 0 && status[j] == TEMP)
			{
				if (pathLen[selectedVertex] + adj[selectedVertex][j] < pathLen[j])
				{
					pathLen[j] = pathLen[selectedVertex] + adj[selectedVertex][j];
					pred[j] = selectedVertex;
				}
			}
		}
		i++; // move i.
	}
}
void getPath(int s,int v)
{
	while (v != s ) {
		cout << pred[v] << "-->";
		v = pred[v];
	}
}

int main()
{
	int src, n;
	cout << "Enter number of vertices ";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	cout << "Enter source vertex ";
	cin >> src;
	djikstra(a, n, src);
	displayTable(n);
	int v;
	while (1)
	{
		printf("Enter destination vertex(-1 to quit): ");
		cin>>v;
		if (v == -1)
			break;
		if (v < 0 || v >= n)
			printf("This vertex does not exist\n");
		else if (v == src)
			printf("Source and destination vertices are same\n");
		else if (pathLen[v] == INF)
			printf("There is no path from source to destination vertex\n");
		else
			getPath(src, v);
	}
	return 0;
}
/*
9
0 4 0 0 8 0 0 0 0
4 0 8 0 11 0 0 0 0
0 8 0 7 0 0 4 0 8
0 0 7 0 0 14 0 9 0
8 11 0 0 0 1 0 0 7
0 0 0 0 1 0 2 0 6
0 0 4 14 0 2 0 10 0
0 0 0 9 0 0 10 0 0
0 0 8 0 7 6 0 0 0
0

2nd 
8
0 8 2 7 0 0 0 0
0 0 0 0 0 16 0 0
5 0 0 4 0 0 3 0
0 0 0 0 9 0 0 0
4 0 0 0 0 5 0 8
0 0 0 0 0 0 0 0
0 0 6 3 4 0 0 0
0 0 0 0 0 2 5 0
0
*/