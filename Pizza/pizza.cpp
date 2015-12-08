/* 
Author: Michael Matthews
Date: 16 Sep. 2015
Class: CS 142 - Pizza Lab

Test Cases:
	Test Case 1:
		Guests: 3
		Tip: 5%
		Larges: 0
		Meduims: 1
		Small: 0
		Area (inches squared): 201.062
		Area/Person (inches squared): 67.0206
		Cost: $12

	Test Case 2:
		Guests: 37
		Tip: 12%
		Larges: 5
		Mediums: 0
		Smalls: 2
		Area (inches squared): 1796.99
		Area/Person (inches squared): 48.5673
		Cost: $99

	Test Case 3:
		Guests: 22
		Tip: 25%
		Larges: 3
		Mediums: 0
		Smalls: 1
		Area (inches squared): 1055.57
		Area/Person(inches squared): 47.9806 
		Cost: $64

*/



#include <iostream>
#include <string>
using namespace std;

int main()
{
	const double PI = 3.14159;
	const int PEOPLE_LARGE = 7;
	const int PEOPLE_MEDUIM = 3;
	const int PEOPLE_SMALL = 1;
	const int RADIUS_LARGE = (20/2) * (20/2);
	const int RADIUS_MEDIUM = (16/2) * (16/2);
	const int RADIUS_SMALL = (12/2) * (12/2);
	const double PRICE_LARGE = 14.68;
	const double PRICE_MEDIUM = 11.48;
	const double PRICE_SMALL = 7.28;
	
	// Prompt user for number of guests

	cout << "Enter the number of guests attending the event: ";
	int guestNumber;
	cin >> guestNumber;

	//Prompt user for tip percentage
	cout << "What is the percent of the total price to be as a tip? ";
	int tipPercentage;
	cin >> tipPercentage;

	//Set int and doubles
	int largePizzas;
	int meduimPizzas;
	int smallPizzas;
	int remainder2;
	int remainder;
	double areaLarge;
	double areaMeduim;
	double areaSmall;

	//Calculate Part 1 (Count your many pizzas) 
	//Determine how many Large, Medium and Small pizzas needed

	largePizzas = guestNumber / PEOPLE_LARGE;
	remainder = guestNumber % PEOPLE_LARGE;
	meduimPizzas = remainder / PEOPLE_MEDUIM;
	remainder2 = remainder % PEOPLE_MEDUIM;
	smallPizzas = remainder2 / PEOPLE_SMALL;
	
	//computing square inches of each pizza needed

	areaLarge = largePizzas * RADIUS_LARGE * PI;
	areaMeduim = meduimPizzas * RADIUS_MEDIUM * PI;
	areaSmall = smallPizzas * RADIUS_SMALL * PI;

	//total area
	double totalArea;
	totalArea = areaLarge + areaMeduim + areaSmall;

	// total area per person
	double totalAreaPerPerson = totalArea / guestNumber;


	//math to determine total price before tip
	double priceTotalLarge;
	double priceTotalMeduim;
	double priceTotalSmall;
	double totalPriceBefore;

	priceTotalLarge = PRICE_LARGE * largePizzas;
	priceTotalMeduim = PRICE_MEDIUM * meduimPizzas;
	priceTotalSmall = PRICE_SMALL * smallPizzas;
	totalPriceBefore = priceTotalLarge + priceTotalMeduim + priceTotalSmall;

	//math to include tip
	double priceWithTip;
	priceWithTip = totalPriceBefore + (totalPriceBefore * (tipPercentage * .01));

	//round number
	int priceRounded;
	priceRounded = round(priceWithTip);

	//cout all info needed
	cout << "Number of guests " << guestNumber << endl;
	cout << "Tip Percentage " << tipPercentage << endl;
	cout << "Number of Large Pizzas " << largePizzas << endl;
	cout << "Number of Meduim Pizzas " << meduimPizzas << endl;
	cout << "Number of Small Pizzas " << smallPizzas << endl;
	cout << "Area (in) " << totalArea << endl;
	cout << "Area/Person (in) " << totalAreaPerPerson << endl;
	cout << "Cost ($) " << priceRounded << endl;

	system("PAUSE");
}