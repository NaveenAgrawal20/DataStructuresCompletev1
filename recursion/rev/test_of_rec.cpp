#include<iostream>
using namespace std;
// This is a Test What I have learned of recursion till 08:20pm Aug-10-2020

/*-----------Factorial-------------------------
int fact(int n)
{
    if(n==0)    
        return 1;
    else
        return n*fact(n-1);
};*/

/*-------------Summation----------------------
int summation(int n)
{
	if(n==0)
		return 0;
	else
		return n+summation(n-1);
};*/

/*------------display numbers----------------
void display(int n)
{
	if(n==0)
		return;
	else
		display(n-1);
		cout<<n;	
};*/
/*-------------Factorial + display-----------------
int fact_dis(int n)
{
	if(n==0)
		return 1;
	else
	{
		printf("%d * ",n);  //cout<<n;
		return n*fact_dis(n-1);
	}
};*/
/*-------------------Sum + display----------------------
int sum_dis(int n)
{
	int sum;
	if(n==0)
		return 0;
	else
	{
		sum = n+sum_dis(n-1);
		cout<<n<<" + ";
		return sum;
	}
}*/
/*----------------Sum of digits in a number (digisum)-------------------
int digsum(int n)
{
	if(n<10)
		return n;
	else
	{
		return n%10 + digsum(n/10); 
	}
}*/
int digsum_dis(int n)
{
	int d;
	if(n<10)
	{
		printf("%d + ",n);
		return n;
	}	
	else
	{
		d = n%10 + digsum_dis(n/10);
		printf("%d + ",n%10);
		return d;
	}
}
/*---------Conversion decimal to binary Octal and hex---------
void conver(int n,int b)
{
	int rem;
	rem = n%b;
	if(n==0)
		return;
	conver(n/b,b);
	if(rem<10)
	{
		cout<<rem;
	}
	else
	{
		printf("%c",rem-10+'A');
	}
}*/
int main()
{
//	cout<<fact(5)<<endl;					//fact 
//	cout<<summation(5)<<endl;				//summation
//	display(10);       						//display
//	cout<<"\b\b = "<<fact_dis(5)<<endl;		//Factorial + display
//	cout<<"\b\b= "<<sum_dis(10)<<endl;		//sum+display
//	cout<<digsum(4532);						//digisum
	cout<<"\b\b = "<<digsum_dis(4532);
 /*   conver(2597,2);           			//conversion
    cout<<endl;							
	conver(2597,16);
	cout<<endl;
	conver(2597,8);  */	
	
	return 0;
}
