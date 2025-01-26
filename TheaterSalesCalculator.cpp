// HW M2A2.cpp Wolfrom Theather Sales calculator
// Rafael Martinez 01/28/2020
// COP2000 Virtual
// Ref pg 116 117

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// Symbolic Constance price of the items
	const float balcony_seating = 50.00;
	const float grand_tier_seating = 175.25;
	const float loge_seating = 125.00;
	const float mezzanine_seating = 100.00;
	const float orchestra_seating = 230.50;

	//Total and subtotal of the price
	double total_price, sub_total_balcony, sub_total_tier, sub_total_loge, sub_total_mezzanine; 
	double sub_total_orchestra;

	//User input
	//quant short for quantity
	double quant_balcony, quant_tier, quant_loge, quant_mezzanine; 
	double quant_orchestra;

	//User input
	cout << "Please input the total number of seats purchased for Balcony Seating > "; 
	cin >> quant_balcony;
	cout << "Please input the total number of seats purchased for Grand Tier Seating > "; 
	cin >> quant_tier;
	cout << "Please input the total number of seats purchased for Loge Seating > "; 
	cin >> quant_loge;
	cout << "Please input the total number of seats purchased for Mezzanine Seating > "; 
	cin >> quant_mezzanine;
	cout << "Please input the total number of seats purchased for Orchestra_Seating > "; 
	cin >> quant_orchestra;
	cout << endl << endl;

	cout << setprecision(2) << fixed << showpoint; // decimal placement  

	//Calculation process
	sub_total_balcony = (balcony_seating * quant_balcony);
	sub_total_tier = (grand_tier_seating * quant_tier);
	sub_total_loge = (loge_seating * quant_loge);
	sub_total_mezzanine = (mezzanine_seating * quant_mezzanine);
	sub_total_orchestra = (orchestra_seating * quant_orchestra);	


	total_price = sub_total_balcony + sub_total_tier + sub_total_loge + sub_total_mezzanine + sub_total_orchestra;

	//Theater Info
	cout << "Wolfrom Theater Ticket Sales" << endl;
	cout << "----------------------------------------" << endl;

	cout << "Balcony = $" << sub_total_balcony << endl;
	cout << "Tier = $" << sub_total_tier << endl;
	cout << "Loge = $" << sub_total_loge << endl;
	cout << "Mezzanine = $" << sub_total_mezzanine << endl;
	cout << "Orchestra = $" << sub_total_orchestra << endl;
	cout << "Total Sales: $" << total_price << endl;

	return 0;
}