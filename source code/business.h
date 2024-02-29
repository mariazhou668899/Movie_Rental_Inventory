// -------------------------------------------------------------------------------------------
// Class Description: Process movie, customer and commands files as a controller. 
// Give class Business's specification of data members and functions.
// Assumptions: assumes data in .txt file formatted correctly but may include errors.
// -------------------------------------------------------------------------------------------


#ifndef Business_h
#define Business_h

#include "customer.h"
#include "movie.h"
#include "BSTree.h"
#include "hashtable.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Business
{
public:

    // constructors
    Business();
    ~Business();

    // functions
    void processMovieFile();
    void processCustomerFile();
    void processCommandsFile();

    const BSTree<Comedy>& getComedyTree() const;
    const BSTree<Drama>& getDramaTree() const;
    const BSTree<Classics>& getClassicsTree() const;
    const HashTable<Customer>& getCustomers() const;

private:
    BSTree<Comedy> ComedyTree;
    BSTree<Drama> DramaTree;
    BSTree<Classics> ClassicsTree;
    HashTable<Customer> Customers;

};

#endif /* Business_h */
