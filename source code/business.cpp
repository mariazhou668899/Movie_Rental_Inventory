// -------------------------------------------------------------------------------------------
// implementation of functions of Class Business
// Assumptions: assumes data in .txt file formatted correctly but may include errors.
// -------------------------------------------------------------------------------------------

//#include <stdio.h>
#include "business.h"
#include <iostream>
#include <fstream>
#include "moviefactory.h"
#include "actionfactory.h"


using namespace std;


// ------------------------------------Business default constructor------------------------------
// Description: creates an empty Business
// -------------------------------------------------------------------------------------------
Business::Business()
{

}

// ------------------------------------Business default destructor------------------------------
// Description: destructs Business
Business::~Business()
{

}

// ------------------------------------Business readMovieFile-----------------------------------------
// Description: reads from .txt file and insert each movie in
// movies in corresponding binary search tree.
void Business::processMovieFile()
{
    const string movieFileName = "data4movies.txt";
    fstream infile(movieFileName, ios_base::in);

    if (infile.fail())
    {
        cout << "Can't find movie file: " << movieFileName << endl;
        return;
    }

    while (!infile.eof())
    {
        Movie* movie = MovieFactory::Create(infile);
        if (movie)
        {
            switch (movie->getMovieType())
            {
            case MovieType::ComedyType:
                ComedyTree.insert(dynamic_cast<Comedy*>(movie));
                break;
            case MovieType::DramaType:
                DramaTree.insert(dynamic_cast<Drama*>(movie));
                break;
            case MovieType::ClassicalType:
                ClassicsTree.insert(dynamic_cast<Classics*>(movie));
                break;
            default:
                throw new logic_error("Unexpected type");

            }
        }
    }
}

// ------------------------------------Business readCommandsFile--------------------------------------
// Description: reads from .txt file and creates actions
void Business::processCommandsFile()
{
    const string commandsFileName = "data4commands.txt";
    fstream infile(commandsFileName, ios_base::in);

    if (infile.fail())
    {
        cout << "Can't find commands file: " << commandsFileName << endl;
        return;
    }

    while (!infile.eof())
    {
        Action* action = ActionFactory::Create(infile, this);
        if (action)
        {
            action->Execute(this);
        }
    }
}

// ------------------------------------Business readCustomerFile--------------------------------------
// Description: reads from .txt file and creates customers
void Business::processCustomerFile()
{
    const string customerFileName = "data4customers.txt";
    fstream infile(customerFileName, ios_base::in);

    if (infile.fail())
    {
        cout << "Can't find customer file: " << customerFileName << endl;
        return;
    }

    while (!infile.eof())
    {
        Customer* customer = new Customer(infile);
        if (customer)
        {
            Customers.addItem(customer->getCustomerID(), customer);
        }
    }
}

// -------------------------------------Business getComedyTree()--------------------------------------
// Description: returns the three that holds comedy movies
const BSTree<Comedy>& Business::getComedyTree() const
{
    return ComedyTree;
}

// -------------------------------------Business getDramaTree()---------------------------------------
// Description: returns the three that holds drama movies
const BSTree<Drama>& Business::getDramaTree() const
{
    return DramaTree;
}

// -------------------------------------Business getClassicsTree()------------------------------------
// Description: returns the three that holds classics movies
const BSTree<Classics>& Business::getClassicsTree() const
{
    return ClassicsTree;
}

// -------------------------------------getCustomers()--------------------------------------
// Description: returns a hastable that holds customer info
const HashTable<Customer>& Business::getCustomers() const
{
    return Customers;
}
