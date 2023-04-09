/**
 *   @file: checkbook.h
 * @author: Tyler Pohlman
 *   @date: 01/28/2022
 *  @brief: This is the header file for the Checkbook class. It stores an array of up to 200 checks, total user balance, and next
 *          avaliable check. It allows different sorting functions of the Check objects, readings Check objects from a file, adding
 *          a Check to the Checkbook, removing a Check from the Checkbook, adding to the balance, showing a list of all the stored 
 *          checks, showing checks that match a specified name, finding the amount average of all the checks, and saving balance,
 *          next avaliable check, and each Check to a file.
 */

#ifndef CHECKBOOK
#define CHECKBOOK

#include "check.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

class Checkbook {
    public:

    static const std::size_t SIZE = 200;

    Checkbook(int given_used = 0, double given_balance = 0.0, int given_next_avaliable = 0);

    /**
     * @brief grabs Check objects, balance, and next avaliable check from a file
     * 
     * @param checkbook_file a file containing valid Checkbook information
     * @return ifstream
     */
    std::ifstream& load_from_file(std::ifstream& checkbook_file);

    /**
     * @brief adds to the balance
     * 
     * @param given_amount a valid amount of money greater than 0
     */
    void deposit(double given_amount);

    /**
     * @brief adds a Check object to the Checkbook
     * 
     * @param ins an input stream
     */
    void write_check(std::istream& ins);

    /**
     * @brief gets the Checkbook balance
     * 
     * @return double 
     */
    double get_balance() const;

    /**
     * @brief outputs all the check Objects
     * 
     * @param outs an output stream
     */
    void show_all(std::ostream& outs);

    /**
     * @brief removes a new
     * 
     * @param check_num the check number
     */
    void remove(int check_num);

    /**
     * @brief sorts the Check objects by check number
     * 
     */
    void number_sort();

    /**
     * @brief sorts the Check objects by recipient
     * 
     */
    void payto_sort();

    /**
     * @brief sorts the Check objects by dates
     * 
     */
    void date_sort();

    /**
     * @brief shows Checks that match the given name
     * 
     * @param given_name a check recipients name
     */
    void show(const std::string& given_name) const;

    /**
     * @brief computes the average amount of all written and valid checks
     * 
     * @return double 
     */
    double average() const;

    /**
     * @brief writes balance, next avaliable check, and all check objects to given file stream
     * 
     * @param ofs an output file stream
     */
    void save(std::ofstream& ofs);


    private:
    //Checks array
    Check data[SIZE];

    //next avaliable index
    std::size_t used;

    //next avaliable check number
    std::size_t next_avaliable;

    //how much money is avaliable
    double balance;
};

#endif