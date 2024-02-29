// -------------------------------------------------------------------------------------------
// Class Description: Give class Customer's specification of data members and functions.
// -------------------------------------------------------------------------------------------


#ifndef customer_h
#define customer_h

#include "media.h"
#include "BSTree.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Transaction;

class Customer
{
public:
	// constructors
	Customer();
	Customer(istream& stream);
	virtual ~Customer();


	// functions
	int getCustomerID() const;
	void setCustomerID(int cid);

	const string& getFirstName() const;
	void setFirstName(const string& fname);

	const string& getLastName() const;
	void setLastName(const string& lname);

	const vector<Transaction*> getHistory() const;
	void addToHistory(Transaction* transaction);
	void borrowMedia(Media* media);
	bool returnMedia(Media* media);

private:
	int customerID;
	string firstName;
	string lastName;
	vector<Transaction*> history; //record current customer's transaction histories
	list<Media*> borrowed;
};

#endif /* customer_h */