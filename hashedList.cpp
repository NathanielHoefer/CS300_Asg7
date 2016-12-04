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


/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************

HashedList::HashedList()
{
	vector<int> temp((int)(100 * 1.25), -1);
	mList = temp;
	mPrime = 101;
	mCurrSize = 0;
	mListSize = 100;
}


HashedList::HashedList(int size)
{
	// Creates vector 125% larger than specificed
	vector<int> temp((int)(size * 1.25), -1);
	mList = temp;
	mPrime = 100003;
	mCurrSize = 0;
	mListSize = size;
}


// FUNCTIONS ******************************************************************


//	Inserts a value into the list by first sending through a hashing function
//		Preconditions: None
//		Postconditions: Value is in a hashed location
//		Return: False if value cannot be placed
bool HashedList::insert(int value)
{
	int probe = quadProbe(value, true);

	if ( probe < 0 )
	{
		return false;
	}
	else
	{
		return true;
	}
}


/*****************************************************************************/


//	Checks to see if the value is contained in the list.
//		Precondition: None
//		Postcondition: None
//		Return: The number of probes taken to locate value, -1 if not
int HashedList::search(int value)
{
	return quadProbe(value, false);
}


/*****************************************************************************/


//	Sends value through hashing algorithm to determine hashed value.
//		Preconditions: None
//		Postcondition: None
//		Return: Hashed value
int HashedList::hash(int value)
{
	return ( value % mPrime );
}


/*****************************************************************************/


//	Tries to place the value into the list using the hashed value. If
//		unavailable, begin a quadratic probe until	open space found or 10
//		probes completed. If searching for a value, insert should ba false. If
//		inserting value, insert should be true
//		Preconditions: Hashed value is within the size of the list
//		Postconditions: Value is placed in list if location is found
//		Return: Number of probes, negative value if not placed.
int HashedList::quadProbe(int value, bool insert)
{
	int address = hash(value);
	int probeCnt = 1;
	bool found = false;

	// Continues while probe count doesn't exceed 10, the address is within the
	// vector size, and the hasn't been found.
	while ( ( probeCnt <= 10 && address <= (mListSize*1.25) ) && !found )
	{
		if ( insert )
		{
			// -1 indicates empty location
			if ( mList[address] < 0 )
			{
				mList[address] = value;
				mCurrSize++;
				found = true;
			}
			else
			{
				// Quadratic probe increase
				address += probeCnt * probeCnt;
				probeCnt++;
			}
		}
		// Searching for value
		else
		{
			if ( mList[address] == value )
			{
				found = true;
			}
			else
			{
				// Quadratic probe increase
				address += probeCnt * probeCnt;
				probeCnt++;
			}
		}
	}

	// Returns the probe count or -1 if not found or placed
	if ( ( probeCnt == 10 && !found ) || address > (mListSize*1.25) )
	{
		return -1;
	}
	else
	{
		return probeCnt;
	}
}


/*****************************************************************************/


//	Calculates the nearest prime to the entered value
//			Preconditions: None
//			Postconditions: None
//			Returns: The nearest prime to entered value
int HashedList::nearPrime(int value)
{
	int primeNum = value;
	bool isPrime = false;

	if ( primeNum % 2 == 0 )
	{
		primeNum++;
	}

	for ( int i = primeNum; !isPrime; i += 2 )
	{
		isPrime = true;

		for ( int j = 3; (j * j) <= primeNum && isPrime; j += 2 )
		{
			if ( primeNum % j == 0 )
			{
				isPrime = false;
			}
		}
	}

	return primeNum;
}


