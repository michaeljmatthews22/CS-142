//Michael Matthews
//Lab 3T

/*
Test Cases (Anticipated/Actual i.e. (5.55/5.56))

	Test 1:
		Anticipated Outcome/Actual Outcome

		Miles per year: 300
		Price of gallon of gas: 3.89
		Intial Cost hybrid: 15000
		Efficiency of hybrid: 30
		Resale hybrid: 10000
		Intial Cost non-hybrid: 8000
		Efficiency of non-hybid:15
		Resale non-hybrid: 5000
		Buyer's Criterion: Gas

		Car: Hybrid
		Gallons: 50/50
		Cost: 5194.5/5194.5

		Car: Non-Hybrid
		Gallons: 100/100
		Cost: 3389/3389

		Math = (MPY / efficiency)
Math = (MPY / efficiency) * priceGas + (intial - resale)
	
	Test 2:
		Anticipated Outcome/Actual Outcome

		Miles per year: 50000
		Price of gallon of gas: 4.56
		Intial Cost hybrid: 25000
		Efficiency of hybrid: 30
		Resale hybrid: 15000
		Intial Cost non-hybrid: 15000
		Efficiency of non-hybid:13
		Resale non-hybrid: 10000
		Buyer's Criterion: Total

		Car: Hybrid
		Gallons: 8333.33/8333.33
		Cost: 48000/48000

		Car:Non-Hybrid
		Gallons: 19230.8/19230.8
		Cost: 92692.3/92692.3

	Test 3:
		Anticipated Outcome/Actual Outcome

		Miles per year: 35
		Price of gallon of gas: 1.25
		Intial Cost hybrid: 5000
		Efficiency of hybrid: 45
		Resale hybrid: 4999
		Intial Cost non-hybrid: 2500
		Efficiency of non-hybid: 24
		Resale non-hybrid: 2499
		Buyer's Criterion: Total

		Car: Hybrid
		Gallons: 3.88889/3.88889
		Cost: 5.86111/5.86111

		Car: Non-Hybrid
		Gallons: 7.29167/7.29167
		Cost: 10.1146/10.1146

*/


#include <iostream>
#include <string>

using namespace std;

int main(){

double mpy;
double gallonPrice;
double intialCost;
double efficiency;
double resale;
double intialCostNon;
double efficiencyNon;
double resaleNon;
string criterion;

cout << "The estimated miles driven per year: ";
cin >> mpy; 
if (mpy <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> mpy; 
}
cout << "The estimated price of a gallon of gas during the 5 years of ownership: ";
cin >> gallonPrice;
if (gallonPrice <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> gallonPrice; 
}
cout << "The initial cost of a hybrid car: ";
cin >> intialCost;
if (intialCost <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> intialCost; 
}

cout << "The efficiency of the hybrid car in miles per gallon: ";
cin >> efficiency;
if (efficiency <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> efficiency; 
}

cout << "The estimated resale value (a dollar amount) for a hybrid after 5 years: ";
cin >> resale;
if (resale <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> resale; 
}

cout << "The initial cost of a non-hybrid car: ";
cin >> intialCostNon;
if (intialCostNon <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> intialCostNon; 
}
cout << "The efficiency of the non-hybrid car in miles per gallon: ";
cin >> efficiencyNon;
if (efficiencyNon <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> efficiencyNon; 
}

cout << "The estimated resale value (a dollar amount) for a non-hybrid after 5 years: ";
cin >> resaleNon;
if (resaleNon <= 0){
	cout <<"Please reenter the data with a positive number." << endl;
	cout << "The estimated miles driven per year: ";
	cin >> resaleNon; 
}

cout << "What is your criterion, either  minimized 'Gas' consumption or minimized 'Total' cost: ";
cin >> criterion;


// Logic of deciding which car should be bought

double mpy5 = mpy * 5;

double consumptionHybrid = mpy5 / efficiency;
double consumptionNon = mpy5 / efficiencyNon;

double costGasHybrid = consumptionHybrid * gallonPrice;
double costGasNon = consumptionNon * gallonPrice;

double totalCostHybrid = costGasHybrid + intialCost;
double totalCostNon = costGasNon + intialCostNon;

double depreciationHybrid = intialCost - resale;
double depreciationNon = intialCostNon - resaleNon;

//by adding these two numbers together we determine that whichever number is higher will determine 
//which car should be bought.  A high depreciation value signfies money lost

double allHybrid = costGasHybrid + depreciationHybrid;
double allNon = costGasNon + depreciationNon;


if (criterion == "Gas"){
if ((consumptionHybrid - consumptionNon) == 0 ){
//They have the same
cout << "They have the same gas consumption" << endl;
cout << "Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionHybrid << endl;
cout << "Total cost of owning the car for 5 years: " << allHybrid << endl;
cout << "Non-Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionNon << endl;
cout << "Total cost of owning the car for 5 years: " << allNon << endl;
} 
else if ((consumptionNon - consumptionHybrid) > 0){
//Hybrid uses less gas
cout << "Hybrid" << endl; 
cout << "Total gallons of fuel consumed: " << consumptionHybrid << endl;
cout << "Total cost of owning the car for 5 years: " << allHybrid << endl;
cout << "Non-Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionNon << endl;
cout << "Total cost of owning the car for 5 years: " << allNon << endl;
} 
else {
//Non uses less gas
cout << "Non-Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionNon << endl;
cout << "Total cost of owning the car for 5 years: " << allNon << endl;
cout << "Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionHybrid << endl;
cout << "Total cost of owning the car for 5 years: " << allHybrid << endl << endl;

}

}
else if (criterion == "Total") {
if ((allHybrid - allNon) == 0){
//They are the same
cout << "They have the same total cost" << endl;
cout << "Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionHybrid << endl;
cout << "Total cost of owning the car for 5 years: " << allHybrid << endl;
cout << "Non-Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionNon << endl;
cout << "Total cost of owning the car for 5 years: " << allNon << endl;
}
else if ((allNon - allHybrid) > 0){
//Hybrid has a lower total cost
cout << "Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionHybrid << endl;
cout << "Total cost of owning the car for 5 years: " << allHybrid << endl;
cout << "Non-Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionNon << endl;
cout << "Total cost of owning the car for 5 years: " << allNon << endl;
}
else {
//Non has a lower total cost
cout << "Non-Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionNon << endl;
cout << "Total cost of owning the car for 5 years: " << allNon << endl;
cout << "Hybrid" << endl;
cout << "Total gallons of fuel consumed: " << consumptionHybrid << endl;
cout << "Total cost of owning the car for 5 years: " << allHybrid << endl << endl;

}

}



system("PAUSE");


return 0;
}