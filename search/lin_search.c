#include<stdio.h>
#include<conio.h>
#define MAX 10

int main()
{
    int n,i,s,flag=0;
    printf("Enter array size");
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i<n;i++)
    {
        printf("Enter array elements ");
        scanf("%d",&arr[i]);
    }
    for(i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
	printf("Enter the item to search ");
	scanf("%d",&s);
    for(i = 0;i<n;i++)
    {
    	if(s==arr[i])
    	{
    		flag=1;
    		break;
		}
	}
	if(flag==1)
		printf("%d Element found at index %d ",s,i);
	else
		printf("Element is not pressent in array");
	getch();
    return 0;
}
