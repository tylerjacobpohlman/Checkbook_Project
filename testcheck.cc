/*************************************************************************
    The purpose of this little program is allow you to test the input
    and output functions and operators that you have written for the
    Check class. You should write these BEFORE you start developing the
    Checkbook class, and you should test your functions by compiling 
    and running this little main.
	John Dolan          Ohio University EECS	September 2019
    Patricia Lindner    Ohio University EECS    August 2021
*************************************************************************/

#include <fstream>
#include "check.h"
using namespace std;

int main()
{
    Check c1, c2;
    cout << "Write a check.\n";
    cin >> c1;
    cout << c1;
    cout << "Write another.\n";
    cin >> c2;
    cout << c2;

    return 0;
}
