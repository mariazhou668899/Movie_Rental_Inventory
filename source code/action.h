// -------------------------------------------------------------------------------------------
// Class Description: Help to implement action commands. 
// Superclass Action's specification of data members and functions
// Action's subclasses Query and Transaction's specification of data members and functions
// Query's subclasses Inventory and History's specification of data members and functions
// Transaction's subclasses Borrow and Return's specification of data members and functions
// -------------------------------------------------------------------------------------------

#ifndef action_h
#define action_h

#include <stdio.h>
#include "business.h"

// ============================================Action =========================================
enum ActionType
{
	query,
	transaction
};

class Action
{
public:
	virtual ~Action();
	virtual void Execute(Business* Business) = 0;
};

// ============================================Action->Query=========================================
// class Action's subclass Query part: class Query includes subclasses Inventroy and History
class Query : public Action
{
public:

private:
	enum queryType { inventory, history };

};

// ----------------------------------Action->Query->Inventory------------------------------------
// class Inventory
class Inventory : public Query
{
public:
	Inventory();
	virtual ~Inventory();
	void Execute(Business* Business);
};

// ----------------------------------Action->Query->History------------------------------------
// class History
class History : public Query
{
public:
	History();
	virtual ~History();

	int getCustomerId() const;
	void setCustomerId(int cid);

	void Execute(Business* Business);

private:
	int customerId;
};

// ============================================Action->Transaction=========================================
// class Action's subclass Transaction part: class Transaction includes subclasses Borrow and Return
// Transaction
class Transaction : public Action
{
public:
	Transaction();
	~Transaction();

	virtual void print() const = 0;

	int getCustomerId() const;
	void setCustomerId(int cid);

	Media* getMedia() const;
	void setMedia(Media* media);

protected:
	int customerID;
	Media* media;
};

// ----------------------------------Action->Transaction->Borrow------------------------------------
// class Borrow
class Borrow : public Transaction
{
public:
	Borrow();
	virtual ~Borrow();

	void Execute(Business* Business);
	void print() const;
};

// ----------------------------------Action->Transaction->Return------------------------------------
// class Return
class Return : public Transaction
{

public:
	Return();
	virtual ~Return();

	void Execute(Business* Business);
	void print() const;
};












#endif /* action_h */
