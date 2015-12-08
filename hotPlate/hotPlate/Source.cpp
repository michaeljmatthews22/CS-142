//Michael Matthews
//Hot Plate
/*
This code will compute the steady state temperature distribution over a piece of metal. 
The boundries remain in their fixed state of 0 on the column ends and 100 on the top and bottom (with the exception of the corners).
Main can be found at the very bottom where it calls the rest of the functions
*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//setting forth constants used throughout the script
const int  ROWS = 20;
const int COLUMNS = 20;
const int BOARDER = 20;
const int ENDCOLUMN = 20;
const int ENDROW = 19;
const int START = 0;
//the following need to be doubles
const double EDGE = 0;
const double FIXED = 100;
const double ROW = 19;
const double SEARCH = 20;


//This function will output the 20X20 array of tempetures of the hot plate
double printHotPlate(double matrix[][COLUMNS]){

	//for loop to go through the rows
	for (int countRow = START; countRow < SEARCH; countRow++){
		int countColumn = START;
		//while loop to go through the columns
		while (countColumn < SEARCH){
			//this is simply for formatting the first time through
			double changedOnce = 25;
			if (matrix[countRow][countColumn] == changedOnce){
				cout << matrix[countRow][countColumn] << "  ";
			}
			else if(matrix[countRow][countColumn] == FIXED){
				cout << matrix[countRow][countColumn] << " ";
			}
			else{
				cout << matrix[countRow][countColumn] << "   ";
			}
			countColumn++;
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}


//This function will intialize the hotplate. Putting 0 at the edges and in the middle with 100 on the bottom and top rows (except for the corners)
double startHotPlate(double matrix[][COLUMNS]){
	int loopingRows;
	int loopingColumns;
	for (loopingRows = START; loopingRows < SEARCH; loopingRows++){
		for (loopingColumns = START; loopingColumns < SEARCH; loopingColumns++){
			if (loopingRows == START && loopingColumns != START && loopingColumns != ROW){
				matrix[loopingRows][loopingColumns] = FIXED;
			}
			else if (loopingRows == ROW && loopingColumns != START && loopingColumns != ROW){
				matrix[loopingRows][loopingColumns] = FIXED;
			}
			else{
				matrix[loopingRows][loopingColumns] = EDGE;
			}
		}
	}
	return 0;
}

//This will simulate the hot plate changing tempetures.  the fixed states set forth in startHotPlate will always remain the same.
//A second array is created here to maintain previous values
double averageHotPlate(double matrix[][COLUMNS]){
	int printing = 0;
	
	//setting biggestInLoop to 10 because I know that the first time through it will be changed to something a bigger value
	double biggestInLoop = 10;
	//go until the biggest change is .1
	double minChange = .1;

	while (biggestInLoop > minChange){

		double matrixPast[ROWS][COLUMNS];
		for (int countRow = START; countRow < SEARCH; countRow++){
			int countColumn = START;
			while (countColumn < SEARCH){
				matrixPast[countRow][countColumn] = matrix[countRow][countColumn];
				countColumn++;
			}
		}
		//setting forth the biggest in the loop as 0
		biggestInLoop = START;
		for (int countRows = START; countRows < SEARCH; countRows++){
			int countColumns = START;
			while (countColumns < SEARCH){
				//if it is not one of the fixed values, go through the if statement
				if (countRows != START && countRows != ROW && countColumns != START && countColumns != ROW){

					//finding places around the given value
					int averageTop = countRows + 1;
					int averageBottom = countRows - 1;
					int averageLeft = countColumns - 1;
					int averageRight = countColumns + 1;

					double total = matrixPast[averageTop][countColumns];
					total = total + matrixPast[averageBottom][countColumns];
					total = total + matrixPast[countRows][averageRight];
					total = total + matrixPast[countRows][averageLeft];

					//dividing by four
					double factors = 4;
					double average = total / factors;

					double value = matrix[countRows][countColumns];
				
					double change = average - value;

					//This checks to stop the loop.  When the biggest change was no bigger than .1, the loop stops
					if (change > biggestInLoop){
						biggestInLoop = change;
					}

					//assigning new value into array
					matrix[countRows][countColumns] = average;
				
					//If it needs to change simotaneously don't use this
					//matrix[countRow][countColumn] = average;
				}
				
				countColumns++;
			}

		}

		while (printing == 0){
			int print = printHotPlate(matrix);
			printing++;
		}

	}
	return 0;


}


int exportHotPlate(double matrix[][COLUMNS]){
	//creating file
	ofstream outputdata;
	outputdata.open("lab6output.csv");
	//outputting to csv file
	for (int countRow = START; countRow < SEARCH; countRow++){
		int countColumn = START;
		while (countColumn < SEARCH){

			outputdata << fixed << setprecision(1) << matrix[countRow][countColumn] << ",";

			if (countColumn == ROW){

				outputdata << endl;
			}

			countColumn++;
		}
		
	}
	outputdata.close();
	return 0;
}

//calling the different functions to be used. 
int main(){

	double matrix[ROWS][COLUMNS]; 
	double total = startHotPlate(matrix);
	double printOut = printHotPlate(matrix);
	double average = averageHotPlate(matrix);
	int exportHot = exportHotPlate(matrix);
	return 0;
}