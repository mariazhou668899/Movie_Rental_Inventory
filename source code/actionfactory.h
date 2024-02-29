// -------------------------------------------------------------------------------------------
// Class Description: read from the .txt file and create I, H, B and R actions by dynamic method 
// Give class ActionFactory's specification of data members and functions.
// -------------------------------------------------------------------------------------------


#ifndef actionFactory_hpp
#define actionFactory_hpp

#include <stdio.h>
#include <iostream>
#include "action.h"

using namespace std;


class ActionFactory
{

public:
	static Action* Create(istream& stream, Business* Business);

private:
	static Inventory* CreateInventory(istream& stream, Business* Business);
	static History* CreateHistory(istream& stream, Business* Business);
	static Borrow* CreateBorrow(istream& stream, Business* Business);
	static Return* CreateReturn(istream& stream, Business* Business);
	static Media* FindMedia(istream& stream, Business* Business);
	static Classics* FindClassics(istream& stream, Business* Business);
	static Comedy* FindComedy(istream& stream, Business* Business);
	static Drama* FindDrama(istream& stream, Business* Business);
};

#endif /* actionFactory_hpp */