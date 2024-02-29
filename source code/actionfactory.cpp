// -------------------------------------------------------------------------------------------
// Give class ActionFactory's implementation of functions
// -------------------------------------------------------------------------------------------


#include "actionfactory.h"

// ------------------------------------Create-------------------------------------------------
// Description: reads from the file creates actions
Action* ActionFactory::Create(istream& stream, Business* Business)
{
	char actionType;

	stream >> actionType;
	if (stream.fail())
		return NULL;

	Action* action;
/////////////////////////////////////////////////////////////delete

	return action;
}


// ------------------------------------CreateInventory----------------------------------------
// Description: returns inventory
Inventory* ActionFactory::CreateInventory(istream& stream, Business* Business)
{
	return new Inventory();
}


// ------------------------------------CreateHistory------------------------------------------
// Description: creates history for a customer
History* ActionFactory::CreateHistory(istream& stream, Business* Business)
{
	int customerId;
	stream >> customerId;
	History* history = new History();
	history->setCustomerId(customerId);
	return history;
}

// ------------------------------------CreateBorrow-------------------------------------------
// Description: creates borrow transaction
Borrow* ActionFactory::CreateBorrow(istream& stream, Business* Business)
{
	int customerId;
	stream >> customerId;

	Media* media = FindMedia(stream, Business);
	if (!media)
		return NULL;

	Borrow* borrow = new Borrow();
	borrow->setMedia(media);
	borrow->setCustomerId(customerId);
	return borrow;
}

// ------------------------------------CreateReturn-------------------------------------------
// Description: creates return transaction
Return* ActionFactory::CreateReturn(istream& stream, Business* Business)
{
	int customerId;
	stream >> customerId;

	Media* media = FindMedia(stream, Business);
	if (!media)
		return NULL;

	Return* returnAction = new Return();
	returnAction->setMedia(media);
	returnAction->setCustomerId(customerId);
	return returnAction;
}

// ------------------------------------FindMedia----------------------------------------------
// Description: finds desired media
Media* ActionFactory::FindMedia(istream& stream, Business* Business)
{
	char mediaType;
	stream >> mediaType;
	stream.ignore();

	if (mediaType != 'D')
	{
		cout << "Invalid media type: " << mediaType << endl;
		stream.ignore(512, '\n');
		return NULL;
	}

	char movieType;
	stream >> movieType;
	stream.ignore();

///////////////////////////////////////////////////////////////////////delete
}

// ------------------------------------FindMedia----------------------------------------------
// Description: finds desired media
Classics* ActionFactory::FindClassics(istream& stream, Business* Business)
{
	int month;
	stream >> month;

	int year;
	stream >> year;

	string majorActorName;
	stream >> majorActorName;

	string majorActorLastname;
	stream >> majorActorLastname;

	Classics classicsToSearch;
	classicsToSearch.setMonth(month);
	classicsToSearch.setYear(year);
	classicsToSearch.setMajorActor(majorActorName + " " + majorActorLastname);

	Classics* found = NULL;
	if (!Business->getClassicsTree().retrieve(classicsToSearch, found))
	{
		cout << "Invalid classics movie " << month << " " << year << " " << majorActorName << " " << majorActorLastname << endl;
		return NULL;
	}

	return found;
}

// ------------------------------------FindComedy----------------------------------------------
// Description: finds desired comedy
Comedy* ActionFactory::FindComedy(istream& stream, Business* Business)
{
	string movieTitle;
	getline(stream >> ws, movieTitle, ',');

	int year;
	stream >> year;

	Comedy comedyToSearch;
	comedyToSearch.setYear(year);
	comedyToSearch.setTitle(movieTitle);

	Comedy* found = NULL;
	if (!Business->getComedyTree().retrieve(comedyToSearch, found))
	{
		cout << "Invalid comedy movie " << movieTitle << " " << year << endl;
		return NULL;
	}

	return found;
}

// ------------------------------------FindDrama----------------------------------------------
// Description: finds desired drama movie 
Drama* ActionFactory::FindDrama(istream& stream, Business* Business)
{
	string director;
	getline(stream >> ws, director, ',');

	string movieTitle;
	getline(stream >> ws, movieTitle, ',');

	Drama dramaToSearch;
	dramaToSearch.setDirector(director);
	dramaToSearch.setTitle(movieTitle);

	Drama* found = NULL;
	if (!Business->getDramaTree().retrieve(dramaToSearch, found))
	{
		cout << "Invalid drama movie " << director << " " << movieTitle << endl;
		return NULL;
	}
	return found;
}

