#include<iostream>

using namespace std;
class matrix
{
    int **mat; // 
    int r,c;
    public:
    	// declaring member function and constructor and destructor
        matrix();
        matrix(int,int);
        
        void getdata();
        void display();
        matrix sum(matrix);
        matrix mul(matrix);
        ~matrix(); //destructor
};
matrix::matrix()
{
    r=c=0;
    mat=NULL;
}
matrix::matrix(int r,int c)
{
    this->r = r;
    this->c = c;
    mat = new int *[r];
    for(int i=0;i<r;i++)
        mat[i] = new int[c];
}

matrix::~matrix()
{
    for(int i=0;i<r;i++)
        delete[] mat[i];
    delete[] mat; 
}

void matrix::getdata()
{
    cout<<"Enter row and col for matrix 1 ";
	cin>>r>>c;
    mat = new int *[r];
    for(int i=0;i<r;i++)
        mat[i] = new int[c];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            cout<<"Enter data for "<<i+1<<","<<j+1<<" : ";
            cin>>mat[i][j];
        }
}

void matrix::display()
{
	cout<<endl;
    for(int i=0;i<r;i++)
	{
        for(int j=0;j<c;j++)
            cout<<mat[i][j]<<"\t";
		cout<<endl;	
	}
}

matrix matrix::mul(matrix m2)
{
    if(m2.r != c) // r1*c1 r2*c2 // c1 and r2 is different
    {
        cout<< "Both Matrix must have same dimension ";
        exit(1);
    }
    
    matrix t(r,m2.c);
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<m2.c;j++)
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
int main()
{
    matrix a,b,d;
    a.getdata();
    a.display();

    b.getdata();
    b.display();
    
    d = a.mul(b);
    d.display();
    return 0;
}
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
