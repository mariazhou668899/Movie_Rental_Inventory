// -------------------------------------------------------------------------------------------
// Class Description: Superclass Movie's specification of data members and functions
// Movie's subclasses Comedy, Drama and Classics's specification of data members and functions
// -------------------------------------------------------------------------------------------


#ifndef movie_h
#define movie_h

#include <stdio.h>
#include "media.h"
#include <iostream>
#include <fstream>
#include <string> 



using namespace std;

enum MovieType
{
    ComedyType,
    DramaType,
    ClassicalType
};

// =========================Movie=========================
class Movie : public Media
{

public:
    //destructor
    virtual ~Movie();

    //functions
    virtual const string& getDirector() const;
    virtual void setDirector(const string& directorName);

    virtual const string& getTitle() const;
    virtual void setTitle(const string& title);

    virtual int getYear() const;
    virtual void setYear(int year);

    virtual MovieType getMovieType() const = 0; // pure virtual method will be override by its subclasses
    virtual MediaType getMediaType() const; // only one type "DVD" so far

protected:
    string director;
    string title;
    int year;
};

// =========================Comedy=========================
class Comedy : public Movie
{
public:
    //constructors 
    Comedy();
    virtual ~Comedy();

    //functions
    bool isEqual(const Comedy& comedy) const;
    bool isGreater(const Comedy& comedy) const;

    virtual MovieType getMovieType() const;

    void print() const;
};

// =========================Drama=========================
class Drama : public Movie
{
public:
    //constructors 
    Drama();

    virtual ~Drama();

    //functions
    bool isEqual(const Drama& mov) const;
    bool isGreater(const Drama& mov) const;

    virtual MovieType getMovieType() const;

    void print() const;
};

// =========================Classics=========================
class Classics : public Movie
{
public:
    //constructors
    Classics();
    virtual ~Classics();

    // functions
    int getMonth() const;
    void setMonth(int month);

    virtual const string& getMajorActor() const;
    virtual void setMajorActor(const string& name);

    virtual bool isEqual(const Classics& mov) const;
    virtual bool isGreater(const Classics& mov) const;
    virtual MovieType getMovieType() const;

    void print() const;
private:

    int month;
    string majorActor;
};



#endif /* movie_h */