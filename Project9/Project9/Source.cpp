/*
Michael Matthews
Student ID: 114257311
CS 142 Fall 2015 Midterm 1 Exam

This code is designed to help you calculate whether or not you should switch phone plans.
You will be able to see within the first 12 months what is the cost if you 
	A) Stayed on your current plan
	B) Switched to a new plan

It will prompt you, please put in accurate information.

Below are three test cases. 
The first shows what it would be if the NEW plan was cheaper
The second shows what it would be if the CURRENT plan was cheaper
The third shows what it woudl be if it was the SAME


Test Case 1 (New Plan) :
What is the monthly charge for your current plan? 100
What is the charge to drop your current plan? 200
How much can you sell your current phone for? 50

What is the monthly charge on the new plan? 50
What is the cost of the phone on the new plan? 200
For month 1:
Current plan cumulative cost: 100
New plan cumulative cost: 400
The cumulative cost of the CURRENT plan is less.

For month 2:
Current plan cumulative cost: 200
New plan cumulative cost: 450
The cumulative cost of the CURRENT plan is less.

For month 3:
Current plan cumulative cost: 300
New plan cumulative cost: 500
The cumulative cost of the CURRENT plan is less.

For month 4:
Current plan cumulative cost: 400
New plan cumulative cost: 550
The cumulative cost of the CURRENT plan is less.

For month 5:
Current plan cumulative cost: 500
New plan cumulative cost: 600
The cumulative cost of the CURRENT plan is less.

For month 6:
Current plan cumulative cost: 600
New plan cumulative cost: 650
The cumulative cost of the CURRENT plan is less.

For month 7:
Current plan cumulative cost: 700
New plan cumulative cost: 700
Both plans have the SAME cumulative cost.

For month 8:
Current plan cumulative cost: 800
New plan cumulative cost: 750
The cumulative cost of the NEW plan is less.

For month 9:
Current plan cumulative cost: 900
New plan cumulative cost: 800
The cumulative cost of the NEW plan is less.

For month 10:
Current plan cumulative cost: 1000
New plan cumulative cost: 850
The cumulative cost of the NEW plan is less.


For month 11:
Current plan cumulative cost: 1100
New plan cumulative cost: 900
The cumulative cost of the NEW plan is less.


For month 12:
Current plan cumulative cost: 1200
New plan cumulative cost: 950
The cumulative cost of the NEW plan is less.

** The new plan was first cheaper in the month of 8.


Test Case 2 (current plan):
What is the monthly charge for your current plan? 10
What is the charge to drop your current plan? 100
How much can you sell your current phone for? 5

What is the monthly charge on the new plan? 10
What is the cost of the phone on the new plan? 10
For month 1:
Current plan cumulative cost: 10
New plan cumulative cost: 115
The cumulative cost of the CURRENT plan is less.

For month 2:
Current plan cumulative cost: 20
New plan cumulative cost: 125
The cumulative cost of the CURRENT plan is less.

For month 3:
Current plan cumulative cost: 30
New plan cumulative cost: 135
The cumulative cost of the CURRENT plan is less.

For month 4:
Current plan cumulative cost: 40
New plan cumulative cost: 145
The cumulative cost of the CURRENT plan is less.

For month 5:
Current plan cumulative cost: 50
New plan cumulative cost: 155
The cumulative cost of the CURRENT plan is less.

For month 6:
Current plan cumulative cost: 60
New plan cumulative cost: 165
The cumulative cost of the CURRENT plan is less.

For month 7:
Current plan cumulative cost: 70
New plan cumulative cost: 175
The cumulative cost of the CURRENT plan is less.

For month 8:
Current plan cumulative cost: 80
New plan cumulative cost: 185
The cumulative cost of the CURRENT plan is less.

For month 9:
Current plan cumulative cost: 90
New plan cumulative cost: 195
The cumulative cost of the CURRENT plan is less.

For month 10:
Current plan cumulative cost: 100
New plan cumulative cost: 205
The cumulative cost of the CURRENT plan is less.

For month 11:
Current plan cumulative cost: 110
New plan cumulative cost: 215
The cumulative cost of the CURRENT plan is less.

For month 12:
Current plan cumulative cost: 120
New plan cumulative cost: 225
The cumulative cost of the CURRENT plan is less.
** The new plan was never cheaper.


Test Case 3 (TIE):

What is the monthly charge for your current plan? 100
What is the charge to drop your current plan? 0
How much can you sell your current phone for? 100

What is the monthly charge on the new plan? 100
What is the cost of the phone on the new plan? 100

For month 1:
Current plan cumulative cost: 100
New plan cumulative cost: 100
Both plans have the SAME cumulative cost.

For month 2:
Current plan cumulative cost: 200
New plan cumulative cost: 200
Both plans have the SAME cumulative cost.

For month 3:
Current plan cumulative cost: 300
New plan cumulative cost: 300
Both plans have the SAME cumulative cost.

For month 4:
Current plan cumulative cost: 400
New plan cumulative cost: 400
Both plans have the SAME cumulative cost.

For month 5:
Current plan cumulative cost: 500
New plan cumulative cost: 500
Both plans have the SAME cumulative cost.

For month 6:
Current plan cumulative cost: 600
New plan cumulative cost: 600
Both plans have the SAME cumulative cost.

For month 7:
Current plan cumulative cost: 700
New plan cumulative cost: 700
Both plans have the SAME cumulative cost.

For month 8:
Current plan cumulative cost: 800
New plan cumulative cost: 800
Both plans have the SAME cumulative cost.

For month 9:
Current plan cumulative cost: 900
New plan cumulative cost: 900
Both plans have the SAME cumulative cost.

For month 10:
Current plan cumulative cost: 1000
New plan cumulative cost: 1000
Both plans have the SAME cumulative cost.

For month 11:
Current plan cumulative cost: 1100
New plan cumulative cost: 1100
Both plans have the SAME cumulative cost.

For month 12:
Current plan cumulative cost: 1200
New plan cumulative cost: 1200
Both plans have the SAME cumulative cost.
** The plans ended up being the same.


*/

#include <iostream>
#include <string>
using namespace std;

int main();


int main(){
	//setting forth the month it became cheaper outside of the while loop so it doesn't reset to 0
	double becameCheaper = 0;

	//Setting forth current plan
	double chargeCurrent;
	cout << "What is the monthly charge for your current plan? ";
	cin >> chargeCurrent;

	//Setting forth the cost to switch
	double chargeToDrop;
	cout << "What is the charge to drop your current plan? ";
	cin >> chargeToDrop;

	double sellFor;
	cout << "How much can you sell your current phone for? ";
	cin >> sellFor;

	cout << endl;

	//Setting for the cost of the new plan
	double chargeNew;
	cout << "What is the monthly charge on the new plan? ";
	cin >> chargeNew;

	double costNewPhone;
	cout << "What is the cost of the phone on the new plan? ";
	cin >> costNewPhone;

	//starting running total at 0
	double totalChargeCurrent = 0;
	double totalChargeNew = 0;

	//This is the main logic of the script.  It goes through and does the math 12 times.  Start $i at 1 so we can print it out as the month
	for (int $i = 1; $i <= 12; $i++){
		
		//runningTotal of the current plan
		totalChargeCurrent = totalChargeCurrent + chargeCurrent;
		cout << "For month " << $i << ":" << endl;
		cout << "\t" << "Current plan cumulative cost: " << totalChargeCurrent << endl;

		//This if statement is for the first time through only.  He won't have these costs again
		if ($i < 2) {

			double switchCost;
			switchCost = totalChargeNew + costNewPhone + chargeToDrop;
			totalChargeNew = switchCost - sellFor;
			
		}

		//Going through the math of the new plan, after intial fees
		totalChargeNew = totalChargeNew + chargeNew;
		cout << "\t" << "New plan cumulative cost: " << totalChargeNew << endl;
		
		if (totalChargeCurrent < totalChargeNew){

			cout << "\t" << "The cumulative cost of the CURRENT plan is less. " << endl;
			if ($i == 12){
				//If it is on it's last month it'll print out the last line. 
				cout << "** The new plan was never cheaper." << endl;
			}
		} 

		else if (totalChargeCurrent == totalChargeNew){
			cout << "\t" << "Both plans have the SAME cumulative cost. " << endl;
			if ($i == 12){
				//If it is on it's last month it'll print out the last line. 
				cout << "** The plans ended up being the same." << endl;
			}
		}
		
		
		else if (!(totalChargeCurrent < totalChargeNew)){

			cout << "\t" << "The cumulative cost of the NEW plan is less." << endl << endl;
			const string FINALLINE = "** The new plan was first cheaper in the month of ";
		
			//this sets forth the month it became cheaper
			if(becameCheaper <= 0){

				becameCheaper = $i;
		
			}
			//If it is on it's last month it'll print out the last line. 
			if ($i == 12){

				cout << FINALLINE << becameCheaper << ".";
			}
		}
		cout << endl;
			
	}

	system("PAUSE");
	return 0;
}