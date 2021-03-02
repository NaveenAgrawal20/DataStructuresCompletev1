#include<stdio.h>
#include<conio.h>

int main()
{
    int a=5,i=1;
    // for(i=1;i<=5;i++)
    // {
    //     a+=5;
    // }
    do{
        printf("%d\n",i);
        i+=1;
    }while(i<5);
    printf("i of do while = %d\n",i);
    i =1;
    while(i<5)
    {
      printf("%d\n",i);
        i+=1;  
    }
    printf("i of while = %d\n",i);
    // printf("%d",a);
    getch();
    return 0;
}
