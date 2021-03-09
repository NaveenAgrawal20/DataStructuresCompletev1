#include <iostream>
using namespace std;
class rectangle
{
public:
    int getArea(int l, int b, int h)
    {
        return 2 * l * b + 2 * b * h + 2 * h * l;
    }
};
class shape
{
public:
    int getVolume(int l, int b, int h)
    {
        return l * b * h;
    }
};

class Cuboid : public rectangle, public shape
{
    int length;
    int breadth;
    int height;

public:
    Cuboid()
    {
        length = 0;
        breadth = 0;
        height = 0;
    }
    void read()
    {
        cout << "Enter Length: ";
        cin >> length;
        cout << "Enter Breadth: ";
        cin >> breadth;
        cout << "Enter Height: ";
        cin >> height;
    }
    int area()
    {
        return rectangle::getArea(length, breadth,
                                  height);
    }
    int volume()
    {
        return shape::getVolume(length, breadth,
                                height);
    }
};
int main()
{
    Cuboid rt;
    rt.read();
    cout << "Area : " << rt.area() << endl;
    cout << "Volume : " << rt.volume() << endl;
    return 0;
}