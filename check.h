/*************************************************************************
    This is the header file for a check class. It holds the information 
for a single check, which is the check number, the date it was written, 
to whom it was written and the amount. There are two ways of inputting 
into the check, the write_check function and the >> operator. There are 
also two ways of outputting the check, the output function and the << 
operator.
    Checks cannot be written for less than $0.01.
  	John Dolan			Ohio University EECS	September 2019
	Patricia Lindner	Ohio University EECS	August 2021
*************************************************************************/

#ifndef CHECK
#define CHECK

#include <iostream>
#include <string>
#include "date.h"

class Check{
    public:
		Check(Date d = Date(1, 1, 1900), std::string p = "VOID", int num = 0, double amt = 0);

		// Input and output functions
		void write_check(std::istream& ins);
		void output(std::ostream& outs)const;

		// Accessor functions
		double get_amount()const {return amount;}

        Date get_date()const {return date;}

		std::string get_payto()const {return payto;}
		
		int get_num()const {return checknum;}

		// Mutator function
		void set_check_num (int n){checknum = n;}

    private:
		int checknum;
		Date date;
		std::string payto;
		double amount;
};

std::ostream& operator << (std::ostream& outs, const Check& c);

std::istream& operator >> (std::istream& ins,Check& c);

#endif