#include <stdio.h>
/*Program to demonstrate tower of hanoi algorithm.*/
void towerofHanoi(int n,char beg, char aux, char end)
{
    if(n == 1){
        printf("Disk moved from %c to %c\n",beg,end);
        return;
    }
    towerofHanoi(n-1,beg,end,aux);
    printf("Disk moved from %c to %c\n",beg,end);
    towerofHanoi(n-1,aux,beg,end);
}

int main()
{
    towerofHanoi(3,'A','B','C');
    return 0;
}
