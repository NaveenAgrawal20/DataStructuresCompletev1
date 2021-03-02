#include<stdio.h>
#include<conio.h>

void disp_n(int n)
{
    if(n==0)
        return;
    else   
        disp_n(n-1);
        printf("%d\t",n);
};
int main()
{
    disp_n(3);
    getch();
    return 0;
}
