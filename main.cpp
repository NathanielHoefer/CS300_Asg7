/*****************************************************************************/
/* Program 7 - Hashing List													 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #7


Description:
	Build a hash table that will read in and store 100000 values while
	outputting to a file all of the numbers that couldn't be placed. Then read
	in and search for the next 100000 values, outputting how many probes taken
	to locate the value or if it wasn't found.

Functions:
	+ main() - Executes the program
		> Create a hash table with the size of 100000
		> Open both the input and output stream
		> Try to input the first 100000 items into the hash table.
			> If the value isn't stored, output that value
		> Try to search for the rest of the values found in the input file.
			> If the value is found, output the value and how many probes taken
			> If the value is not found, then output as such.
		> Close the file streams
 */


#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "hashedList.hpp"

using namespace std;

int main()
{

	int listSize = 100000;
	int inVal;
	int result;

	HashedList list(listSize);

	ifstream input("file.dat");
	ofstream output("results.dat");

	output << "Creating Hashing Table...\n\n";
	output << "Values Not Stored: \n\n";

	// Input the first 100,000 values
	for ( int i = 0; i < listSize; i++ )
	{
		input >> inVal;
		if ( !list.insert(inVal) )
			output << inVal << "\n";
	}

	output << "\nSearching Hashing Table...\n\n";

	// Search for the remaining values
	while ( !input.eof() )
	{
		input >> inVal;
		result = list.search(inVal);

		if ( result < 0 )
		{
			output << left << setw(14) << "Not Found: " << inVal << "\n";
		}
		else
		{
			output << left << setw(14) << "Found: " << setw(8) << inVal;
			output << " Probes: " << result << "\n";
		}
	}

	input.close();
	output.close();

	cout << "Program Completed" << endl;

}



