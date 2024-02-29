// -------------------------------------------------------------------------------------------
// Give class MovieFactory's implementation of functions
// -------------------------------------------------------------------------------------------


#include "moviefactory.h"
#include "BSTree.h"
#include <iostream>
#include <string>
using namespace std;

// ------------------------------------MovieFactory Create-------------------------------------------------
// Description: reads from the file. creates movies . Depending on the movie type calls
// corresponding helper methods
Movie* MovieFactory::Create(istream& stream)
{
    
    ////////////////////////////////////////////////////////
    return movie;
}

// ------------------------------------MovieFactory CreateComedy-------------------------------------------
// Description: helper method to create comedy movie
Comedy* MovieFactory::CreateComedy(istream& stream)
{
    int movieYear;
    stream >> movieYear;

    Comedy* comedy = new Comedy();
    comedy->setYear(movieYear);

    return comedy;
}

// ------------------------------------MovieFactory CreateDrama-------------------------------------------
// Description: helper method to create drama movie
Drama* MovieFactory::CreateDrama(istream& stream)
{
    int movieYear;
    stream >> movieYear;
    Drama* drama = new Drama();
    drama->setYear(movieYear);

    return drama;

}

// ------------------------------------MovieFactory CreateClassics-------------------------------------------
// Description: helper method to create classics movie
Classics* MovieFactory::CreateClassics(istream& stream)
{
    /////////////////////////////////////

    return classics;
}
