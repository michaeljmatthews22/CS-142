/*
Michael Matthews
Plinko Lab with Functions
Michael Matthews

This program is creating a Plinko game. The user is asked to choose whether or not he wants to put in one chip,
multiple chips in the same slot, or multiple chips in every slot.  (Or they can quit the program) 
If they choose one chip, it outputs the path of the chip and the ending slot.  It then computes the total winnings on 
one chip.
If they choose multiple chips, it doesn't show the path, however, it does show the total winnings and the average per chip.
If they choose multiple chips in every slot, it also doesn't show the path, however, it shows the total winnings for EACH slot and 
the average winnings for EACH slot.  It doesn't show the total winnings overall. See the test cases below


Test Cases

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop chips into all slots
4 - Quit the program
Enter your selection now: 1
*** DROP SINGLE CHIP ***
Which slot do you want to drop the chip in (0-8): 4
[4.0 4.5 4.0 4.5 5.0 4.5 4.0 3.5 4.0 4.5 5.0 5.5 6.0]
Winnings $1000.00

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop chips into all slots
4 - Quit the program
Enter your selection now: 2
*** DROP MULTIPLE CHIPS ***
Which slot do you want to drop the chips in (0-8): 4
How many chips do you want to put in?: 100
Total Winnings on 100 chips: $236000.00
Average winnings per chip: $2360.00

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop chips into all slots
4 - Quit the program
Enter your selection now: 3
How many chips do you want to put in?: 10000

Total winnings on slot:   0 $11181500.00
Average winnings on slot: 0 $1118.15
Total winnings on slot:   1 $12694500.00
Average winnings on slot: 1 $1269.45
Total winnings on slot:   2 $16632000.00
Average winnings on slot: 2 $1663.20
Total winnings on slot:   3 $22880000.00
Average winnings on slot: 3 $2288.00
Total winnings on slot:   4 $25777500.00
Average winnings on slot: 4 $2577.75
Total winnings on slot:   5 $22359000.00
Average winnings on slot: 5 $2235.90
Total winnings on slot:   6 $17092500.00
Average winnings on slot: 6 $1709.25
Total winnings on slot:   7 $12309500.00
Average winnings on slot: 7 $1230.95
Total winnings on slot:   8 $11325500.00
Average winnings on slot: 8 $1132.55
Total winnings on slot:   9 $10454500.00
Average winnings on slot: 9 $1045.45

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop chips into all slots
4 - Quit the program
Enter your selection now: 4
GOODBYE

*/

//including the libraries for the program
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//Setting forth the different functions of the program

int main();
int option1(int choice);
int option2or3(int twoOrThree);

//These functions are used by all three options
int oneChipFalling(double slotNumber, int theMenuChoice);
int multiple(double slotNumber, double howManyTimes);
int calculateWinning(double endingSlot);

//main function presents the menu and then uses switch to determine which other functions to call
int main(){

	//setting forth random time
	srand(time(0));
	int menuChoice;
	int userInput = 0;

	//creating loop that will not let someone get past unless they put an integer of 1,2,3 or 4
	while (!(userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4)){
		//I need to redeclare userInput inside here, otherwise return 0 doesn't work correctly
		int userInput;
		string userInputString;
		cout << "MENU: Please select one of the following options:" << endl;
		cout << "1 - Drop a single chip into one slot" << endl;
		cout << "2 - Drop multiple chips into one slot" << endl;
		cout << "3 - Drop chips into all slots" << endl;
		cout << "4 - Quit the program" << endl;
		cout << "Enter your selection now: ";
		cin >> userInputString;

		//This is to verify whether or not it is a string.  If it can't convert
		//it to an int then it will fail. 
		istringstream(userInputString) >> userInput;

		switch (userInput){
		case 1: menuChoice = option1(userInput); break;
		case 2: case 3: menuChoice = option2or3(userInput); break;
		case 4: cout << "GOODBYE" << endl; /*system("PAUSE");*/ exit(0); break;
		default: cout << "INVALID Menu Choice " << endl; userInput = 0; break;
		}

	}

	return 0;
}

//If the user choose number 1, i.e. single chip
int option1(int choice){
	//setting it forth as an int and a string.  String is then converted to int
	int slotChoice;
	string slotChoiceString;
	cout << "*** DROP SINGLE CHIP ***" << endl;
	cout << "Which slot do you want to drop the chip in (0-8): ";
	cin >> slotChoiceString;
	//conversion
	istringstream(slotChoiceString) >> slotChoice;
	//if the string is "0" and the int is 0, then the slot is 0.  If the string is not "0" and the int is 0, it fails. Because it takes a string
	//and converts it to a int, it automatically converts it to a 0. Therefore it is necessary to still make sure the string is a "0".  I.E.
	//input = "potatoe"
	//conversion int = 0
	//input = "0"
	//conversion int = 0
	//Therefore need to make sure both are zero

	if (slotChoiceString != "0" && slotChoice == 0){
		cout << "INVALID SLOT." << endl;
		return 0;
	}

	//creating loop to make sure that it isn't outside the bounds
	while (!(0 <= slotChoice && slotChoice <= 8)) {
		cout << "INVALID SLOT." << endl;
		return 0;
	}

	int menuChoice = 1;
	//sending the endingslot to the oneChipFalling with the original menuChoice
	double endingSlotForOne = oneChipFalling(slotChoice, menuChoice);
	//calculate the total winnings
	double total = calculateWinning(endingSlotForOne);
	cout << "Winnings $";
	cout << setprecision(2) << fixed << total << endl << endl;

	return 0;

}

//this is if there are multiple chips dropped into either all slots, or just one
int option2or3(int twoOrThree){
	int slotNumber;

	if (twoOrThree == 2){

		string slotNumberString;
		cout << "*** DROP MULTIPLE CHIPS ***" << endl;
		cout << "Which slot do you want to drop the chips in (0-8): ";
		cin >> slotNumberString;
		//doing conversion from string to int.
		istringstream(slotNumberString) >> slotNumber;

		//if the string is "0" and the int is 0, then the slot is 0.  If the string is not "0" and the int is 0, it fails. Because it takes a string
		//and converts it to a int, it automatically converts it to a 0. Therefore it is necessary to still make sure the string is a "0".  I.E.
		//input = "potatoe"
		//conversion int = 0
		//input = "0"
		//conversion int = 0
		//Therefore need to make sure both are zero

		if (slotNumber == 0 && slotNumberString != "0"){
			cout << "INVALID SLOT." << endl;
			return 0;

		}
		//if it is outside 0 and 8 then it will not work
		while (!(0 <= slotNumber && slotNumber <= 8)){
			cout << "INVALID SLOT." << endl;
			return 0;
		}
	}
	
	//seeing howManyTime is wants to be put in
	int howManyTimes;
	string howManyTimesString;
	cout << "How many chips do you want to put in?: ";
	cin >> howManyTimesString;

	istringstream(howManyTimesString) >> howManyTimes;
	double callMultiple;
	//You have to choose an positive int. (0 is nonpositive in this context)
	while (howManyTimes <= 0){
		cout << "INVALID NUMBER OF CHIPS" << endl;
		return 0;
	}


	if (twoOrThree == 2){
		//calling the multiple function to calculate ending slots
		callMultiple = multiple(slotNumber, howManyTimes);
		//setting forth the average
		double average = callMultiple / howManyTimes;
		cout << "Total Winnings on " << howManyTimes << " chips: " << "$";
		cout << setprecision(2) << fixed << callMultiple << endl;
		cout << "Average winnings per chip: " << "$";
		cout << setprecision(2) << fixed << average << endl << endl;

	}
	else{ //this case if it is 3, i.e. many chips into each slot
		cout << endl;
		//i represents the slot number
		for (int i = 0; i <= 8; i++){
			double sum;
			sum = i;
			//calling the multiple function and each time passing in a different slot number
			callMultiple = multiple(i, howManyTimes);
			cout << "Total winnings on slot:   " << i << " $";
			cout << setprecision(2) << fixed << callMultiple << endl;
			cout << "Average winnings on slot: " << i << " $";
			double average = callMultiple / howManyTimes;
			cout << setprecision(2) << fixed << average << endl;
		}
		cout << endl;
	}


	return 0;

}

//this function calculates the chip falling multiple times. It calls the singleChipFalling.  It calls the caculateWinning function as well
int multiple(double slotNumber, double howManyTimes){
	//setting forth variables used withinfunction
	double total = 0;
	double sum = slotNumber;
	double winnings;
	int originalChoice = 0;
	//this for loop runs the chipFalling for as many times as the user wanted.  It returns total

	for (int j = 0; j < howManyTimes; j++) {

		double chipFalling = oneChipFalling(sum, originalChoice);
		winnings = calculateWinning(chipFalling);

		total = winnings + total;

	}

	return total;

}

//this calculates one chip falling.  This is called by multiple.  It does not call another function
int oneChipFalling(double slotNumber, int theMenuChoice){
	//if the chip is just one it will output the [] with the slot and its path, ending with the last slot and winning

	if (theMenuChoice == 1){

		cout << "[";
		cout << setprecision(1) << fixed << slotNumber << " ";
	}
	double sum = slotNumber;
	int count = 0;
	while (count < 12){
		//using random number each time it encounters a slot
		double d2 = rand() % 2 + -.5;
		sum = sum + d2;
		count++;

		if (sum < 0){
			sum = sum + 1;
		}
		if (8 < sum){
			sum = sum - 1;
		}
		//formating if the orginal choice was a single chip
		if (theMenuChoice == 1){
			cout << setprecision(1) << fixed << sum;

			if (count < 12){
				cout << " ";
			}
			if (!(count < 12)){
				cout << "]" << endl;
			}
		}

	}

	return sum;

}

//calculating winnings for each slot.  Returns running total
int calculateWinning(double endingSlot){
	//setting forth winnings.  Slot 5 is prize 3, slot 6, prize two, etc. (i.e. it peaks at 4 and then goes back down, being symmetrical)
	double runningTotal = 0;
	int prize;
	int zero = 100;
	int one = 500;
	int two = 1000;
	int three = 0.00;
	int four = 10000;
	int money = endingSlot;

	//if ending slot is 0-8, the corresponding price $ is added to runningTotal
	switch (money){
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

	return runningTotal;

}

























