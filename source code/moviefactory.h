// -------------------------------------------------------------------------------------------
// Class Description: read from the .txt file and creates movies by static method 
// Give class MovieFactory's specification of data members and functions.
// -------------------------------------------------------------------------------------------



#ifndef moviefactory_h
#define moviefactory_h

#include <stdio.h>
#include "movie.h"


class MovieFactory
{

public:
    static Movie* Create(istream& stream);

private:
    static Comedy* CreateComedy(istream& stream);
    static Drama* CreateDrama(istream& stream);
    static Classics* CreateClassics(istream& stream);

};

#endif /* moviefactory_h */