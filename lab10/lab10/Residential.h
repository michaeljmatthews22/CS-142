#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Property.h"

//New residential propery. Inherits from Property
class Residential : public Property
{
	//Only residentials are occupied
private: 
	bool occupied;
	
public:
	Residential(string type, bool rental, double value, bool occupied, string address);
	~Residential();

	virtual string toString();
	virtual int calculateTaxes();
	//virtual int calculateTaxes(double discount);
};

