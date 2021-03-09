#include <iostream>
using namespace std;
class Shape //base class
{
public:
    double height, base;
    //constructor to assign initial values to height and base
    Shape()
    {
        height = 0;
        base = 0;
    }
    void get_data() //get_data() function to get values of height and base
    {
        cout << "\nEnter height and base to compute area:" << endl;
        cin >> height >> base;
    }
    virtual void display_area() //declaration of virtual function display_area()
    {
    }
};
//class triangle inheriting class Shape
class Triangle : public Shape
{
public:
    //redefining function display_area()
    void display_area()
    {
        cout << "\nArea of Triangle = " << (height * base) / 2 << endl;
    }
};
//class Rectangle inheriting class Shape
class Rectangle : public Shape
{
public:
    void display_area() //redefining function display_area()
    {
        cout << "\nArea of Rectangle = " << height * base << endl;
    }
};
int main()
{
    Shape *s;
    Triangle t;
    t.get_data();
    s = &t;
    s->display_area();
    Rectangle r;
    r.get_data();
    s = &r;
    s->display_area();
    return 0;
}
