/*
Michael Matthews
Restaurants
November Something

This program starts off with eight different restaurants. It then prompts the user to add or remove some. If the total number of 
restaurants is still a power of two, the user has the option of doing a tournament where each restaurant will be pit against another
until there is only one remaining.
 */

/*
Test Cases:

1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 1
McDonald's,Subway,Taco Bell,KFC,Chick-fil-A,Arby's,Jack in the Box,Cafe Rio

1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 4
1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 1
Arby's,Jack in the Box,McDonald's,Subway,Taco Bell,Chick-fil-A,Cafe Rio,KFC

1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 2
Enter a restaurant name: Test Restaurant
Test Restaurant was added to the vector.
1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 3
Enter a restaurant name to remove: Test
The restaurant indicated was not in the vector.
1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 3
Enter a restaurant name to remove: Test Restaurant
Test Restaurant was removed from the vector.
1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 2
Enter a restaurant name: Subway
This restaurant is already in the vector.
1 - Display all restaurants
2 - Add a restaurant
3 - Remove a restaurant
4 - Shuffle the vector
5 - Begin the tournament
6 - Quit the program
Make a choice 5
Match 1/4  Round 1/3
1: Arby's
2: KFC
Which restaurant do you prefer? 1
Match 2/4  Round 1/3
1: Jack in the Box
2: Cafe Rio
Which restaurant do you prefer? 1
Match 3/4  Round 1/3
1: McDonald's
2: Chick-fil-A
Which restaurant do you prefer? 2
Match 4/4  Round 1/3
1: Taco Bell
2: Chick-fil-A
Which restaurant do you prefer? 3
You must enter 1 or 2.
Match 4/4  Round 1/3
1: Taco Bell
2: Chick-fil-A
Which restaurant do you prefer? 1
Match 1/2  Round 2/3
1: Arby's
2: Taco Bell
Which restaurant do you prefer? 3
You must enter 1 or 2.
Match 1/2  Round 2/3
1: Arby's
2: Taco Bell
Which restaurant do you prefer? 1
Match 2/2  Round 2/3
1: Jack in the Box
2: Subway
Which restaurant do you prefer? 3
You must enter 1 or 2.
Match 2/2  Round 2/3
1: Jack in the Box
2: Subway
Which restaurant do you prefer? 2
Match 1/1  Round 3/3
1: Arby's
2: Subway
Which restaurant do you prefer? 3
You must enter 1 or 2.
Match 1/1  Round 3/3
1: Arby's
2: Subway
Which restaurant do you prefer? 3
You must enter 1 or 2.
Match 1/1  Round 3/3
1: Arby's
2: Subway
Which restaurant do you prefer? 2
The winner is: Subway
Press any key to continue . . .

*/

//including necessary libraries to run the code
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

//This function finds any restaurant in the vector. If the restaurant isn't in the vector than it returns a -1.
int findRestaurant(vector<string>& restaurants, string add_new_restaurant){

	//This function will go through and check each index to see if it is there or not. If it isn't there then it will never subtract anything from the test variable.
	//If at any point it is found it will subtract changeTest from test.
	int notThere = -1;
	int count = restaurants.size();
	int test = count;
	int changeTest = 1;

	for (int index = 0; index < count; index++){
		if (restaurants[index] == add_new_restaurant){
			return index;	
		}
		else {
			test = test - changeTest;
		}
	}

	int empty = 0;
	if (test == empty){

		return notThere;
	}

}

//This function simply shows all the restaurants in the vector restaurants
//count is set to the number of entries in restaurants
int showRestaurants(vector<string>& restaurants){

	//Go throughs each of the items in the vector and prints, unless it is the last one
	int count = restaurants.size();
	int lastOne = count - 1;
	
	for (int index = 0; index < count; index++){
		if (index == lastOne){
			cout << restaurants[index] << endl << endl;
		}
		else {
			cout << restaurants[index] << ",";
		}
	}

	return 0;
}

//This funciton adds a restaurant to the vector. If the restaurant is already in the vector then it lets you know that.
int addRestaurant(vector<string>& restaurants){

	cout << "Enter a restaurant name: ";
	string input;
	cin.sync();
	getline(cin, input);
	int unableTo = -1;
	
	int result = findRestaurant(restaurants, input);
	if (result == unableTo){
		restaurants.push_back(input);
		cout << input << " was added to the vector." << endl;
	}
	else{
		cout << "This restaurant is already in the vector. " << endl;
	}
	return 0;
}

//This function removes a restaurant from the vector. If the restaurant you requested for removal is not in the vector than you are told.
int removeRestaurant(vector<string>& restaurants){

	int unableTo = -1;
	cout << "Enter a restaurant name to remove: ";
	string input;
	cin.sync();
	getline(cin, input);

	int result = findRestaurant(restaurants, input);

	if (result == unableTo){
		cout << "The restaurant indicated was not in the vector. " << endl;
	}
	else{
		int goback = -1;
		int place = result;
		string previous = restaurants[place];

		restaurants.erase(restaurants.begin() + place);
		cout << previous << " was removed from the vector. " << endl;
	}

	return 0;

}

//This function will shuffle the Restaurant vector everytime you call it.
int shuffleRestaurant(vector<string>& restaurants){

	int size = restaurants.size();
	int plus = size;
	
	
	for (int run = 0; run < 1000; run++){
		
		int random1 = rand() % plus;
		int random2 = rand() % plus;
		
		string randomString = restaurants[random1];
		string randomString2 = restaurants[random2];

		restaurants[random1] = randomString2;
		restaurants[random2] = randomString;
	}
	cout << "The vector has been shuffled. " << endl;
	return 0;
}

//This function will ensure that you have enough contenders for the tournament
int powerOfTwo(int count){

	int divideTwo = 2;
	int whileZero = 0;
	int remainder = 1;

	while (((count % divideTwo) == whileZero) && count > remainder){
		count = count / divideTwo;
	}

	return count;
}

//This function will start the tournament until there is only one winner
int startTournament(vector<string>& restaurants){

	//the following are variables for the extra credit

	int howMany = restaurants.size();
	int howManyCopy = howMany;
	int matchups = 2;
	int totalRounds = 0;
	int remainder = 1;

	while (howManyCopy != remainder){
		totalRounds++;
		howManyCopy = howManyCopy / matchups;
	}
	
	int dontStop = 0;
	int stop = 1;
	int endTournament = dontStop;
	int count = restaurants.size();
	int check = powerOfTwo(count);
	int isPow = 1;

	if (check != isPow){
		cout << "The Tournament may not begin until it is a power of two " << endl;
	}
	else {

		int trackRound = 0;
		
		while (check == isPow){
			
			int leftside = count - count;
			int rightside = count - 1;
			int start = 0;
			int keep_going = 1;
			int size_of_array = restaurants.size();
			int eachMatch = 2;
			int totalMatches = size_of_array / eachMatch;
			int matchRound = 1;
			
			trackRound++;

			while (start != keep_going){

			vector<string> copy = restaurants;
			//go a round
				int choice1 = 1;
				int choice2 = 2;

				int choice;
				int wrong = 3;
				int keepgoing = 3;
				int stop = 1;
				int goAlong = 3;
						

					while (keepgoing == goAlong){

						string choiceString;
						int noString = 0;
						int notOption = 0;

						cout << "Match " << matchRound << "/" << totalMatches << "  ";
						cout << "Round " << trackRound << "/" << totalRounds << "  " << endl;
						cout << "1: " << copy[leftside] << endl;
						cout << "2: " << copy[rightside] << endl;
						cout << "Which restaurant do you prefer? ";
						cin >> choiceString;

						istringstream(choiceString) >> noString;
						choice = noString;

						if (noString == notOption){
							cout << "INVALID CHOICE.  ";
						}

						if (noString == choice1 || choice == choice2){

							keepgoing = stop;
						}
						else{
							cout << "You must enter 1 or 2. " << endl;
							keepgoing = wrong;

						}
					
					}

				if (choice == choice1){
					restaurants.erase(restaurants.begin() + rightside);
				}
				else if (choice == choice2){
					restaurants.erase(restaurants.begin() + leftside);
				}

				matchRound++;
				int next = 1;
				leftside = leftside + next;
				rightside = rightside - next;

				int newsize = restaurants.size();
		
				int winner = 1;

				if (leftside > rightside){
					keep_going = start;
				}

				if (newsize == winner){
					endTournament = stop;
				}
				
			}
		
			count = restaurants.size();
			check = powerOfTwo(count);
			if (endTournament == stop){
				isPow = 2;
			}
			else {
				isPow = 1;
			}
		}

	}

	int checksize = 1;
	int finalsize = restaurants.size();
	if (checksize == finalsize){
		cout << "The winner is: " << restaurants[0] << endl;
		system("PAUSE");
		exit(0);
	}

return 0;

}

//This function gives you the intial options of what to do
//Here in the main funcion is where you have the first 8 restaurants added into the 
//the vector restaurants. 
int main(){

	srand(time(0));
	string keepGoing = "yes";

	//putting Values into vector

	vector<string> restaurants;

	restaurants.push_back("McDonald's");
	restaurants.push_back("Subway");
	restaurants.push_back("Taco Bell");
	restaurants.push_back("KFC");
	restaurants.push_back("Chick-fil-A");
	restaurants.push_back("Arby's");
	restaurants.push_back("Jack in the Box");
	restaurants.push_back("Cafe Rio");


	while (keepGoing == "yes"){

		string choiceString;
		int choice = 0;

		cout << "1 - Display all restaurants" << endl;
		cout << "2 - Add a restaurant" << endl;
		cout << "3 - Remove a restaurant" << endl;
		cout << "4 - Shuffle the vector" << endl;
		cout << "5 - Begin the tournament" << endl;
		cout << "6 - Quit the program" << endl;
		cout << "Make a choice: ";
		cin >> choiceString;

		istringstream(choiceString) >> choice;

		int notOption = 0;
		if(choice == notOption){
			cout << "INVALID CHOICE" << endl;
		}
		else {

			switch (choice){
			case 1: showRestaurants(restaurants);
				break;
			case 2: addRestaurant(restaurants);
				break;
			case 3: removeRestaurant(restaurants);
				break;
			case 4: shuffleRestaurant(restaurants);
				break;
			case 5:  startTournament(restaurants);
				break;
			case 6: exit(0);
			}
		}
	}

	return 0;
}