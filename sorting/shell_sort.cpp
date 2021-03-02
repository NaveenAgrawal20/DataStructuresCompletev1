#include<iostream>
using namespace std;

// Shell Sort or Diminishing Increment Sort (Improved Version of Insertion Sort)

void display(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		int m = *(arr+i);
		printf("%d ",m);
	}
	printf("\n");
}

void shell_sort(int arr[],int size)
{
    int incr,i,j,k;
    cout<<"Enter maximum increment value ODD value ";
    cin>>incr;
    while(incr>=1)
    {
        for(i=incr;i<size;i++)
        {
            k = arr[i];
            for(j=i-incr;j>=0&&arr[j] > k;j = j-incr)
            {
                arr[j+incr] = arr[j];
            }
            arr[j+incr] = k;
        }
        // cout<<"---------------------------------------------------"<<endl;
        incr = incr - 2;
    }
}
int main()
{
	int a[17] = {19,63,2,6,7,10,1,18,9,4,45,3,5,17,16,12,56};
    display(a,17);
    shell_sort(a,17);
    display(a,17);
	return 0;
}
