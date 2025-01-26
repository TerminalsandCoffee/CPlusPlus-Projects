//pg245,249

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

const float GOLD = .01,         // Gold Interest Rate %1
           	 SILVER = .02,		  // Silver Interest Rate %2
		         BRONZE = .04;       // Bronze Interest Rate %4
		

	double cost,                
		   rate;               // % Rate based on Membership level selection 

	int year;                   // Used to display year of membership
	char member = '0';             // Used to store user input of membership level

double initial_gym_fee = 1200.00;
double total_fee = 0.0;
int cost_of_fee_per_yr;

	do
	{

		// User Prompt to Select Membership value 1-4.
		cout << "\t Welcome to Ronda's Strikeforce Gym! " << endl;
		cout << "--------------------------------------------" << endl;
		cout << "\t Membership Fee Calculator\n" << endl;
		cout << " 1.  Gold\n";
		cout << " 2.  Silver\n";
		cout << " 3.  Bronze\n";
		cout << " 4.  Quit\n" << endl;
		cout << "Please Enter your Membership Level ( 1-3 , 4 to Quit) \n";
		cin >> member;
		cout << endl;
		cout << fixed << showpoint << setprecision(2);


		// Input Validation  
		while (member < '1' || member > '4')
		{
			cout << "Invalid Selection, please select Option 1-4\n";
			cin >> member;
		}

		// User Input of Option 1-3
		switch (member)
		{

			// Gold Interest Rate Fees Over 10 Years
			// rate = Gold
		case '1': rate = GOLD;
			break;

			// Silver Interest Rate Fees Over 10 Years
			// rate = Silver 
		case '2': rate = SILVER;
			break;

			// Bronze Interest Rate Fees Over 10 Years
			// rate = Bronze  
		case '3': rate = BRONZE;
			break;
		}

		
		if (member == '1' || member == '2' || member == '3')
		{
		 for(cost_of_fee_per_yr = 1; cost_of_fee_per_yr <= 10;) {

    cout << "Year" << setw(4) << cost_of_fee_per_yr << setw(10) << initial_gym_fee << endl;

    total_fee = initial_gym_fee * rate;
    initial_gym_fee += total_fee;	// accumulator

    cost_of_fee_per_yr++;
     }
  }


	} while (member != '4');

	// If User Selects 4, Exits program. Menu loops 1-3, Invalid otherwise, and Exit on 4.
	if (member == '4')
		cout << "\nThank you for using Rhonda's Fee Calculator!\n" << endl;

	return 0;
}


/*
Algorithm Used
1. Start
2. Declare Constants & Variables
a. Constants GOLD = .01 , SILVER = .02, BRONZE - .04, initial_gym_fee = 1200.00
b. double = cost, rate;  int = year ; char = member ;
3. Output Welcome Screen & Menu Options to User
4. Ask user for input to menu selection. 1 -4 options. Stored into char member variable.
5. Validate user input with while loop.
6. Switch branch user selection into Member Levels based on member variable
a. 1 = Gold, 2 = Silver, 3 = Bronze
7. Inside of each switch rate is set to GOLD / SILVER / BRONZE.
8. Run a table loop that iterates 10 times, once for each of 10 years.
a. each loop cost is initialized as =  initial_gym_fee * rate.
b. after each loop run for 10 Iterations.
C. output to user the 10 loops as a formatted table.
9. Loop back to main menu after each selection with do / while loop
10. End program on Quit selection , and thank user for using program.
*/