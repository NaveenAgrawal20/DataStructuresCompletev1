#include <iostream>
using namespace std;
class Rectangle
{
public:
    int area, volume;
    void return_area()
    {
        cout << "Area is " << area << endl;
    }
    void return_volume()
    {
        cout << "Volume is " << volume << endl;
    }
};
class Shape
{
public:
    Shape()
    {
        cout << "Shapes are " << endl;
    }
};
class Cuboid : public Rectangle, public Shape
{
public:
    Cuboid(int l, int b, int h)
    {
        cout << "Cuboid: " << endl;
        area = 2 * ((l * b) + (b * h) + (h * l));
        volume = l * b * h;
    }
};
class Cube : public Rectangle
{
public:
    Cube(int a)
    {
        cout << "Cube:"<<endl;area = 6 * a * a;
        volume = a * a * a;
    }
};
int main()
{
    Cuboid c(10, 20, 30);
    c.return_area();
    c.return_volume();
    Cube s(50);
    s.return_area();
    s.return_volume();
    return 0;
}