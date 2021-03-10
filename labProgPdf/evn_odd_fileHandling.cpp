#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
    int n;
    ofstream fo1("even.txt");
    ofstream fo2("odd.txt");
    ifstream f("data.txt");

    if(!f)
    {
        cout<<"Data file can't be open"<<endl;
        getch();
        exit(1);
    }
    // Reading from data.txt and writing to even.txt and odd.txt
    while(!f.eof())
    {
        f>>n;
        if(n%2==0)
            fo1<<n<<endl;
        else
            fo2<<n<<endl;
    }
    // Reading From odd.txt and even.txt
    ifstream fr1("even.txt");
    cout<<"Even text data is "<<endl;
    while(1)
    {
        fr1>>n;
        if(fr1.eof())
            break;
        cout<<n<<endl;
    }
    ifstream fr2("odd.txt");
    cout<<"odd.txt data is "<<endl;
    while(1)
    {
        fr2>>n;
        if(fr2.eof())
            break;
        cout<<n<<endl;
    }
    //data file
    f.seekg(0,ios::beg);
    cout<<"Data.txt data is "<<endl;
    while(!f.eof())
    {
        f>>n;
        cout<<n<<endl;
    }

    return 0;
}
