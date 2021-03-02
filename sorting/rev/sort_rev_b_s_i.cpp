#include<iostream>
using namespace std;


void display(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		int m = *(arr+i);
		printf("%d ",m);
	}
	printf("\n");
}
void buble(int arr[],int size)
{
    int temp;
	int iter=0,xchanges=0,comp=0; 	// iteration,exchanges(swap),comparison
    for(int i=0;i<size-1;i++)
    {
    	iter++;   // pass
        for(int j=0;j<size-i-1;j++)
        {
        	comp++;
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                xchanges++;
            }
        }
        if(xchanges==0)
    	{
            cout<<"List is Sorted ";
    	    break;
        }
    }
    cout<<"The no of exchanges are = "<<xchanges<<" ::comparison are "<<comp<<" and passes are "<<iter<<endl;
}
void selection(int arr[],int size)
{
	int i,j,temp,min;
    int iter=0,comp=0,xchanges=0;
    for(i=0;i<size-1;i++)
    {
    	iter++;
        min = i;  //(i am not using min to decrease space requirement)
        for(j=i+1;j<size;j++)
        {
        	comp++;
        	if(arr[min] > arr[j])
			{
				min = j;
			}
		}
    	if(min!=i)
        {
        	temp = arr[i];
        	arr[i] = arr[min];
        	arr[min] = temp; 
        	xchanges++;
		}
	}
	cout<<"The no of exchanges are = "<<xchanges<<" ::comparison are "<<comp<<" and passes are "<<iter<<endl; //only see comp and passes(iter)//  comp = n(n-1)/2 in all cases O(n**2)
}
void insertsort(int ar[],int size)
{
    int k=0,j,i;
    for(i=1;i<size;i++)
    {
        k = ar[i];
        for(j=i-1;j>=0 && ar[j] > k;j--)
        {
            ar[j+1] = ar[j];
        }
        ar[j+1] = k;
    }
}
int main()
{

	
//	int a[5] = {1,2,3,4,5}; //best
	int a[5] = {3,4,5,2,1}; //average
//	int a[5] = {5,4,3,2,1}; //worst
// 	int a[5] = {1,2,5,4,3}; // Special case

					//exchanges + comparison = best,average,worst
//	display(a,5);	
//    buble(a,5);		// 0+10 = 10, 7+10 = 17, 10+10=20  // improved:: 0+4 = 4, 7+10 = 17, 10+10 = 20  //differece in best case of improved
//    display(a,5);
    
    // display(a,5);
    // selection(a,5);		// 0+10 = 10, 3+10 = 13, +10=20  // cant be improved see special case
    // display(a,5);

    display(a,5);
    insertsort(a,5);		
    display(a,5);
    return 0;
}

