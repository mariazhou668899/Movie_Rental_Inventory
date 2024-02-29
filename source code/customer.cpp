// -------------------------------------------------------------------------------------------
// Give class Customer's implementation of functions.
// -------------------------------------------------------------------------------------------


#include "customer.h"

// ------------------------------------Customer default constructor---------------------------
// Description: creates an customer object
Customer::Customer()
{
	
}

// ------------------------------------Customer  constructor----------------------------------
// Description: creates customer by reading from stream
Customer::Customer(istream& stream)
{
	stream >> customerID;
	stream >> firstName;
	stream >> lastName;
}

// ------------------------------------Customer destructor------------------------------------
// Description: destructs customer object
Customer::~Customer()
{

}

// ------------------------------------Customer getCustomerID------------------------------------------
// Description: returns customer  id
int Customer::getCustomerID() const
{
	return customerID;
}

// ------------------------------------Customer setCustomerID------------------------------------------
// Description: sets customer id
void Customer::setCustomerID(int cid)
{
	customerID = cid;
}

// ------------------------------------Customer getFirstName-------------------------------------------
// Description: returns customer's first name
const string& Customer::getFirstName() const
{
	return firstName;
}

// ------------------------------------Customer setFirstName-------------------------------------------
// Description: sets customer first name
void Customer::setFirstName(const string& fname)
{
	firstName = fname;
}

// ------------------------------------Customer getLastName--------------------------------------------
// Description: returns customer's last name
const string& Customer::getLastName() const
{
	return lastName;
}

// ------------------------------------Customer setLastName--------------------------------------------
// Description: sets customers last name
void Customer::setLastName(const string& lname)
{
	lastName = lname;
}

// ------------------------------------Customer getHistory---------------------------------------------
// Description: returns customers transaction history as a vector
const vector<Transaction*> Customer::getHistory() const
{
	return history;
}

// ------------------------------------Customer addToHistory-------------------------------------------
// Description: adds transaction to history vector
void Customer::addToHistory(Transaction* transaction)
{
	history.push_back(transaction);
}

// ------------------------------------Customer borrowMedia--------------------------------------------
// Description: adds the media to the borrowed vector
void Customer::borrowMedia(Media* media)
{
	borrowed.push_back(media);
}

// ------------------------------------Customer returnMedia--------------------------------------------
// Description: erases media from the borrowed vector 
bool Customer::returnMedia(Media* media)
{
	list<Media*>::iterator i = find(borrowed.begin(), borrowed.end(), media);
	if (i == borrowed.end())
		return false;

	borrowed.erase(i);
	return true;
}