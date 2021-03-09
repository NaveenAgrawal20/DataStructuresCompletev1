#include <iostream>
using namespace std;
class rectangle
{
protected:
    float length, breadth;

public:
    rectangle()
    {
        cout << "enter length:";
        cin >> length;
        cout << "enter breadth:";
        cin >> breadth;
    }
};
//calculate class is derived from base class rectangle
class calculate : public rectangle
{
public:
    float area()
    {
        return length * breadth;
    }
    float perimeter()
    {
        return 2 * (length + breadth);
    }
};
int main()
{
    cout << "enter data for rectangle to find area and perimeter "<<endl;
    calculate c;
    cout << "Area = " << c.area() << " square meter" << endl;
    cout << "perimeter = " << c.perimeter() << " meter";
    return 0;
}
