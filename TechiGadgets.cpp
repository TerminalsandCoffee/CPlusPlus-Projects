/* This program manages user accounts by reading account data from a file, validating user credentials, 
and displaying account information based on access level. 
It includes functions to read and sort account data, validate user credentials, and display account information. 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

void showAll(string theAccounts[5][7]);
void sortInput(string theAccounts[5][7]);
bool readFile(string theAccounts[5][7]);
bool validateUser(string theAccounts[5][7], string, string, int*);

int main()
{
	cout << setprecision(2) << fixed << showpoint;   // Setting Formatting
	bool userGood;						             // Holds Bool value for User Validation
	bool fileGood;						             // Holds Bool value for File Read being good or bad
	int saveRow;					                 // Holds the row Username & Password match were found in. 
	string username;                                 // User input username 
	string password;                                // User input password
	string accountData[5][7] = { " " };             // Accounts Array that file is read into. 

	fileGood = readFile(accountData); // Validates if the Account Data file is opened, if so reads data into array. 

	{
		if (fileGood == true)
			cout << "The file was read succesfully...\n\n";
		else
		{
			cout << " The file was not read succesfully... exiting program.\n\n";
			return 0;
		}
	}

	sortInput(accountData);  // Sorts the array by last name alphabetically. 

	do
	{
		// Resets username & password each loop so they cannot be used by default. 
		username = "";
		password = "";


		// Prompts for Username & Password, exiting program on 0 entry in either case. 
		cout << "Enter the following information, or press 0 to Exit anytime..." << endl;
		cout << "Please enter your User Name :";
		cin >> username;

		if (username == "0")
		{
			cout << "\nThank You, have a nice day.\n\n";
			return 0;
		}

		cout << "Please Enter your User Password :";
		cin >> password;

		if (password == "0")
		{
			cout << "\nThank You, have a nice day.\n\n";
			return 0;
		}

		userGood = validateUser(accountData, username, password, &saveRow); // Call Uservalidation to check Username / Password Combination.

		{
			if (userGood == true)  // On true splits to Admin / User level paths. 
			{
				if (accountData[saveRow][5] == "A")  // Admin Level path. Prints out array table & saves to output file. 
				{  
					showAll(accountData);
				}

				else
				{
					cout << "\nWelcome Back " << accountData[saveRow][1] << "!\n\n";
					cout << setw(8) << left << accountData[saveRow][1];
					cout << setw(8) << left << accountData[saveRow][2];
					cout << setw(6) << left << accountData[saveRow][4];
					cout << setw(4) << left << accountData[saveRow][5];
					cout << setw(15) << left << accountData[saveRow][6];
					cout << endl << endl;
				}
			}

			else   // On False outputs error message and loops back around for Username & Password. 
			{
				cout << "Username and password do not match, please try again ...\n" << endl;
			}
		}


	} while (password != "0" || username != "0");


	return 0;

}

void showAll(string theAccounts[5][7])
{
	// If user is Admin, opens + creates an outputFile sortedBackup.txt
	// Then outputs entire array table while saving contents to sortedBackup.txt
	ofstream outputFile;
	outputFile.open("sortedBackup.txt");
	int row = 5;

	cout << "\n";

	for (int index = 0; index < row; index++)  
		// outputs Array to screen formatted for each column.
		// Also writes to backup outputFile. 
	{
		cout << setw(20) << right << theAccounts[index][0];
		cout << setw(8) << right << theAccounts[index][1];
		cout << setw(8) << right << theAccounts[index][2];
		cout << setw(10) << right << theAccounts[index][3];
		cout << setw(6) << right << theAccounts[index][4];
		cout << setw(4) << right << theAccounts[index][5];
		cout << setw(15) << right << theAccounts[index][6];
		cout << endl;

		outputFile << setw(20) << right << theAccounts[index][0];
		outputFile << setw(8) << right << theAccounts[index][1];
		outputFile << setw(8) << right << theAccounts[index][2];
		outputFile << setw(10) << right << theAccounts[index][3];
		outputFile << setw(6) << right << theAccounts[index][4];
		outputFile << setw(4) << right << theAccounts[index][5];
		outputFile << setw(15) << right << theAccounts[index][6];
		outputFile << endl;
	}

	cout << "Backup file created ....\n " << endl;

	outputFile.close();

}

void sortInput(string theAccounts[5][7]) 
{
	// Code to sort the array by last name alphabetically. 
	bool sorted = false;
	string temp;

		while (!sorted) {
			sorted = true;
			for (int index = 0; index < 4; ++index) {
				if (theAccounts[index][2] > theAccounts[index + 1][2]) {
					sorted = false;
					for (int last = 0; last < 7; ++last) {
						temp = theAccounts[index][last];
						theAccounts[index][last] = theAccounts[index + 1][last];
						theAccounts[index + 1][last] = temp;
					}
				}
			}
		}
}



bool readFile(string theAccounts[5][7])   // Function opens the AccoutData.txt, if succesful reads data into array & returns true, otherwise returns false.
{
	bool fileRead = false;
	int row = 5;
	int col = 7;
	ifstream inputFile;                  // inputFile file input object. 
	inputFile.open("AccountData.txt");  // Opens AccountData.txt file

	if (inputFile)
	{
		fileRead = true;
		// Reads file into theAccounts array. 
		for (int index = 0; index < row; index++)
			for (int index2 = 0; index2 < col; index2++)
				inputFile >> theAccounts[index][index2];
	}

	inputFile.close();

	return fileRead;
}

bool validateUser(string theAccounts[5][7], string username, string password, int *saveRow)   
// Validates user input username & password. Passes back True / False & saveRow value.
{
	bool passed = false;
	int user = 0;
	int pass = 3;
	int row = 0;

	// For loop passing through theAccounts array finding matching username + password. 
	// Returns false if no match is found. 

	for (int row = 0; row <= 4; row++)
	{
		if ((username == theAccounts[row][user]) && (password == theAccounts[row][pass]))
		{
			passed = true;
			*saveRow = row;
		}
	}

	return passed; // Passed bool value brought back to Main to determine true / false password & username input. 
}



/*

A. Declare Necessary variables and 2D array to store data from input file.
B. Call the readFile function and capture the returned value.
C. Test if file was succesffully read if so continue with program else exit with error message.
D. Sorts array alphabetically by last name. 
E. Do While...
	a. Ask User to Enter user name or Zero to exit.
	b. Read in User Name
	c. If User Name read in is "zero" Exit program
	d. Ask the user to Enter their password or Zero to Exit
	e. Read in User  Password
	f. If User Password read in is "zero" exit program.
	g. Call the Validate User function and capture the returned bool value & saveRow value
	h. If returned value from the Validate User function is true, continue
	   program to check access code if U or A
			i. If U - Display User Name, Year Joined, Access Level, and Tech Status
			ii. If A - Call showAll function to display array table & write contents to outputFile.  
	i. Else if returned value Not Valid from the Validate User function, FALSE,
	   output message usernamd and password invalid. Loops back to top.
*/