#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
using namespace std;
int determinant(int *arr,int order);
int main(){
 int *ar1,i,j,pos,n,d;

    printf("enter n for n x n matrix ");
    scanf("%d",&n);
    ar1=(int*)calloc(n*n,sizeof(int));
    for(i=0;i<n;i++)
     {
	     for(j=0;j<n;j++)
	     {
	      	pos = i*n+j;
	      	printf("Enter a[%d][%d] ",j,i);
			scanf("%d",&ar1[pos]);  
	     }
     }
     //!Array is saved as => a[0]=9 a[1]=8 a[2]=7 a[3]=6 a[4]=5 a[5]=4 a[6]=3 a[7]=2 a[8] =1
     //printing array
    for(i=0;i<n;i++)
    {
        for(j=i;j<n*n;j+=n) //icrement of n and limit of n*n and initial j=i;
        {
            printf("%d ",ar1[j]);
        }
        printf("\n");
        /*output=
        9 6 3
        8 5 2
        7 4 1*/
    }
    d=determinant(ar1,n);
    free(ar1);
    printf("\n%d is the determinant",d);
}
int determinant(int *arr,int order)
{
	int *ar2,i,j,k,l,det = 0;
	int newsize,newpos,pos;
	if(order==1)
		return arr[0];
	newsize = (order-1)*(order-1);
	ar2 = (int*)calloc(newsize,sizeof(int));
	for(i=0;i<order;i++)
	{
		for(j=1;j<order;j++)
		{
			l = 0;
			for(k=0;k<order;k++)
			{
				if(k==i)
					continue;
				pos = j*order+k;
				newpos = (j-1)*(order-1)+l;
				ar2[newpos] = arr[pos];
				l++;
			}
		}
		det = det+arr[i]*pow(-1,i)*determinant(ar2,order-1);
	}
	return det;
    
//    return det;
}
