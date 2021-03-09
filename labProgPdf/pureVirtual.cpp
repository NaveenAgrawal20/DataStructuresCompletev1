#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
//class shape
class Shape
{
public:
    double height, base;
    //constructor to assign initial values to height and base
    Shape()
    {
        height = 0;
        base = 0;
    }
    //declaration of pure virtual function display_area()
    virtual void display_area() = 0;
};
//class triangle inheriting class Shape
class Triangle : public Shape
{
public:
    // Constructor
    Triangle()
    {
        cout << "Enter the height : ";
        cin >> height;
        cout << "Enter the base : ";
        cin >> base;
    }
    //redefining function display_area()
    void display_area()
    {
        cout << "\nHeight : " << height << '\n'
             << "Base : " << base;
        cout << "\nArea of Triangle = " << (height * base) / 2 << " m^2 \n\n";
    }
};
//class Rectangle inheriting class Shape
class Rectangle : public Shape
{
public:
    //constructor
    Rectangle()
    {
        cout << "Enter the length : ";
        cin >> height;
        cout << "Enter the breadth : ";
        cin >> base;
    }
    //redefining function di splay_area()
    void display_area()
    {
        cout << "\nLength or height : " << height << '\n'
             << "Base or Breadth: " << base;
        cout
            << "\nArea of Rectangle = "
            << height * base
            << " m^2 \n\n";
    }
};
int main()
{
    int option;
    do
    {
        cout << "Choose the valid option \n 1 for area of triangle \n 2 for area of rectangle \n Any other no for exit ";
        cin >> option;
        if (option == 1)
        {
            Triangle t;
            t.display_area();
        }
        if (option == 2)
        {
            Rectangle r;
            r.display_area();
        }
    } while (option == 1 || option == 2);
    getch();
    return 0;
}
