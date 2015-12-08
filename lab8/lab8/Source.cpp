//Reference from the Help Session
//https://docs.google.com/document/d/1VMFN0zsC566IR0F486GdHpdw8VArTnQKTHqcYPgaHx4/edit?pli=1
/*
Michael Matthews
mjm287
Lab8

This lab is meant to help my crazy Uncle. It can add in external data, 
buy new cars, sell new cars, paint cars, etc.

Test Case 1: Expecting it to not let me add a car that is too expensive and not to let met add a car that is already in the vector

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 2

Current Balance: $10000.00

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 3

Please enter the name: Run
Please enter the color: Red
Please enter the price: 1000000
The car is too expensive
Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 3

Please enter the name: Jalopy
Please enter the color: Blue
Please enter the price: 1000
Car was added

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 3

Please enter the name: Jalopy
The car is already in the inventory

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 4

Please enter name of car to sell Jalopy
was removed

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 1

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice:

Test Case 2: Expecting it to load file. I am uncertain what it exactly does when I add a file that doesn't exist


Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 1


Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 6

File name:
Nothing.txt
File information added.

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 1


Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 2

Current Balance: $-9255963134931783000000000000000000000000000000000000000000000
0.00

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice:


Test Case Three: Make sure that the data is correctly doing the math when adding, subtracting, loading, etc

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 3

Please enter the name: Jalopy
Please enter the color: Blue
Please enter the price: 1000.89
The car was added.

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 1

Name: Jalopy
Color: Blue
Price: $1000.89


Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 2

Current Balance: $8999.11

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 6

File name: cars1.txt
File information added.

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 2

Current Balance: $9528.34

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 4

Please enter name of car to sell: Wrong
The Car was not found
Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 4

Please enter name of car to sell: Lemon
The car was removed.

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 2

Current Balance: $13755.33

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 5

Please enter name of car to paint: Jalopy
What color would you like: Red

The color and price were changed

Please enter one of the following:
1 - Show Current Inventory
2 - Show Current Balance
3 - Buy a Car
4 - Sell a Car
5 - Paint a Car
6 - Load File
7 - Save File
8 - Quit Program
Please enter in your choice: 2

Current Balance: $13755.33

*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cctype>

#include "Car.h"

using namespace std;

//this function gets a fileName and adds it to the vector and balance
int inputFile(vector<Car>& car_vector, double& balance){

	ifstream in_file;
	string file_name;
	cout << "File name: ";
	cin >> file_name;
	in_file.open(file_name);
	string name;
	string color;
	double price;
	double balanceAdd;
	in_file >> balanceAdd;

	balance = balance + balanceAdd;

	//TODO: add in something if the file is not found

	while (in_file >> name){
		
		in_file >> color >> price;
		Car added = Car(name, color, price);
		car_vector.push_back(added);
	}

	in_file.close();
	cout << "File information added. " << endl;
	

	return 0;
}

//this function goes through and finds if the car exists in the vector
int find(vector<Car>& car_vector, string CarName)
{

	for (int i = 0; i < car_vector.size(); i++)
	{
		if (car_vector[i].getName() == CarName)
		{
			return i;
		}
	}
	return -1;
}

//changes the color of a car into a new color
int paintCar(vector<Car>& car_vector){

	string car_name;
	cout << "Please enter name of car to paint: ";
	cin >> car_name;

	int location = find(car_vector, car_name);

	int notFound = -1;
	if (location == notFound){
		cout << "The car was not found.";
	}
	else{

		string new_color;
		cout << "What color would you like: ";
		cin >> new_color;
		car_vector[location].paint(new_color);
		cout << endl << "The color and price were changed " << endl;
	}
	
	return 0;
}

//this function will remove the car from the vector and will add price to balance
int sellCar(vector<Car>& car_vector, double& balance){

	string car_name;
	cout << "Please enter name of car to sell: ";
	cin >> car_name;

	int location = find(car_vector, car_name);

	int notFound = -1;
	if (location == notFound){
		cout << "The Car was not found";
	}
	else{

		double doubleAdd = car_vector[location].getPrice();
		balance = balance + doubleAdd;

		car_vector.erase(car_vector.begin() + location);
		cout << "The car was sold. " << endl;

	}

	
	return 0;
}

//this car is to add in a new car
int newCar(vector<Car>& car_vector, double& balance){
	string name;
	string color;
	double price;


	cout << "Please enter the name: ";
		cin >> name;

		double foundCar = find(car_vector, name);

		double no_car = -1;
		if (foundCar == no_car){

			cout << "Please enter the color: ";
			cin >> color;
			cout << "Please enter the price: ";
			cin >> price;
			
			if (price <= balance){

				Car newCar = Car(name, color, price);
				car_vector.push_back(newCar);
				balance = balance - price;
				cout << "The car was added. " << endl;
			}
			else{
				cout << "The car is too expensive. ";
			}
		}
		else{
			cout << "The car is already in the inventory. " << endl;
		}

		

	return 0;
}

//this function will display all the cars in the vector
int displayInventory(vector<Car>& car_vector){

	for (int i = 0; i < car_vector.size(); i++)
	{
		cout << car_vector[i].toString() << endl;
	}
	return 0;
}
//this function is used to output a file

int outputFile(vector<Car>& car_vector, double& balance){

	string filename;
	cout << "Enter the name of the file to be save: ";
	cin >> filename;
	ofstream out_file(filename);

	out_file << setprecision(2) << fixed << balance << endl;
	
	for (int i = 0; i < car_vector.size(); i++)
	{
		out_file << car_vector[i].getName() << " ";
		out_file << car_vector[i].getColor() << " ";
		out_file << car_vector[i].getPrice() << endl;
	}

	out_file.close();
	cout << "The file was saved. " << endl;

	return 0;
}


//gives the user the choice of what he would like to do
int main(){

	string input;
	int choice = 0;
	bool keepGoing = true;
	vector<Car> car_vector;
	double balance;
	balance = 10000;
	

	while (keepGoing == true){
		cout << endl;
		input = " ";
		choice = 0;
		cout << "Please enter one of the following: " << endl;
		cout << "1 - Show Current Inventory " << endl;
		cout << "2 - Show Current Balance " << endl;
		cout << "3 - Buy a Car " << endl;
		cout << "4 - Sell a Car " << endl;
		cout << "5 - Paint a Car " << endl;
		cout << "6 - Load File " << endl;
		cout << "7 - Save File " << endl;
		cout << "8 - Quit Program " << endl;
		cout << "Please enter in your choice: ";
		cin >> input;
		cout << endl;

		istringstream(input) >> choice;
		int notOption = 0;
		if (choice == notOption){
			cout << "INVALID CHOICE" << endl;
		}
		else{
			
			//Instance of class
			switch (choice){
			case 1: displayInventory(car_vector);
				break;
			case 2: cout << "Current Balance: $" <<setprecision(2) << fixed << balance << endl;
				break;
			case 3: newCar(car_vector, balance);
				break;
			case 4: sellCar(car_vector, balance);
				break;
			case 5: paintCar(car_vector);
				break;
			case 6: inputFile(car_vector, balance);
				break;
			case 7: outputFile(car_vector, balance);//save file prompts for file name and saves the current balance and inventory in that file
				break;
			case 8: exit(0);
				break;
			default: cout << "INVALID INPUT" << endl;
				break;
			}
		}

	}

	return 0;
}