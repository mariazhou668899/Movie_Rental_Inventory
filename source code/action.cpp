// -------------------------------------------------------------------------------------------
// Superclass: Action's implementation of functions
// Action's subclasses: Query and Transaction's implementation of functions
// Query's subclasses: Inventory and History's implementation of functions
// Transaction's subclasses: Borrow and Return's implementation of functions
// -------------------------------------------------------------------------------------------

#include "action.h"

// ============================================Action =========================================
// ------------------------------------Action default destructor-----------------------------
// Description: creates an action object
Action::~Action()
{

}


// ============================================Inventory =========================================
// ------------------------------------Inventory default constructor--------------------------
// Description: creates an inventory object
Inventory::Inventory()
{

}

// ------------------------------------Inventory destructor-----------------------------------
// Description: destructs inventory object
Inventory::~Inventory()
{

}

// ------------------------------------Inventory Execute------------------------------------------------
// Description: gets movie information from Business and prints out the whole inventory system
// in order (first comedy, then drama and finally classics  movies
void Inventory::Execute(Business* Business)
{	
	bool comedyFlag=Business->getComedyTree().isEmpty();
	bool dramaFlag = Business->getDramaTree().isEmpty();
	bool classicsFlag = Business->getClassicsTree().isEmpty();
	if (comedyFlag && dramaFlag && classicsFlag) {
		cout << "Current Inventory is empty!" << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "Current Inventory is: " << endl;
		Business->getComedyTree().print();
		Business->getDramaTree().print();
		Business->getClassicsTree().print();
	}
	cout << endl;
}


// ============================================History =========================================
// ------------------------------------History default constructor----------------------------
// Description: creates an history  object
History::History()
{
	customerId = -1;
}

// ------------------------------------History destructor-------------------------------------
// Description: destructs history object
History::~History()
{

}

// ------------------------------------History getCustomerID------------------------------------------
// Description: returns customer ID
int History::getCustomerId() const
{
	return customerId;
}

// ------------------------------------History setCustomerID------------------------------------------
// Description: sets customer id for the user
void History::setCustomerId(int cid)
{
	customerId = cid;
}

// ------------------------------------History Execute------------------------------------------------
// Description: finds customer with customer ID and prints out the transaction history
// gives error when there is no such customer with given ID
void History::Execute(Business* Business)
{
	Customer* customer = Business->getCustomers().getItem(customerId);
	if (!customer)
	{
		cout << "Invalid customer ID: " << customerId << endl;
		return;
	}

	const vector<Transaction*>& history = customer->getHistory();
	int records = history.size();
	if (records ==0) {
		cout << endl;
		cout <<"Customer " << customerId << " hasn't transaction history!" << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "Customer " << customerId << "'s transaction histories are: " << endl;		
		for (int i = 0; i < history.size(); i++)
		{
			history[i]->print();
		}
		cout << endl;
	}

}


// ============================================Transaction =========================================
// ------------------------------------Transaction default constructor----------------------------
// Description: creates an transaction  object
Transaction::Transaction()
{
	customerID=-1;
	media=NULL;
}

// ------------------------------------Transaction destructor-------------------------------------
// Description: destructs transaction object
Transaction::~Transaction()
{

}

// -----------------------------------Transaction getCustomerId-------------------------------------------
// Description: returns customer id
int Transaction::getCustomerId() const
{
	return customerID;
}

// -----------------------------------Transaction setCustomerId-------------------------------------------
// Description: sets customer ID
void Transaction::setCustomerId(int newID)
{
	customerID = newID;
}

// -----------------------------------Transaction getMedia------------------------------------------------
// Description: returns media type
Media* Transaction::getMedia() const
{
	return media;
}

// -----------------------------------Transaction setMedia------------------------------------------------
// Description: sets media type
void Transaction::setMedia(Media* newMedia)
{
	this->media = newMedia;
}


// ============================================Borrow =========================================
// ------------------------------------Borrow default constructor-----------------------------
// Description: creates an borrow  object
Borrow::Borrow()
{

}

// ------------------------------------Borrow destructor--------------------------------------
// Description: destructs borrow object
Borrow::~Borrow()
{

}

// ------------------------------------Borrow Execute------------------------------------------------
// Description: Updates the stock by borrowing a desired movie. Gives error if the stock of the
// movie smaller than or equal to zero. Also gives error if customer Id is invalid
void Borrow::Execute(Business* Business)
{
	Customer* customer = Business->getCustomers().getItem(customerID);
	if (!customer)
	{
		cout << "Invalid customer ID: " << customerID << endl;
		return;
	}

	if (media->getStock() <= 0)
	{
		cout << "Can't borrow media. Out of stock." << endl;
		return;
	}

	customer->addToHistory(this);
	customer->borrowMedia(media);
	media->decreaseStock();
}

// ------------------------------------Borrow Print--------------------------------------------------
// Description: prints out borrowed movie info. just added for test puposes 
void Borrow::print() const
{
	cout << "B " << customerID << " ";
	media->print();
}

// ============================================Return =========================================
// ------------------------------------Return default constructor----------------------------
// Description: creates an return object
Return::Return()
{

}

// ------------------------------------Return destructor--------------------------------------
// Description: destructs return object
Return::~Return()
{

}

// ------------------------------------Return Execute------------------------------------------------
// Description: Updates the stock by returning a desired movie. Gives error if an unborrowed
// movie is been tried to returned. Also gives error if customer Id is invalid
void Return::Execute(Business* Business)
{
	Customer* customer = Business->getCustomers().getItem(customerID);
	if (!customer)
	{
		cout << "Invalid customer ID: " << customerID << endl;
		return;
	}

	if (!customer->returnMedia(media))
	{
		cout << "Can't return unborrowed media." << endl;
		return;
	}

	customer->addToHistory(this);
	media->increaseStock(1);
}

// ------------------------------------Return Print--------------------------------------------------
// Description: prints out returned movie info. just added for test puposes
void Return::print() const
{
	cout << "R " << customerID << " ";
	media->print();
}