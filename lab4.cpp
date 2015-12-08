/*
Michael Matthews
Plinko Lab
Test Case 1:
MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2
*** DROP MULTIPLE CHIPS ***
Which slot do you want to drop the chips in (0-8): 8
How many chips do you want to put in? 1000
Total Winnings on 1000 chips: $1124000.00
Average winnings per chip: $1124.00

Test Case 2:
MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 1
*** DROP SINGLE CHIP ***
Which slot do you want to drop the chip in (0-8): 0
[0.0 0.5 1.0 0.5 1.0 1.5 1.0 1.5 1.0 1.5 2.0 1.5 2.0]
Winnings $1000.00

Test Case 3:
MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2
*** DROP MULTIPLE CHIPS ***
Which slot do you want to drop the chips in (0-8): 4
How many chips do you want to put in? 142
Total Winnings on 142 chips: $313000.00
Average winnings per chip: $2204.23
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main();
int menu(int input);

int main(){
	srand(time(0));
	int menuChoice;
	int userInput = 0;

	while (!(userInput == 1 || userInput == 2 || userInput == 3)){

		int userInput;
		cout << "MENU: Please select one of the following options:" << endl;
		cout << "	1 - Drop a single chip into one slot" << endl;
		cout << "	2 - Drop multiple chips into one slot" << endl;
		cout << "	3 - Quit the program" << endl;
		cout << "Enter your selection now: ";
		cin >> userInput;
		menuChoice = menu(userInput);
	}
	return 0;
}

int menu(int input){

	double slotChoice;
	double slotSelection;
	double slotSelections;
	double run;
	double sum = 0;
	int count = 0;

	while (input != 1 && input != 2 && input != 3){
		cout << "INVALID SELECTION.  Please enter 1, 2 or 3 " << endl;
		return 0;
	}

	if (input == 1){
		cout << "*** DROP SINGLE CHIP ***" << endl;
		cout << "Which slot do you want to drop the chip in (0-8): ";
		cin >> slotChoice;

		while (!(0 <= slotChoice && slotChoice <= 8)){
			cout << "INVALID SLOT." << endl;
			return 0;
		}
		
		cout << "[";
		cout << setprecision(1) << fixed << slotChoice << " ";

		sum = slotChoice;
		for (int $i = 0; $i < 12; $i++){

			double d2 = rand() % 2 + -.5;
			sum = sum + d2;
			if (sum <= 0){
				sum = sum + 1;
			}
			if (8 <= sum){
				sum = sum - 1;
			}
			cout << setprecision(1) << fixed << sum;

			if ($i < 11){
				cout << " ";
			}
			if (!($i < 11)){
				cout << "]";
			}
		}

		cout << endl;
		string zero = "$100.00";
		string one = "$500.00";
		string two = "$1000.00";
		string three = "$0.00";
		string four = "$10000.00";
		int endingSlot = sum;

		switch (endingSlot){
		case 0: cout << "Winnings " << zero; break;
		case 1: cout << "Winnings " << one; break;
		case 2: cout << "Winnings " << two; break;
		case 3: cout << "Winnings " << three; break;
		case 4: cout << "Winnings " << four; break;
		case 5: cout << "Winnings " << three; break;
		case 6: cout << "Winnings " << two; break;
		case 7: cout << "Winnings " << one; break;
		case 8: cout << "Winnings " << zero; break;
		}
		cout << endl;
		//system("PAUSE");
		return 0;

	}

	else if (input == 2) {
		int slotNumber;
		cout << "*** DROP MULTIPLE CHIPS ***" << endl;
		cout << "Which slot do you want to drop the chips in (0-8): ";
		cin >> slotNumber;

		while (!(0 <= slotNumber && slotNumber <= 8)){
			cout << "INVALID SLOT." << endl;
			return 0;
		}

		int howManyTimes;
		cout << "How many chips do you want to put in?: ";
		cin >> howManyTimes;

		while (howManyTimes <= 0){
			cout << "INVALID NUMBER OF CHIPS" << endl;
			return 0;
		}
		
		double runningTotal =0;
		int prize;
		int zero = 100;
		int one = 500;
		int two = 1000;
		int three = 0.00;
		int four = 10000;

		for (int $j = 0; $j < howManyTimes; $j++) {
			double sum = slotNumber;
			int count = 0;
			while (count < 12)
			{

				double d2 = rand() % 2 + -.5;
				sum = sum + d2;
				count++;
				if (sum <= 0){
					sum = sum + 1;
				}
				if (8 <= sum)
				{
					sum = sum - 1;
				}
				//cout << sum;
				//cout << " ";

			}
			
			int money = sum;

			switch (money)
			{
			case 0: prize = zero; break;
			case 1: prize = one; break;
			case 2: prize = two; break;
			case 3: prize = three; break;
			case 4: prize = four; break;
			case 5: prize = three; break;
			case 6: prize = two; break;
			case 7: prize = one; break;
			case 8: prize = zero; break;
			}

			if (!(prize == 0)){
				runningTotal = runningTotal + prize;
			}
		}

		double average = runningTotal / howManyTimes;

		cout << "Total Winnings on " << howManyTimes << " chips: " << "$";
		cout << setprecision(2) << fixed << runningTotal << endl;

		cout << "Average winnings per chip: " << "$";
		cout << setprecision(2) << fixed << average << endl;

		cout << endl;
		//system("PAUSE");	
		return 0;

	}

	else if (input == 3){
		cout << "GOODBYE" << endl;
		system("PAUSE");
		exit(0);
	}

	return 0;

}