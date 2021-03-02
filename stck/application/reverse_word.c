#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 10
char stack[MAX];
int top=-1;
void push(char ch)
{
    if(top==MAX-1)
    {
        printf("Full");
        return;
    }
    stack[++top] = ch;
}
char pop()
{
    char rch;
    if(top==-1)
    {
        printf("Empty");
        exit(1);
    }
    rch = stack[top];
    top--;
    return rch;
}
int main()
{
    char name[10];
    printf("Enter word to be reversed ");
    gets(name);
    printf("Word to be reversed = %s ",name);
    for(int i=0;i<strlen(name);i++)
    {
        push(name[i]);
    }
    printf("\nReversed name is = ");
    for(int i=0;i<strlen(name);i++)
    {
        printf("%c",pop());
    }
    getch();
    return 0;
}