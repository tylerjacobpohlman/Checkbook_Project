/*************************************************************************
     This is the main for our Checkbook project. You will be able to 
see, by reading the code below, the names and parameters of the 
functions that you will be creating in your Checkbook class (12 in total).

    You are NOT to alter this file except to uncomment function calls

  	John Dolan			Ohio University EECS	January 2021
	Patricia Lindner	Ohio University EECS	August 2021
*************************************************************************/
/*************************************************************************
     This version has been modified by commenting out all the function
     calls on the Checkbook object, allowing you to develop, compile and
     test each function one at a time. After you write a function 
     uncomment the call to that function, compile your project and test
     it with that option.
*************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "check.h"
#include "checkbook.h"
using namespace std;

/* This function shows the user the menu, asks them to enter their 
choice and then returns the integer value of that choice. */
int menu();

int main(){
    Check tmp;
    ifstream ifs;
    ofstream ofs;
    string user,userfile;
    int choice;  // user menu choice
    double depamount;  // amount of a deposit
    int rmnum;      // Check number to be removed from checkbook
    string payto_find; // used in listing all checks to a certain entity

    cout << "Please enter your user name (No spaces): ";
    cin >> user;

    Checkbook mychecks; // A default checkbook is constructed
    userfile = user + ".txt";
    ifs.open(userfile.c_str());

	// if no file this is first running for this user
    if(!ifs.fail()){ 
		mychecks.load_from_file(ifs);
		ifs.close();
    }

    do{
		choice = menu();
		switch(choice){
			case 1:
				cout << "Please enter amount of the deposit: $";
				cin >> depamount;
				mychecks.deposit(depamount);
				break;
			case 2:
				mychecks.write_check(cin);
				break;
			case 3:
				cout << "Your account balance: $" << mychecks.get_balance();
				break;
			case 4:
				mychecks.show_all(cout);
				break;
			case 5:
				cout << "Enter the Check Number of the Check to be removed: ";
				cin >> rmnum;
				mychecks.remove(rmnum);
				break;
			case 6:
				mychecks.number_sort();
				break;
			case 7:
				mychecks.payto_sort();
				break;
			case 8:
				mychecks.date_sort();
				break;
			case 9:
				while(cin.peek() == '\n' || cin.peek() == '\r'){
					cin.ignore(); // clear out leftover newlines
				}
				getline(cin, payto_find);
				mychecks.show(payto_find);
				break;
			case 10:
				cout << "Your average check amount: $" << mychecks.average();
				break;
			case 0:
				cout << "Thank you for using the Checkbook program.\n";
				cout << "All alterations to the checkbook will now be saved.\n";
				break;
			default:
				cout << "Invalid choice. Please choose again.\n";
				break;
		} // bottom of the switch
    } while(choice != 0);

	ofs.open(userfile.c_str());
	if(!ofs.fail()){
		mychecks.save(ofs);
	    ofs.close();
	}

	return 0;
}

int menu(){
    int choice;
	
    cout << "Your Checkbook. Please choose from the following:\n";
    cout << " 1) Make a deposit.\n";
    cout << " 2) Write a check.\n";
    cout << " 3) See the checkbook balance.\n";
    cout << " 4) See a listing of all checks written.\n";
    cout << " 5) Remove a check which has been cancelled.\n";
    cout << " 6) Sort by Check Number.\n";
    cout << " 7) Sort Alphabetically by Payto.\n";
    cout << " 8) Sort by Date.\n";
    cout << " 9) Find all checks written to a certain payee.\n";
    cout << "10) Find the average of all checks written.\n";
    cout << " 0) Quit.\n";

    cin >> choice;

    return choice;
}