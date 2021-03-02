#include<iostream>

using namespace std;
/*
Write a c++ program for matrix multiplication with following specifications 
(a.) Use dynamic memory allocation (new and delete) for matrix 
(b.) Use getdata() function to input values for matrix 
(c.) Use show() to display the matrix 
(d.) Use mul() to multiply two matrices
*/
class matrix
{
    int **mat; // 
    int r,c,i,j;
    public:
    	// declaring member function and constructor 
        matrix();
        matrix(int,int);
        
        void getdata();         // member function to initialize the matrix and store value in array
        void show();            // member function to display the matrix 
        matrix sum(matrix);     
        matrix mul(matrix);     // member function to multiply two matrix and store their result in a new matrix
        void del();             // member function to free the memory allocated by new
};
matrix::matrix()            // initializing row and col = 0
{
    r=c=0;
    mat=NULL;
}

matrix::matrix(int r,int c) 
{
    this->r = r;
    this->c = c;
    mat = new int *[r];
    for(i=0;i<r;i++)
        mat[i] = new int[c];
}

void matrix::del()          
{
    for(i=0;i<r;i++)
        delete[] mat[i];
    delete[] mat; 
}

void matrix::getdata()
{
    // cout<<"Enter row and col for matrix 1 ";
	// cin>>r>>c;
    // mat = new int *[r];
    // for(int i=0;i<r;i++)
    //     mat[i] = new int[c];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            cout<<"Enter data for "<<i+1<<","<<j+1<<" : ";
            cin>>mat[i][j];
        }
}

void matrix::show()
{
	cout<<endl;
    for(i=0;i<r;i++)
	{
        for(j=0;j<c;j++)
            cout<<mat[i][j]<<"\t";
		cout<<endl;	
	}
}

matrix matrix::mul(matrix m2)
{
    if(m2.r != c)           // r1*c1 r2*c2       // c1 and r2 is different
    {
        cout<< "Both Matrix must have same dimension ";
        exit(1);
    }
    // as c1 and r2 are same we multiply the two matrices
    matrix t(r,m2.c);
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<m2.c;j++)
        {
            t.mat[i][j] = 0;
            for(int k=0;k<c;k++)
            {
                t.mat[i][j] += mat[i][k] * m2.mat[k][j];
        	}
		}
    }
    return (t);
}

// Driver function 
int main()
{
    int r,c;

    cout<<"Enter row and column for 1st matrix ";
    cin>>r>>c;
    matrix a(r,c); // creating three objects of matrix class
    a.getdata();
    a.show();

    cout<<"Enter row and column for 2nd matrix ";
    cin>>r>>c;
    matrix b(r,c),d;
    b.getdata();
    b.show();
    
    d = a.mul(b);   // storing the multiplication result in d
    d.show();
    d.del();        // calling del member function to to free the memory allocated by new
    // checking 
    d.show();       
    return 0;
}
// Test Case
/*
2
3
8 
1 
2
-5
6
7
3
2
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