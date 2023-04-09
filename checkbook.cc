/**
 *   @file: checkbook.cc
 * @author: Tyler Pohlman
 *   @date: 01/28/2022
 *  @brief: The implementation file ffor the Checkbook class.
 */

#include "checkbook.h"
#include "check.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Checkbook::Checkbook(int given_used, double given_balance, int given_next_avaliable)
{
    //changes checkbook variables
    used = given_used;
    balance = given_balance;
    next_avaliable = given_next_avaliable;
}

ifstream &Checkbook::load_from_file(ifstream &checkbook_file)
{
    //check object used to store into array
    Check given_check;

    //stores balance and next avaliable check number
    checkbook_file >> balance;
    checkbook_file >> next_avaliable;

    //sets number of used indexes
    used = 0;

    //goes through file looking for new checkbooks
    while (!checkbook_file.eof() && (next_avaliable <= SIZE))
    {
        //grabs the check data and stores it in checkbook
        checkbook_file >> given_check;

        //stores check into array
        data[used] = given_check;

        //increments array index
        used++;

        //stops new line character at end of file causing a duplicate of the final check
        while (checkbook_file.peek() == '\n')
        {
            checkbook_file.ignore();
        }
    }

    return checkbook_file;
}

void Checkbook::deposit(double given_amount)
{
    balance += given_amount;
}

void Checkbook::write_check(std::istream &ins)
{
    //the check being written
    Check new_check;

    //takes the input stream and uses it to write to the check
    ins >> new_check;

    //stores the new check in the checkbook
    data[used] = new_check;

    //sets check book number properly
    data[used].set_check_num(next_avaliable);

    //increments in array
    used++;

    //sets new avaliable check number
    next_avaliable++;

    //deducts check amount from total balance
    balance -= new_check.get_amount();
}

double Checkbook::get_balance() const
{
    return balance;
}

void Checkbook::show_all(ostream &outs)
{
    for (int i = 0; i < used; i++)
    {
        //formatting each check
        outs << "***************************************" << endl;
        outs << "Check Number: " << data[i].get_num() << endl;
        outs << "        Date: " << data[i].get_date() << endl;
        outs << "   recipient: " << data[i].get_payto() << endl;
        outs << "     Amount : " << data[i].get_amount() << '$' << endl;
        outs << "***************************************" << endl;
    }
}

void Checkbook::remove(int check_num)
{

    for (int i = 0; i < used; i++)
    {
        if (data[i].get_num() == check_num)
        {
            //adds back balance
            balance += data[i].get_amount();

            //swaps void check and end check
            Check tmp;
            tmp = data[i];
            data[i] = data[used - 1];
            data[used - 1] = data[i];

            //decrements to leave void check out of scope
            used--;

            //saving time
            break;
        }
    }

    //add back balance
}

void Checkbook::number_sort()
{
    //index of the smallest number during the run of the inner loop
    int smallest_index;
    //used to swap
    Check tmp;

    for (size_t i = 0; i < used - 1; i++)
    {
        smallest_index = i;

        for (size_t j = i + 1; j < used; j++)
        {
            if (data[j].get_num() < data[smallest_index].get_num())
            {
                smallest_index = j;
            }
        }

        //swaps the checks to put the check with the smallest number at the i position of the outter loop
        tmp = data[i];
        data[i] = data[smallest_index];
        data[smallest_index] = tmp;
    }
}

void Checkbook::payto_sort()
{
    //index of the smallest number during the run of the inner loop
    int smallest_index;
    //used to swap
    Check tmp;

    for (size_t i = 0; i < used - 1; i++)
    {
        smallest_index = i;

        for (size_t j = i + 1; j < used; j++)
        {
            if (data[j].get_payto() < data[smallest_index].get_payto())
            {
                smallest_index = j;
            }
        }

        //swaps the checks to put the check with the first alphabetical name at the i position of the outter loop
        tmp = data[i];
        data[i] = data[smallest_index];
        data[smallest_index] = tmp;
    }
}

void Checkbook::date_sort()
{
    //index of the smallest number during the run of the inner loop
    int smallest_index;
    //used to swap
    Check tmp;

    for (size_t i = 0; i < used - 1; i++)
    {
        smallest_index = i;

        for (size_t j = i + 1; j < used; j++)
        {
            if (data[j].get_date() < data[smallest_index].get_date())
            {
                smallest_index = j;
            }
        }

        //swaps the checks to put the check with the first chronological date at the i position of the outter loop
        tmp = data[i];
        data[i] = data[smallest_index];
        data[smallest_index] = tmp;
    }
}

void Checkbook::show(const string &given_name) const
{
    for (size_t i = 0; i < used; i++)
    {
        if (data[i].get_payto() == given_name)
        {
            //formatting each check
            cout << "***************************************" << endl;
            cout << "Check Number: " << data[i].get_num() << endl;
            cout << "        Date: " << data[i].get_date() << endl;
            cout << "   recipient: " << data[i].get_payto() << endl;
            cout << "     Amount : " << data[i].get_amount() << '$' << endl;
            cout << "***************************************" << endl;
        }
    }
}

double Checkbook::average() const
{
    double average = 0.0;
    double check_nums = 0.0;

    for (size_t i = 0; i < used; i++)
    {

        average += data[i].get_amount();
        check_nums++;
    }

    average /= check_nums;

    return average;
}

void Checkbook::save(ofstream &ofs)
{
    //stores balance and number of used checkbooks
    ofs << balance << endl;
    ofs << next_avaliable << endl;

    for (int i = 0; i < used; i++)
    {

        ofs << data[i];
    }
}