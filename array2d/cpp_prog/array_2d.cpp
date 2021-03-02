#include<iostream>
#include<process.h>
using namespace std;
/*
Write a c++ program for matrix multiplication with following specifications 
(a.) Use dynamic memory allocation (new and delete) for matrix 
(b.) Use getdata() function to input values for matrix 
(c.) Use show() to display the matrix 
(d.) Use mul() to multiply two matrices
*/
// Matrix
class Matrix{
    private:
        int i,j,k,r,c;
        int **mat;
    public:
        Matrix():r(0),c(0){mat=NULL;};
        Matrix(int row,int col);
        
       ~Matrix()
       	{
		    for(i=0;i<r;i++)
		    {
		        delete mat[i];
			}
			delete mat; 
		}
		
        void getdata();
        void show();
        Matrix sum(Matrix);
        Matrix mul(Matrix);
       	void info()
        {
            cout<<r<<" "<<c;
        }
};

Matrix::Matrix(int row,int col)
{
    this->r = row;
    this->c = col;
    
    // dynamic
    mat = new int*[r];
    for(i=0;i<r;i++)
        mat[i] = new int[c];
}

void Matrix::getdata()
{
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            cout<<"Enter data for "<<i+1<<","<<j+1<<" : ";
            cin>>mat[i][j];
        }
}

void Matrix::show()
{
	cout<<endl;
    for(i=0;i<r;i++)
	{
        for(j=0;j<c;j++)
            cout<<mat[i][j]<<"\t";
		cout<<endl;	
	}
}


// Operations 
Matrix Matrix::sum(Matrix m)
{
    if(r!=m.r || c!= m.c)
    {
        cout<<"cant add ";
        exit(1);
    }
    
    Matrix t(r,c);
    for(int i=0;i<r;i++)
	{
        for(int j=0;j<c;j++)
        {
            t.mat[i][j] = mat[i][j]+m.mat[i][j];
		}	
	}
    return t;
}

Matrix Matrix::mul(Matrix m2)
{
    if(m2.r != c) // r1*c1 r2*c2 // c1 and r2 is different
    {
        cout<< "Both Matrix must have same dimension ";
        exit(1);
    }
    
    Matrix mulres(r,m2.c);
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<m2.c;j++)
        {
            mulres.mat[i][j] = 0;
            for(k=0;k<c;k++)
            {
                mulres.mat[i][j] += mat[i][k] * m2.mat[k][j];
        	}
		}
    }

    return mulres;
}
int main()
{
    Matrix a(2,2),b(2,3),c;
    a.getdata();
    a.show();
    b.getdata();
    b.show();
    
    c = a.mul(b);
    c.show();
    
    return 0;
}
/*
2
1
3
4
1
0
1
1
2
2
*/
