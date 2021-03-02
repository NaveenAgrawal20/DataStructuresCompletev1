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
        min = i;
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
//		if(xchanges==0)   // this causes (special case) to fail
//    	{
//            cout<<"List is Sorted ";
//    	    break;
//        }
	}
	cout<<"The no of exchanges are = "<<xchanges<<" ::comparison are "<<comp<<" and passes are "<<iter<<endl; //only see comp and passes(iter)//  comp = n(n-1)/2 in all cases O(n**2)
}
void insertsort(int arr[],int size)
{
	int i,j,k;
	int iter = 0,xchanges=0,comp=0;
	for(i=1;i<size;i++)
	{
		iter++;
		k = arr[i];
		for(j=i-1; j>=0 && arr[j]>k ;j--)   // if uses with condition(if-else break if arr[j] <= k or continue if arr[j] > k
		{
			arr[j+1] = arr[j];
		}	
		arr[j+1] = k;
	}
	cout<<"The no of exchanges are = "<<xchanges<<" ::comparison are "<<comp<<" and passes are "<<iter<<endl;
}
int main()
{

	
	int a[5] = {1,2,3,4,5}; //best
//	int a[5] = {3,4,5,2,1}; //average
//	int a[5] = {5,4,3,2,1}; //worst
// 	int a[5] = {1,2,5,4,3}; // Special case

					//exchanges + comparison = best,average,worst//pass+comp
//	display(a,5);	
//    buble(a,5);		 PREFERD := // improved:: 0+4 = 4, 7+10 = 17, 10+10 = 20 //4,14,14 //0+10=10,7+10=17,10+10=20 )(Not Improved) //differece in best case of improved //For Small list // 
//    display(a,5);
    
//    display(a,5);
//    selection(a,5);		// 0+10 = 10, 3+10 = 13, 2+10=10  //14,14,14 //cant be improved see special case  //Efficient where exchange operation is less required (Large files) as exchange cant be greater than n-1
//    display(a,5);
    
    display(a,5);
    insertsort(a,5);		// 4+0 = 4, 11+9= 20, 14+10=24//8, // cant be improved see special case  //Efficient where exchange operation is less required (Large files) as exchange cant be greater than n-1
    display(a,5);
    return 0;
}

