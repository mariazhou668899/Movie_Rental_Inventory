// -------------------------------------------------------------------------------------------
// Give class Movie's implementation of functions.
// -------------------------------------------------------------------------------------------


#include "movie.h"

// ============================================Movie=========================================
// ------------------------------------Movie destructor---------------------------------------
// Description: destructs Movie object
Movie::~Movie()
{

}

// ------------------------------------Movie getDirector--------------------------------------------
// Description: returns director's name
const string& Movie::getDirector() const
{
    return director;
}

// ------------------------------------Movie setDirector--------------------------------------------
// Description: setsdirector's name
void Movie::setDirector(const string& directorName)
{
    director = directorName;
}

// ------------------------------------Movie getTitle-----------------------------------------------
// Description: returns movie title
const string& Movie::getTitle() const
{
    return title;
}

// ------------------------------------Movie setTitle-----------------------------------------------
// Description: sets movie title
void Movie::setTitle(const string& titleN)
{
    title = titleN;
}

// ------------------------------------Movie getYear------------------------------------------------
// Description: returns movie year
int Movie::getYear() const
{
    return year;
}

// ------------------------------------Movie setYear------------------------------------------------
// Description: sets movie year
void Movie::setYear(int yearN)
{
    year = yearN;
}

// ------------------------------------Movie getMediaType-------------------------------------------
// Description: returns media type 
MediaType Movie::getMediaType() const

{
    return MediaType::DVDType;

}

// ============================================Comedy=========================================
// ------------------------------------Comedy default constructor-----------------------------
// Description: creates Comedy object
Comedy::Comedy()
{

}

// ------------------------------------Comedy destructor---------------------------------------
// Description: destructs Comedy object
Comedy::~Comedy()
{

}

// ------------------------------------Comedy isEqual------------------------------------------------
// Description: checks whether two comedy movies is equal to each other. returns boolean
bool Comedy::isEqual(const Comedy& node) const
{
    return
        node.getTitle().compare(title) == 0 &&
        node.getYear() == year;
}

// ------------------------------------Comedy isGreater----------------------------------------------
// Description: checks whether one comedy object is greater than another. returns boolean
bool Comedy::isGreater(const Comedy& node) const
{
    if (title.compare(node.getTitle()) != 0)
        return title.compare(node.getTitle()) > 0;

    return year > node.getYear();
}

// ------------------------------------Comedy getMovieType-------------------------------------------
// Description: returns movie type
MovieType Comedy::getMovieType() const
{
    return MovieType::ComedyType;
}

// ------------------------------------Comedy print--------------------------------------------------
// Description: prints movie info. used for test puposes.
void Comedy::print() const
{
    cout << "F, " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// ============================================Drama=========================================
// ------------------------------------Drama default constructor------------------------------
// Description: creates Drama object
Drama::Drama()
{

}

// ------------------------------------Drama Destructor---------------------------------------
// Description: destructs drama objects
Drama::~Drama()
{

}

// ------------------------------------Drama isEqual------------------------------------------------
// Description: checks whether two drama movies is equal to each other. returns boolean

bool Drama::isEqual(const Drama& mov) const
{
    return
        mov.getDirector().compare(director) == 0 &&
        mov.getTitle().compare(title) == 0;
}

// ------------------------------------Drama isGreater----------------------------------------------
// Description: checks whether one drama object is greater than another. returns boolean
bool Drama::isGreater(const Drama& mov) const
{
    if (director.compare(mov.getDirector()) != 0)
        return director.compare(mov.getDirector()) > 0;

    if (title.compare(mov.getTitle()) != 0)
        return title.compare(mov.getTitle()) > 0;

    return year > mov.getYear();
}

// ------------------------------------Drama getMovieType-------------------------------------------
// Description: returns movie type
MovieType Drama::getMovieType() const // ok
{
    return MovieType::DramaType;
}

// ------------------------------------Drama print--------------------------------------------------
// Description: prints movie info. used for test puposes.
void Drama::print() const
{
    cout << "D, " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// ============================================Classics=========================================
// ------------------------------------Classics default constructor---------------------------
// Description: creates Classics object
Classics::Classics()
{

}

// ------------------------------------Classics destructor------------------------------------
// Description: destructs classics object
Classics::~Classics()
{

}

// ------------------------------------Classics getMonth-----------------------------------------------
// Description: returns month
int Classics::getMonth() const
{
    return month;
}

// ------------------------------------Classics setMonth-----------------------------------------------
// Description: sets month info
void Classics::setMonth(int month)
{
    this->month = month;
}

// ------------------------------------Classics getMajorActor------------------------------------------
// Description: returns major actor's name
const string& Classics::getMajorActor() const
{
    return majorActor;
}

// ------------------------------------Classics setMajorActor------------------------------------------
// Description: sets major actor name
void Classics::setMajorActor(const string& mjName)
{
    majorActor = mjName;
}

// ------------------------------------Classics isEqual------------------------------------------------
// Description: checks whether two classic movies is equal to each other. returns boolean
bool Classics::isEqual(const Classics& mov) const
{
    return
        mov.getYear() == year &&
        mov.getMajorActor().compare(majorActor) == 0 &&
        mov.getMonth() == month;
}

// ------------------------------------Classics isGreater----------------------------------------------
// Description: checks whether one classics object is greater than another. returns boolean
bool Classics::isGreater(const Classics& mov) const
{
    if (year != mov.getYear())
        return year > mov.getYear();

    if (month != mov.getMonth())
        return month > mov.getMonth();

    return majorActor.compare(mov.getMajorActor()) > 0;
}

// ------------------------------------Classics getMovieType-------------------------------------------
// Description: returns movie type
MovieType Classics::getMovieType() const
{
    return ClassicalType;
}

// ------------------------------------Classics print--------------------------------------------------
// Description: prints movie info. used for test puposes.
void Classics::print() const
{
    cout << "C, " << stock << ", " << director << ", " << title << ", " << majorActor << " " << month << " " << year << endl;
}