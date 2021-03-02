#include <iostream>
#include <cstring>
#define MAX 20
using namespace std;
struct stack
{
    char data[MAX];
    int top;
};

void push(struct stack*, char);
char pop(struct stack*);
char peep(struct stack);
bool isOperator(char ch);
int precedence(char ch);
void intopost(char in[], char pre[]);
void intopre(char in[], char pre[]);

void intopost(char in[], char post[])
{
    stack s1;
    s1.top = -1;
    int i = 0, j = 0;
    char ch;
    // READ LEFT TO RIGHT
    while (in[i] != '\0')
    {
        if (in[i] == '(')
            push(&s1, '(');
        else if (in[i] == ')')
        {
            while ((ch = pop(&s1)) != '(')
                post[j++] = ch;
        }
        else if (isOperator(in[i]))
        {
            while (s1.top != -1 && precedence(s1.data[s1.top]) >= precedence(in[i]))
            {
                post[j++] = pop(&s1);
            }
            push(&s1, in[i]);
        }
        else
        {
            post[j++] = in[i];
        }
        i++;
    }
    while (s1.top != -1)
    {
        post[j++] = pop(&s1);
    }
    post[j] = '\0'; // END string
}
void intopre(char in[], char pre[])
{
    stack s2;
    s2.top = -1;
    int i = strlen(in) - 1, j = 0;
    char ch;
    // READ TO LEFT TO RIGHT
    while (i >= 0)
    {
        if (in[i] == ')')
            push(&s2, ')');
        else if (in[i] == '(')
        {
            while ((ch = pop(&s2)) != ')')
                pre[j++] = ch;
        }
        else if (isOperator(in[i]))
        {
            while (s2.top != -1 && precedence(s2.data[s2.top]) > precedence(in[i]))
            {
                pre[j++] = pop(&s2);
            }
            push(&s2, in[i]);
        }
        else
        {
            pre[j++] = in[i];
        }
        i--;
    }
    while (s2.top != -1)
    {
        pre[j++] = pop(&s2);
    }
    pre[j] = '\0'; // END string
    _strrev(pre);
}

int main()
{
    char in[50], post[50], pre[50];
    printf("Enter equation in infix notation ");
    cin >> in;
    intopost(in, post);
    printf("\nEquation in postfix form %s", post);
    intopre(in, pre);
    printf("\nEquation in prefix form %s", pre);
    return 0;
}
void push(stack* s, char key)
{
    if (s->top == MAX - 1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    s->top++;
    s->data[s->top] = key;
}
char pop(struct stack* p)
{
    if (p->top == -1)
    {
        printf("\nUNDERFLOW\n");
        exit(1);
    }
    return p->data[p->top--];
}
char peep(struct stack s1)
{
    if (s1.top == -1)
    {
        printf("\nUNDERFLOW\n");
        exit(1);
    }
    return s1.data[s1.top];
}
int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%';
}
// A+B/C*(D+E)-F
// pre = -+A*/BC+DEF