/*************************************************************************
    This is the implementation file for the Check class. For more 
		information about the class see check.h.
    Students are expected to implement some of the functions shown 
		below.
	John Dolan			Ohio University EECS	September 2019
	Patricia Lindner	Ohio University EECS	August 2021
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "check.h"
#include "date.h"

using namespace std;

Check::Check(Date d, string p, int num, double amt)
{
    checknum = num;
    date = d;
    payto = p;
    amount = amt;
}

// Input and output functions
void Check::write_check(std::istream &ins)
{
    string first_name;
    string last_name;

    //checks if the current input stream is cin
    if (&cin == &ins)
    {
        cout << "Enter the following check information:" << endl;
        cout << "Date: ";
        ins >> date;

        cout << "Recipient: ";
        //stops new line character at end of file causing a duplicate of the final check
        if (ins.peek() == '\n')
        {
            ins.ignore();
        }
        getline(ins, payto);

        cout << "Amount: ";
        ins >> amount;

        //stop running of function
        return;
    }

    ins >> checknum;
    ins >> date;
    ins.ignore();
    getline(ins, payto);
    ins >> amount;   
}

void Check::output(std::ostream &outs) const
{
    outs << checknum << endl;
    outs << date << endl;
    outs << payto << endl;
    outs << amount << endl;
    
}

ostream &operator<<(ostream &outs, const Check &c)
{
    c.output(outs);
    return outs;
}

istream &operator>>(istream &ins, Check &c)
{
    c.write_check(ins);

    return ins;
}