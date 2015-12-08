#include "Residential.h"
#include <sstream>

//New Residential information
Residential::Residential(string type, bool rental, double value, bool occupied, string address) : Property(type, rental, value, address)
{
	this->occupied = occupied;
}

//Deconstructor
Residential::~Residential()
{
}

//toString that willoutput information regarding if it is occupied or not
string Residential::toString(){

	stringstream ss;
	ss << Property::toString();

	if (occupied == true){
		ss << " Occupied";
	}
	else{
		ss << " Not Occupied";
	}
	return ss.str();
}

//this will calculate the Taxes for residential tendants

int Residential::calculateTaxes(){

	double taxrate;
	const double NOT_OCCUPPIED = .009;
	const double OCCUPIED_TAX = .006;

	if (occupied == true){

		taxrate = OCCUPIED_TAX;
	}
	else{

		taxrate = NOT_OCCUPPIED;
	}
	
	double taxes_to_pay;

	double value = Property::getValue();

	taxes_to_pay = value * taxrate;

	return taxes_to_pay;


}
	
