#include"iostream.h"
#include"conio.h"

class matrix
{
	int **a;
	int r,c;
	public:
		matrix(){r=c=0; a = NULL;}
		matrix(int r, int c);
		void getData();
		void display();
		friend matrix operator*(matrix ,matrix );
};
matrix::matrix(int r,int c)
{
	this->r = r;this->c =c;
	a = new int*[r];
	for(int i=0;i<r;i++)
		a[i] = new int[c];
}
void matrix::getData()
{
	for(int i = 0;i<r;i++)
		for(int j = 0;j<r;j++)
			cin>>a[i][j];
}
void matrix::display()
{
	for(int i = 0;i<r;i++)
		{
			for(int j = 0;j<c;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
}
matrix operator*(matrix m1,matrix m2)
{                       matrix t(m1.r,m2.c);
			if(m1.c != m2.r)
				return t;

			for(int i = 0;i<m1.r;i++)
			{
				for(int j = 0;j<m2.c;j++)
				{
					t.a[i][j] = 0;
					for(int k = 0;k<m2.r;k++)
					{
						t.a[i][j] += m1.a[i][k]*m2.a[k][j];
					}
				}
			}
				return t;
}
int main()
{
	clrscr();
	matrix m1(2,2), m2(2,2), m3;
	m1.getData();
	m1.display();
	m2.getData();
	m2.display();
	m3 = m1*m2;
	m3.display();
	getch();
	return 0;
}