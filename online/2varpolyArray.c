#include<stdio.h>

 /* declare structure for polynomial */
 struct poly
 {
	 int coeff;
	 int expoX;
	 int expoY;
 };
 /* declare three arrays p1, p2, p3 of type structure poly.
 * each polynomial can have maximum of ten terms
 * addition result of p1 and p2 is stored in p3 */

 struct poly p1[10],p2[10],p3[10];

 /* function prototypes */
 int readPoly(struct poly []);
 int addPoly(struct poly [],struct poly [],int ,int ,struct poly []);
 void displayPoly( struct poly [],int terms);

 int main()
 {
	int t1,t2,t3;

	/* read and display first polynomial */
	t1=readPoly(p1);
	printf(" \n First polynomial : ");
	displayPoly(p1,t1);
	/* read and display second polynomial */
	t2=readPoly(p2);
	printf(" \n Second polynomial : ");
	displayPoly(p2,t2);

	/* add two polynomials and display resultant polynomial */
	t3=addPoly(p1,p2,t1,t2,p3);
	printf(" \n\n Resultant polynomial after addition : ");
	displayPoly(p3,t3);
	printf("\n");

	return 0;
 }

 int readPoly(struct poly p[10])
 {
	int t1,i;

	printf("\n\n Enter the total number of terms in the polynomial:");
	scanf("%d",&t1);

	printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for(i=0;i<t1;i++)
	{
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d",&p[i].coeff);
		fflush(stdin);
//        printf("Enter var 1");
//        scanf("%c",&p[i].var1);
//        fflush(stdin);
//        printf("Enter var 2");
//        scanf("%c",&p[i].var2);
		printf("      Enter the exponent(%d) for X: ",i+1);
		scanf("%d",&p[i].expoX);        /* only statement in loop */
        printf("      Enter the exponent(%d) for Y: ",i+1);
		scanf("%d",&p[i].expoY);
	}
	return(t1);
 }

 int addPoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
 {
	int i,j,k;


	i=0;
	j=0;
	k=0;
	while(i<t1 && j<t2)
	{
		if(p1[i].expoX==p2[j].expoX && p1[i].expoY == p2[j].expoY)
		{
			p3[k].coeff=p1[i].coeff + p2[j].coeff;
			p3[k].expoX=p1[i].expoX;
			p3[k].expoY=p1[i].expoY;
			i++;
			j++;
			k++;
		}
		else if(p1[i].expoX+p1[i].expoY>p2[j].expoX+p2[j].expoY )
		{
			p3[k].coeff=p1[i].coeff;
			p3[k].expoX=p1[i].expoX;
			p3[k].expoY=p1[i].expoY;
			i++;
			k++;
		}
		else
		{
			p3[k].coeff=p2[j].coeff;
			p3[k].expoX=p2[j].expoX;
			p3[k].expoY=p2[j].expoY;
			j++;
			k++;
		}
	}

	/* for rest over terms of polynomial 1 */
	while(i<t1)
	{
		p3[k].coeff=p1[i].coeff;
        p3[k].expoX=p1[i].expoX;
        p3[k].expoY=p1[i].expoY;
        i++;
        k++;
	}
	/* for rest over terms of polynomial 2 */
	while(j<t2)
	{

		p3[k].coeff=p2[j].coeff;
        p3[k].expoX=p2[j].expoX;
        p3[k].expoY=p2[j].expoY;
        j++;
        k++;
	}

//	while(i<t1 && j<t2)
//	{
//		if(p1[i].var1 == p2[j].var1 && p1[i].var2 == p2[j].var2 && p1[i].expoX==p2[j].expoX && p1[i].expoY == p2[j].expoY)
//		{
//			p3[k].coeff=p1[i].coeff + p2[j].coeff;
//			p3[k].expoX=p1[i].expoX;
//			p3[k].expoY=p1[i].expoY;
//            p3[k].var1 = p1[i].var1;
//            p3[k].var2 = p1[i].var2;
//			i++;
//			j++;
//			k++;
//		}
//		else if(p1[i].var1 == p2[j].var1 && p1[i].var2 == p2[j].var2 && p1[i].expoX+p1[i].expoY>p2[j].expoX+p2[j].expoY )
//		{
//			p3[k].coeff=p1[i].coeff;
//			p3[k].expoX=p1[i].expoX;
//			p3[k].expoY=p1[i].expoY;
//            p3[k].var1 = p1[i].var1;
//            p3[k].var2 = p1[i].var2;
//			i++;
//			k++;
//		}
//		else
//		{
//			p3[k].coeff=p2[j].coeff;
//			p3[k].expoX=p2[j].expoX;
//			p3[k].expoY=p2[j].expoY;
//            p3[k].var1 = p2[j].var1;
//            p3[k].var2 = p2[j].var2;
//			j++;
//			k++;
//		}
//	}
//
//	/* for rest over terms of polynomial 1 */
//	while(i<t1)
//	{
//		p3[k].coeff=p1[i].coeff;
//        p3[k].expoX=p1[i].expoX;
//        p3[k].expoY=p1[i].expoY;
//        p3[k].var1 = p1[i].var1;
//        p3[k].var2 = p1[i].var2;
//        i++;
//        k++;
//	}
//	/* for rest over terms of polynomial 2 */
//	while(j<t2)
//	{
//
//		p3[k].coeff=p2[j].coeff;
//        p3[k].expoX=p2[j].expoX;
//        p3[k].expoY=p2[j].expoY;
//        p3[k].var1 = p2[j].var1;
//        p3[k].var2 = p2[j].var2;
//        j++;
//        k++;
//	}

	return(k); /* k is number of terms in resultant polynomial*/
 }

 void displayPoly(struct poly p[10],int term)
 {
	int k;

	for(k=0;k<term;k++)
    {
    if(p[k].coeff >0)
         printf("+%d(x^%dy^%d)",p[k].coeff,p[k].expoX,p[k].expoY);
    else
        printf("-%d(x^%dy^%d)",-1*p[k].coeff,p[k].expoX,p[k].expoY);
    }
//	printf("%d(x^%d)",p[term-1].coeff,p[term-1].expo);
}
