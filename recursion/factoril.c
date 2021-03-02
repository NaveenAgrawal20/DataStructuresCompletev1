#include<stdio.h>
#include<conio.h>
int fact(int num)
{
    if(num==0)
        return 1;
    else
        return (num*fact(num-1));
};
int main()
{
    int n=5,z;
    z = fact(n);
    printf("%d",z);
    getch();
    return 0;
}