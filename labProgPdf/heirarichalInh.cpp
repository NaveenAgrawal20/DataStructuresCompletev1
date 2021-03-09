#include <iostream>
using namespace std;
class Student
{
    string name;
    int rollno;

public:
    void setName(string n)
    {
        name = n;
    }
    void setRoll(int r)
    {
        rollno = r;
    }
    string getName()
    {
        return name;
    }
    int getRoll()
    {
        return rollno;
    }
};
class Exam : public Student
{
public:
    int marksA;
    int marksB;
    void setMarks(int a, int b)
    {
        marksA = a;
        marksB = b;
    }
};
class Sports : public Student
{
public:
    int sportmarks;
    void setSportsMarks(int c)
    {
        sportmarks = c;
    }
};
class Result : public Exam, public Sports
{
public:
    int total;
    float avg;
    int totalMarks()
    {
        total = marksA + marksB + sportmarks;
        return total;
    }
    float avgMarks()
    {
        avg = (total / 3);
        return avg;
    }
};
int main()
{
    Student s1;
    string name;
    int rollNo;
    cout << "Enter student's name ";
    cin >> name;
    s1.setName(name);
    cout << endl;
    cout << "Enter student's roll no. ";
    cin >> rollNo;
    s1.setRoll(rollNo);
    cout << endl;
    cout << "Student's Details " << endl;
    cout << s1.getName() << endl;
    cout << s1.getRoll() << endl;
    Result obj;
    int a, b, c;
    cout << "Enter Your 2 subjects Marks ";
    cin >> a >> b;
    obj.setMarks(a, b);
    cout << "Enter Your SpotrsMarks ";
    cin >> c;
    obj.setSportsMarks(c);
    cout << "Your Total Marks " << obj.totalMarks() << endl;
    cout << "Your Average " << obj.avgMarks() << endl;
}