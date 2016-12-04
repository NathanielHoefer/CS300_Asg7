/*****************************************************************************/
/* Program 7 - Hashing List													 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #7
 */


#include <vector>
#include <iostream>
#include "hashedList.hpp"

using namespace std;

int main()
{

	int listSize = 10;

	HashedList list(listSize);

//	cout << "Nearest prime to 100000: " << list.nearPrime(listSize) << endl;

	cout << "Hashed Value: " << list.hash(24) << endl;
	cout << "Hashed Value: " << list.hash(16) << endl;
	cout << "Hashed Value: " << list.hash(2) << endl;
	cout << "Hashed Value: " << list.hash(18) << endl;
	cout << "Hashed Value: " << list.hash(34) << endl;
	cout << "Hashed Value: " << list.hash(25) << endl;
	cout << "Hashed Value: " << list.hash(10) << endl;
	cout << "Hashed Value: " << list.hash(11) << endl;
	cout << "Hashed Value: " << list.hash(19) << endl;
	cout << "Hashed Value: " << list.hash(25) << endl;

	cout << list.insert(24) << endl;
	cout << list.insert(16) << endl;
	cout << list.insert(2) << endl;
	cout << list.insert(18) << endl;
	cout << list.insert(34) << endl;
	cout << list.insert(25) << endl;
	cout << list.insert(10) << endl;
	cout << list.insert(11) << endl;
	cout << list.insert(19) << endl;
	cout << list.insert(25) << endl;


	cout << "25 Found: " << list.search(25) << endl;
	cout << "10 Found: " << list.search(10) << endl;
	cout << "33 Found: " << list.search(33) << endl;


}



