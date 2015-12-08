#include "Commercial.h"
#include <sstream>

//New commercial address
Commercial::Commercial(string type, bool rental, double value, bool hasDiscount, double discount, string address) : Property(type, rental, value, address)
{
	this->discount = discount;
	this->hasDiscount = hasDiscount;
}


//Deconstructor
Commercial::~Commercial()
{
}

//This will compute the taxes for anyone who is in the commercial business

int Commercial::calculateTaxes(){

	double taxes_to_pay;
	const double RENTAL_TAX = .012;
	const double NO_RENTAL_TAX = .01;

	bool rental = Property::getRental();
	double value = Property::getValue();
	double toBePaid = 1;
	
	//if they have the discount or not
	if (hasDiscount == true){

		if (rental == true){
			
			taxes_to_pay = ((value * (toBePaid - discount)) * RENTAL_TAX);
		}
		else{

			taxes_to_pay = ((value * (toBePaid - discount)) * NO_RENTAL_TAX);
		}
	}
	else{

		if (rental == true){

			taxes_to_pay = (value * RENTAL_TAX);
		}
		else{
			taxes_to_pay = (value *  NO_RENTAL_TAX);
		}

	}

	return taxes_to_pay;
}

//This is the toSTring function that calls the Property class first and then outputs information regarding commercial
string Commercial::toString(){

	stringstream ss;
	ss << Property::toString();
	if (hasDiscount == true){
		ss << " Discounted ";
		ss << " Discount: " << discount;
	}
	else{
		ss << " NOT discounted ";
	}
	
	return ss.str();
}

