#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int lin_search(int *,int,int);
int binary_search(int arr[],int size,int item);

int binary_searchR(int arr[],int size,int item,int low)
{
	int high = size-1;
	int mid = (low+high)/2;
	if(low > high)
	{
		return -1;
	}
	if(item==arr[mid])
		return mid;
	if(item > arr[mid]) 
		binary_searchR(arr,size,item,low+1);
	else
		binary_searchR(arr,size-1,item,low);
}
int main()
{
    int n,*a,i,j,item;
    printf("Enter size of array ");
    scanf("%d",&n);
    a = (int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter elemment %d ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nEnter item to be searched ");
    scanf("%d",&item);
//    int s = lin_search(a,n,item);
//    if(s==-1)
//        printf("Not found ");
//    else
//        printf("Item found at %d ",s+1);

//  using Binary
	int b = binary_searchR(a,n,item,0);
	if(b==-1)
        printf("Not found ");
    else
        printf("Item found at %d ",b+1);
        
    free(a);
    a = NULL;
    getch();
    return 0;
}
int lin_search(int arr[],int size,int item)
{
    int i,flag=-1;
    for(i=0;i<size;i++)
    {
        if(arr[i]==item)
            return i;
    }
    return -1;
}
int binary_search(int arr[],int size,int item)
{
	int high = size-1,low = 0;
	int mid = (low+high)/2;
	while(low<=high)
	{
		if(item==arr[mid])
			return mid;
		if(item > arr[mid]) // for descending '<'
			low = mid+1;
		else
			high = mid-1;
		mid = (low+high)/2;
	}
	return -1;
}


