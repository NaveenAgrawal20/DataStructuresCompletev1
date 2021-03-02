#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void deletion(int *a,int *p,int item,int pos);
void display(int *a,int size);
void del_alle(int *a,int *n,int item);

// 12 42 10 34 43 50 14 
// 12 42 10 34 43 50 14 12 10 23
// 10 80 10 10 20 30 10 40 50 10
int main()
{
    int n,pos,item,i;
    printf("Enter size of array ");
    scanf("%d",&n);
    int *a = (int*)malloc(n*sizeof(int));
    // input 
    for(i=0;i<n;i++)
    {
        printf("Enter %d element ",i+1);
        scanf("%d",&a[i]);
    }
    display(a,n);
//    printf("\nEnter item to insert and its pos ");
//    scanf("%d %d",&item,&pos);
//    //deletion
//    if(pos<1 || pos >n)
//    {
//    	printf("Invalid Position ");
//    	exit(1);
//	}
//    deletion(a,&n,item,pos);

	printf("Enter item to be deleted ");
	scanf("%d",&item);
    del_alle(a,&n,item);
    display(a,n);
    //
    return 0;
}
void del_alle(int *a,int *n,int item)
{
	int k=0;
	for(int i=0;i<*n;i++)
	{
		if(a[i] == item)
			continue;
		else
		{
			a[k] = a[i];
			k++;
		}
    }
    *n = k;
}
void deletion(int *a,int *p,int item,int pos)
{
	pos--;
	for(int i = pos;i<*p-1;i++)
    	a[i] = a[i+1];
    (*p)--;
}
void display(int *a,int n)
{
	for(int i=0;i<n;i++)
    {
		printf("%d\t",a[i]);
    }
    printf("\n");
}

