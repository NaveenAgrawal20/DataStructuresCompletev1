#include<stdio.h>
#include<conio.h>
int sumation(int n)
{
    if(n<=0)
        return 0;
    else
        return (n+sumation(n-1));
};
int main()
{
    int sum;
    sum=sumation(10);
    printf("%d",sum);
    getch();
    return 0;
}