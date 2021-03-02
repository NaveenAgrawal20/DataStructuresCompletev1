#include<stdio.h>
#include<conio.h>

int sum_dis(int n)
{  
    int sum;
    if(n==0)
        return 0;
    sum = n+sum_dis(n-1);
    printf("%d + ",n);
    // return n+sum_dis(n-1);
    return sum;
}

int main()
{
    int s = sum_dis(50);
    printf("\b\b= %d",s);  //\b to erase the last '+' sign
    getch();
    return 0;
}