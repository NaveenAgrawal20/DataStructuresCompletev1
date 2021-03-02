#include<stdio.h>
#include<conio.h>

void conver(int n,int b)
{   
    if(n%b==n)
    { 
        printf("%d ",n);
        return;
    }
    else
        conver(n/b,b);
        printf("%d ",n%b);
        // return conv;
};
int main()
{
    conver(45,2);
    printf("\n");
    conver(45,8);
    printf("\n");
    conver(45,16);
    printf("\n");
    // printf("%d",conver(4));
    getch();
    return 0;
}