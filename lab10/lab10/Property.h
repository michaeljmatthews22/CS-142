#pragma once
#include <string>
#include <vector>
#include <sstream>

//don't include the child within the parent!
using namespace std;

//Property class. Each one of the privates each property member will ahve
class Property
{

private:

	string address;
	double value;
	bool rental;
	double taxrate;

	//using static to give id to each new user
	static int total;
	int id;
	string type;


public:

	Property(string type, bool rental, double value, string address);
	~Property();

	//pure virtual. there is no "propery" calculate taxes, just for the children
	virtual int calculateTaxes() = 0;
	virtual string toString();
	string getAddress();
	int getId();
	double getValue();
	double getRental();
	

		
};

