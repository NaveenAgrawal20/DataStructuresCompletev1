#include<stdio.h>
#include<conio.h>
#define MAX 20
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
// logic 1
void sele1(int *a,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(&a[i],&a[j]);
            }
        }
    }
}
// logic 2
void sele2(int *a,int n)
{
	int min,i,j;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(a[min] > a[j])
			{
				min = j;	
			}	
		}
		if(min != i)
		{
			swap(&a[min],&a[i]);
		}
	}
}
int main()
{
    
    int a[MAX],n,i,j;
    printf("Enter array size ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter array element %d ",i+1);
        scanf("%d",&a[i]);
    }
    //	logic 1
//    sele1(a,n);
//    display(a,n);
    
	//logic 2
	sele2(a,n);
    display(a,n);
    return 0;
}
