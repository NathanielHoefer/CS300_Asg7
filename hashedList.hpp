/*****************************************************************************/
/* Program 7 - Hashing List													 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #7



Class Name: HashedList
	An object that holds a list of data that is hashed using a specific hashing
	function.

Data:
	- vector<int> mList: The list that contains the data

Constructors:
	+ HashedList(): Initializes an empty list with size of 100
	+ HashedList(int size): Initializes an empty list with size entered

Accessor and Mutator Functions:
	+ getSize();

Functions:
	+ insert(int value): Inserts a value into the list by first sending it
		through a hashing function.
		Preconditions: None
		Postconditions: Value is in a hashed location
		Return: False if value cannot be placed
		> Run value through hash
		> using quadProbe, try to place value
		> If quadProbe returns -1, return false

	+ search(int value): Checks to see if the value is contained in the list.
		Precondition: None
		Postcondition: None
		Return: The number of probes taken to locate value, -1 if not
		> Run value through hash
		> Search for the value using quadProbe
		> If found, return number of probes, otherwise return -1

	+ hash(int value): Sends value through hashing algorithm to determine hashed
		value.
		Preconditions: None
		Postcondition: None
		Return: Hashed value
		> Use modulo division of 100003 on the entered value
		> Return the hashed value

	+ quadProbe(int value, bool insert): Tries to place the value
		into the list using the hashed value. If unavailable, begin a quadratic
		probe until	open space found or 10 probes completed. If searching for a
		value, insert should ba false. If inserting value, insert should be true
		Preconditions: Hashed value is within the size of the list
		Postconditions: Value is placed in list if location is found
		Return: Number of probes
		> Go to location of hashed value and check if it is filled.
		> If so, begin quadratic progression until space is found.
		> If space is found and insert == true, then place the number into the
			list
		> If probe reaches 10, return -1 to indicate value not placed

	+ nearPrime(int value): Calculates the nearest prime to the entered value
		Preconditions: None
		Postconditions: None
		Returns: THe nearest prime to entered value
		> Check if value is even, if so, increment to avoid even numbers.
		> Divide starting with 3 through the value to see if value is even
 */

#ifndef HASHEDLIST_HPP_
#define HASHEDLIST_HPP_

#include <vector>

using namespace std;


/*****************************************************************************/
// Class Function Prototypes and Variables
/*****************************************************************************/


class HashedList
{

private:

// MEMBER VARIABLES ************************************************************

	// The list that contains the data
	vector<int> mList;

	// The prime number used for modulo division
	int mPrime;

	// The number of entries
	int mCurrSize;

	// Size of list
	int mListSize;


public:

// CONSTRUCTORS ***************************************************************

	HashedList();

	HashedList(int size);


// Accessors and Mutators

	int getSize() { return mList.size(); };


// FUNCTIONS ******************************************************************


//	Inserts a value into the list by first sending through a hashing function
//		Preconditions: None
//		Postconditions: Value is in a hashed location
//		Return: False if value cannot be placed
	bool insert(int value);


/*****************************************************************************/


//	Checks to see if the value is contained in the list.
//		Precondition: None
//		Postcondition: None
//		Return: The number of probes taken to locate value, -1 if not
	int search(int value);


/*****************************************************************************/


//	Sends value through hashing algorithm to determine hashed value.
//		Preconditions: None
//		Postcondition: None
//		Return: Hashed value
	int hash(int value);


/*****************************************************************************/


//	Tries to place the value into the list using the hashed value. If
//		unavailable, begin a quadratic probe until	open space found or 10
//		probes completed. If searching for a value, insert should ba false. If
//		inserting value, insert should be true
//		Preconditions: Hashed value is within the size of the list
//		Postconditions: Value is placed in list if location is found
//		Return: Number of probes
	int quadProbe(int value, bool insert);


/*****************************************************************************/


//	Calculates the nearest prime to the entered value
//			Preconditions: None
//			Postconditions: None
//			Returns: THe nearest prime to entered value
	int nearPrime(int value);

};

#endif /* HASHEDLIST_HPP_ */
