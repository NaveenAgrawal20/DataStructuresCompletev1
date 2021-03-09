#include <iostream>
using namespace std;
class student
{
protected:
    int roll;
    string name;

public:
    void setvalue(int r, string s)
    {
        roll = r;
        name = s;
    }
    void printdetail()
    {
        cout << "The Roll number of the student is " << roll << endl;
        cout << "The Name of the student is " << name << endl;
    }
};
class exam : virtual public student
{
protected:
    float physics, maths;

public:
    void setmarks(float p, float m)
    {
        physics = p;
        maths = m;
    }
    void printmarks()
    {
        cout << "Marks in physics and maths are:" << endl;
        cout << "physics:" << physics << endl;
        cout << "maths:" << maths << endl;
    }
};
class sport : public virtual student
{
protected:
    float score;

public:
    void setscore(float s)
    {
        score = s;
    }
    void printscore()
    {
        cout << "The sport score of the student is " << score << endl;
    }
};
class result : public exam, public sport
{
    float total, avg;

public:
    void process()
    {
        total = physics + maths + score;
        avg = (physics + maths + score) / 3;
        printdetail();
        cout << endl;
        printmarks();
        cout << endl;
        printscore();
        cout << endl;
        cout << "The Total score of the student is " << total << endl;
        cout << "The Average score of the student is " << avg << endl;
    }
};
int main()
{
    result r1;
    r1.setvalue(12, "chirag");
    r1.setmarks(95, 95);
    r1.setscore(39.8);
    r1.process();
    return 0;
}
