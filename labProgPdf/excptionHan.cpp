#include <iostream>
#include <cmath>
using namespace std;
//user_defined function to find the square root of a number
void my_sqrt()
{
    //try block to check whether the input number is greater than 0 or not
    try
    {
        double num;
        cout << "Enter the number: \n";
        cin >> num;
        //if num less than 0, it will throw error,ie., 0 is an error code for any exception occur
        if (num < 0)
        {
            throw 0;
        }
        else
        {
            double sqroot;
            sqroot = sqrt(num); //sqrt function is used,i.e., from cmath header file
            cout << "Sqaure root of " << num << " is: \n";
            cout << sqroot;
        }
    }
    //catch block handles the exception thrown
    //exception thrown is 0, i.e., INT type error, so the catch blockhandles it in INT type variable 
    catch (int x)
    {
        cout << "wrong value, Negative values not allowed !!! ";
    }
}
int main()
{
    //calling the function
    my_sqrt();
    return 0;
}