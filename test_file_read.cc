#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string L[20];
    ifstream ifs;

    ifs.open("bob_checks.txt");

    int i = 0;
    while (i < 20 && !ifs.eof())
    {
        getline(ifs, L[i]);
        i++;
    }

    i = 0;
    while (i < 20)
    {
        cout << L[i] << endl;
        i++;
    }
    ifs.close();
}