#include<stdio.h>
#include<conio.h>
//sum of digits in a number;
int sum_digi(int n)
{
    if(n/10==0)
        return n;
    else
        return n%10+sum_digi(n/10);
};
void display(int n)
{
    if(n/10==0)
    {    printf("%d + ",n);
        return;
    }
    else
        display(n/10);
        printf("%d + ",n%10);
}
int main()
{
    printf("%d ",sum_digi(4523));
    display(4523);
    getch();
    return 0;
}