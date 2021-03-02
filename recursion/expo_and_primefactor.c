#include<stdio.h>
#include<conio.h>

// int expo(int n,int x)
// {
//     if(x==0)
//         return 1;
//     else
//     {
//         --x;
//         return n*expo(n,x); 
//     }
// }

void pfactors(int n)
{
    int i=2;
    if(n==1)
    {
		printf("%d",n);
        return;
	}
	else
    {
        while(n%i!=0)
        {
			i++;
		}
        printf("%d * ",i);
        pfactors(n/i); 
    }
};
int main()
{
	// printf("%d",expo(2,10));
	pfactors(121);
    getch();
    return 0;
}
