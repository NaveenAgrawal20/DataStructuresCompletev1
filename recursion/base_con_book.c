#include<stdio.h>
#include<conio.h>

void conver(int n,int b)
{
    int rem;
    rem = n % b;
    if(n == 0)    
        return;
    conver(n/b,b);
    if(rem<10)
        printf("%d",rem);
    else
        printf("%c",rem-9+64);

};
int main()
{
    conver(2597,2);
    printf("\n");
    conver(2597,16);
    printf("\n");
    conver(2597,8);
    getch();
    return 0;
}
// for(int i=0;i<5;i++)
//     {
//         printf("%c",97+i); //a
//         printf("%c",65+i); //A
//     }