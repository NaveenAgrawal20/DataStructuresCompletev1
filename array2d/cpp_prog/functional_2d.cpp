#include <iostream>
using namespace std;

int main()
{
    int **a,**b,**c,r1, c1, r2, c2, i, j, k;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // intializing 1st matrix
	a = new int *[r1];
    for(int i=0;i<r1;i++)
        a[i] = new int[c1];
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
	// intializing 2nd matrix
	b = new int *[r2];
    for(int i=0;i<r2;i++)
        b[i] = new int[c2];
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }



    // MULTIPLICATION
	if(c1 != r2) // r1*c1 r2*c2 // c1 and r2 is different
    {
        cout<< "Both Matrix must have same dimension ";
        exit(1);
    }
    // Initializing elements of matrix mult to 0.
  	c = new int *[r1];
   	for(int i=0;i<r1;i++)
        c[i] = new int[c2];
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
        	c[i][j] = 0;
        	for(int k=0;k<c1;k++)
            	c[i][j] += a[i][k]*b[k][j];
        }

    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << c[i][j];
        if(j == c2-1)
            cout << endl;
    }
	for(int i=0;i<r1;i++)
        delete[] c[i];
    delete[] c;
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << c[i][j];
        if(j == c2-1)
            cout << endl;
    }
    return 0;
}
/*
2
3
3
2
8
1
2
-5
6
7
-5
1
0
2
-11
7
*/

/*
ans
-62     24
-52     56
*/
