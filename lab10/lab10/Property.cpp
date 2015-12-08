#include "Property.h"
#include <sstream>

//Using the static total in order to give new ids
int Property::total = 0;

//New property. Giving ID starting at zero and other values that both Residential and Commercial have
Property::Property(string type, bool rental, double value, string address)
{
	this->type = type;
	this->rental = rental;
	this->value = value;
	this->address = address;

	id = total;
	total++;
}

//Deconstructor
Property::~Property()
{
}

//To string for each of the values that both Residential and Commercial have
string Property::toString(){

	stringstream ss;
	ss << "Property id: " << id << " ";
	ss << "Address: " << address;
	if (rental == true){
		ss << " Rental ";
	}
	else{
		ss << " NOT rental ";
	}
	ss << "Estimated Value: " << value;
	

	return ss.str();
}

//Get address
string Property::getAddress(){
	return address;
}

//Get ID
int Property::getId(){
	return id;
}
//Get value of the property
double Property::getValue(){
	return value;
}
//get bool if it is rented or not
double Property::getRental(){
	return rental;
}
