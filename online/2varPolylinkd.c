#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
    int exp;
    struct node* next;
    char var;
};

struct node *addlast(struct node *start,int coeff,char var,int exp);

void traverse(struct node *);
struct node* add_poly(struct node *l1,struct node *l2)
{
    struct node *l3 = NULL;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    while(l1!=NULL && l2!=NULL)
    {
        // if exp is same
        if(l1->exp == l2->exp && l1->var == l2->var)
        {
            l3 = addlast(l3 , l1->coef+l2->coef,l1->var,l1->exp);
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1->exp > l2->exp && l1->var == l2->var) // if l1 is bigger (acc to exp) than we insert l1_term into list (decreasing order)
        {
            l3 = addlast(l3,l1->coef,l1->var,l1->exp);
            l1 = l1->next;
        }
        else
        {
            l3 = addlast(l3,l2->coef,l2->var,l2->exp);
            l2 = l2->next;
        }
    }
    // copy remaining linkedlist
    while(l1 != NULL)
    {
        l3 = addlast(l3,l1->coef,l1->var,l1->exp);
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        l3 = addlast(l3,l2->coef,l2->var,l2->exp);
        l2 = l2->next;
    }
    return l3;
};

int main()
{
    int i,n,c,e;
    char var;
    struct node *l1,*l2,*l3,*l4;
    l1 = l2 = l3 = l4 = NULL;
    printf("Enter no of terms for first polynomial\n");
    scanf("%d",&n);
    printf("Enter terms in decreasing order of power\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter coeff of x\n");
        scanf("%d",&c);
        fflush(stdin);
        printf("Enter var ");
        scanf("%c",&var);
        printf("Enter expo of x\n");
        scanf("%d",&e);
        l1 = addlast(l1,c,var,e);
    }
    printf("Enter no of terms for second polynomial\n");
    scanf("%d",&n);
    printf("Enter terms in decreasing order of power\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter coeff of x\n");
        scanf("%d",&c);
        fflush(stdin);
        printf("Enter var ");
        scanf("%c",&var);
        printf("Enter expo of x\n");
        scanf("%d",&e);
        l2 = addlast(l2,c,var,e);
    }
    //Adding Function called
    l3 = add_poly(l1,l2);
    // Displaying
    printf("1st equation is\n");
    traverse(l1);
    printf("2nd equation is\n");
    traverse(l2);

    printf("The resultant Added equation is\n");
    traverse(l3);
    return 0;

}
///////////////////////////////////////
///////////////////////////////////////
struct node *addlast(struct node *start,int coeff,char var,int exp){
    struct node* newnode,*p;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef = coeff;
    newnode->var = var;
    newnode->exp = exp;
    if(start == NULL)
        start = newnode;
    else
    {
        p = start;
        while(p->next != NULL)
            p = p->next;
        p->next = newnode;
    }
    newnode->next = NULL;
    return start;
};

void traverse(struct node *start)
{
    if(start == NULL){
        printf("\nList is Empty...\n");
        return ;
    }
    struct node *temp;
    temp = start;
    while(temp!=NULL)
    {
        if(temp->coef > 0)
            printf("+ %d(%c^%d) ",temp->coef,temp->var,temp->exp);
        else
            printf("- %d(%c^%d) ",abs(temp->coef),temp->var,temp->exp);
        temp = temp->next;
    }
    printf("\n");
}
/*
3
5 3
4 2
7 0
3
8 3
7 2
8 1

//output
+ 5x^3 + 4x^2 + 7x^0
+ 8x^3 + 7x^2 + 8x^1

+ 13x^3 + 11x^2 + 8x^1 + 7x^0

+ 40x^6 + 67x^5 + 68x^4 + 88x^3+ 49x^2 + 56^x.
*/
