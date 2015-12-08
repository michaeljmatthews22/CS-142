#pragma once
#include <string>
#include <vector>
#include "Property.h"
using namespace std;

//Commercial class. Discount and hasDiscount are unique to Commercial
class Commercial : public Property
{

private:
	double discount;
	bool hasDiscount;

public:
	//new commercial
	Commercial(string type, bool rental, double value, bool hasDiscount, double discount, string address);
	~Commercial();

	//using virtuals
	virtual string toString();
	virtual int calculateTaxes();

};

