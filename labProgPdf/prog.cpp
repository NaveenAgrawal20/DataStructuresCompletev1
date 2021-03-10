#include <iostream>

#include <fstream>

using namespace std;

int main()
{

    char text[200];

    ofstream file; // file declaration

    file.open("example.txt");

    cout << "Write text to be written on file." << endl;

    cin.getline(text, sizeof(text));

    file << text << endl; // Writing on file

    file.close();

    cout << "written file: " << endl;

    ifstream filein("example.txt");
    while(1)
    {
        filein >> text; // Reding from file
        if(filein.eof())
            break;
        cout << text << " " ;
    }
    filein.close(); //closing the file

    return 0;
}
