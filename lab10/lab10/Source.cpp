//TODO
/*

TEST CASE 1:

Test Case file contents
Residential 0 700000 1 235 Death Valley
Residentially 98000 1 .05 George Washington Bld.
Commercial 1 650000 0 897 Valley Hills
Jimmy Johns 4 49990 1

Residential 1 900000 1 240 Next Year Rd.

TEST CASE 2:
Residential 1 690000 1 400 Elvis Presley Lane
Commercial -1 780000 0 589 Kelly Vaughn Late
Residential 0 Maybe 1 998 Red White and Blue
Residential 1 200000 0 900 Pele Pele Way
Commercial 1 6667777 1 .99 2301 Yellow Street
Commercial 1 4899932001829 0 984 Abbey Road

TEST CASE 3:
Residential 1 400000 0 435 Lake Creek Road
Residentail 10 200000 testthis 689 Coyote Gulch
Maybe Not
Commercial 0 50000000 0 .9 657 Claude Monet Drive
Commercial 1 123456678 0 12 Van Gough Terrace
Residential If you like Pinacolda Street


make sure that you can set precision on the output

Michael Matthews
mjm287
Lab 10

This lab will compute the taxes for address given whether they are residential or commercial. 

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

using namespace std;
#include "Commercial.h"
#include "Residential.h"
#include "Property.h"

//this function will print all of the data to the screen for both information of valid properities and tax information
void printList(vector<Property*> allData)
{
	cout << endl << endl;
	cout << "All valid properities: " << endl;
	for (int i = 0; i < allData.size(); i++)
	{
		cout << allData[i]->toString() << endl;
	}
	cout << endl << endl;
	cout << "NOW PRINTING TAX REPORT: " << endl;
	for (int i = 0; i < allData.size(); i++)
	{
		cout << "**Taxes due at the property at: " << allData[i]->getAddress() << endl;
		cout << "\t" << "Property id: " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << allData[i]->getId() << endl;
		cout << "\t" << "This property has an estimated value of " << "\t" << "\t" << allData[i]->getValue() << endl;
		cout << "\t" << "TaxesDue: " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << fixed << setprecision(2) << allData[i]->calculateTaxes() << endl;
		
	}

}

//Here in the main the user will be prompted for a txt file to take the data from. If they enter in a wrong file then it will not work. However, if it does, it will read line by line unless there is
//an error and will compute the taxes for each property
int main(){
	
	vector<Property*> allData;
	
	ifstream in_file;
	string file_name;
	stringstream file;
	cout << "Where should I read the data from? ";
	cin >> file_name;

	in_file.open(file_name);

	if (in_file.is_open()){

		string address;
		string type;
		bool rental;
		double value;
		bool occupied;
		double discount;
		bool hasDiscount;
		double taxrate;
		bool ignore;
		bool alreadyIgnored;
		taxrate = 0;
		int rentalCheck;
		int occupiedCheck;
		int discountCheck;

		string line;
		string previousAddress;
		
		while (getline(in_file, line)){

			alreadyIgnored = false;
			stringstream ss;
			ss << line;
			ss >> type;

			if (type == "Residential"){		
				
				ss >> rentalCheck;

				if (ss.fail()){
					if (alreadyIgnored == false){
						cout << "Ignoring bad RESIDENTIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}

				if (rentalCheck == 1 || rentalCheck == 0){
					
					ignore = false;
				}
				else{
					if (alreadyIgnored == false){
						cout << "Ignoring bad RESIDENTIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}

				rental = rentalCheck;
				ss >> value;
				if (ss.fail()){
					if (alreadyIgnored == false){
						cout << "Ignoring bad RESIDENTIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}

				
				ss >> occupiedCheck;

				if (occupiedCheck == 1 || occupiedCheck == 0){

					ignore = false;
				}
				else{
					if (alreadyIgnored == false){
						cout << "Ignoring bad RESIDENTIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}

				occupied = occupiedCheck;
				

				getline(ss, address);


				
				if (previousAddress != address){
					if (ignore == false){
						Property* new_Residential = new Residential(type, rental, value, occupied, address);
						allData.push_back(new_Residential);
					}
					previousAddress = address;
				}
				
			}
			else if (type == "Commercial"){
				
				
				ss >> rentalCheck;

				if (rentalCheck == 1 || rentalCheck == 0){

					ignore = false;
				}
				else{
					if (alreadyIgnored == false){
						cout << "Ignoring bad COMMERCIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}

				rental = rentalCheck;

				ss >> value;

				if (ss.fail()){
					if (alreadyIgnored == false){
						cout << "Ignoring bad COMMERCIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}


				ss >> discountCheck;

				if (discountCheck == 1 || discountCheck == 0){

					ignore = false;
				}
				else{
					if (alreadyIgnored == false){
						cout << "Ignoring bad COMMERCIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}

				hasDiscount = discountCheck;
				
				ss >> discount;
				if (ss.fail()){
					if (alreadyIgnored == false){
						cout << "Ignoring bad COMMERCIAL in input file: " << line << endl;
						ignore = true;
						alreadyIgnored = true;
					}
				}

				getline(ss, address);
				
				if (address != previousAddress){
					if (ignore == false){
						Property* new_Commercial = new Commercial(type, rental, value, hasDiscount, discount, address);
						allData.push_back(new_Commercial);

					}
					previousAddress = address;
				}

			}
			else{

				cout << "Ignoring unknown types of properties appearing in the input file: " << line << endl;
			}
		}


		printList(allData);
		in_file.close();

	}

	else{
		cout << "Error! Please enter in valid file next time. Quitting " << endl;
	}

	
	system("Pause");
	
	return 0;
}