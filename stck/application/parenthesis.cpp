#include<iostream>
#include<cstring>

#define MAX 30
using namespace std;
char stack[MAX];
int top=-1;

int ismatch(char a,char b)
{
    if(a == '(' && b ==')' )
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '[' && b ==']')    
        return 1;
    else
        return 0;
}

void push(char c)
{
    if(top==MAX-1)
    {  
        cout<<"Full";  
        return;
    }
    stack[++top] = c;
}
char pop()
{
    char rch;
    if(top==-1)
    {
        cout<<"Empty";
        exit(1);
    }
    rch = stack[top];
    top--;
    return rch;
}
int check(char exp[])
{
    char cc;
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top==-1)
            {
                cout<<"Right paranthesis are more than left"<<endl;
                return 0;
            }
            else
            {
                cc = pop();
                if(!ismatch(cc,exp[i]))
                {
                    cout<<"Mismatch paranthesis are "<<cc<<" and "<<exp[i]<<endl;
                    return 0;
                }
            }
        }
    }
    if(top==-1)
    {
        cout<<"Valid Expression"<<endl;
        return 1;
    }
    else
    {
        cout<<"Left paranthesis are more"<<endl;
        return 0;
    }
}
int main()
{
    char express[10]; //= "(2-1)+2";
    cout<<"Enter Expression ";
    cin>>express;
    check(express);

    return 0;
}
/*test cases 
[A+(b-1)]
A+{[3+4}]
A+{{3+5}}
*/