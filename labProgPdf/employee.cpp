#include <iostream>
using namespace std;
class person // The Base class that contains the information of the person id and name
{
    int id;
    char name[30];

public:
    virtual void getdata()
    {
        cout << "\n Enter the name and number of the employee:" << endl;
        cin >> name >> id;
    }
    virtual void display()
    {
        cout << "\n Employee Name = " << name << "\n Number ="<<id;
    }
    virtual void bonus()
    {
        cout << "\n Bonus function of person base class is called";
    }
};
class admin : public virtual person // Admin class :- In this class the bonus is given
// to the sale of the current employee
{
    int sales;

public:
    void getdata()
    {
        cout << "\n Enter the Sale amount of the admin : " << endl;
        cin >> sales;
    }
    void display()
    {
        cout << "\n Admin Employee sale amount = " << sales;
    }
    void bonus()
    {
        if (sales > 2000)
            cout << "\n The bonus of the admin is : " << (sales * 0.25);
    }
};
class account : public virtual person // This Class contains information about the money in the account
// and bonus is generated accordingly
{
    long int amt;

public:
    void getdata()
    {
        cout << "\n Enter the amount accumulated in the account : "<< endl;
    cin >> amt;
    }
    void display()
    {
        cout << "\n Employee Account amount = " << amt;
    }
    void bonus()
    {
        if (amt > 10000)
            cout << "\n The bonus of the admin is : " << (amt * 0.25);
    }
};
class master : public admin, public account //This is the master Class that is used to call the functions of every class.
{
public:
    void getdata()
    {
        cout << "\n Executing getdata of master class :";
        person::getdata();
        admin::getdata();
        account::getdata();
    }
    void display()
    {
        cout << "\n executing display of master class :";
        person::display();
        admin::display();
        account::display();
    }
    void bonus()
    {
        cout << "\n executing bonus of master class :";
        person::bonus();
        admin::bonus();
        account::bonus();
    }
};
int main()
{
    person p, *per_ptr;
    admin a, *admin_ptr;
    account ac, *acc_ptr;
    master ms, *ms_ptr;
    cout << "\nassigning the addr of base class person to base class pointer ";
    per_ptr = &p;
    per_ptr->getdata();
    per_ptr->display();
    per_ptr->bonus();
    cout << "\n assigning the addr of admin class to base class pointer ";
    per_ptr = &a;
    per_ptr->getdata();
    per_ptr->display();
    per_ptr->bonus();
    cout << "\n assigning the addr of account class to base class pointer ";
    per_ptr = &ac;
    per_ptr->getdata();
    per_ptr->display();
    per_ptr->bonus();
    cout << "\n assigning the addr of class master to base class pointer ";
    per_ptr = &ms;
    per_ptr->getdata();
    per_ptr->display();
    per_ptr->bonus();
    return 0;
}
