/*************************************************************************
    The Date class is one that I wrote many years ago, and have used in 
    a variety of projects. It has built-in exceptions that are thrown 
    when a user enters an invalid date.
    The point of this little demo program is to teach you how to work 
    with these exceptions, a feature you are free to include in your 
    Checkbook::input function.
 	John Dolan          Ohio University EECS	September 2019
     Patricia Lindner    Ohio University EECS     August 2021
*************************************************************************/
#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    Date d1;
    bool good = false;

    while (!good)
    {
        try
        {
            cout << "Enter your favorite date: ";
            cin >> d1;
            good = true;
        }
        catch (bad_month b1)
        {
            b1.msg();
        }
        catch (bad_day bd1)
        {
            bd1.msg();
        }
    }
    cout << "I always liked " << d1 << endl;

    return 0;
}