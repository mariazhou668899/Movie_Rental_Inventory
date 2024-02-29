// -------------------------------------------------------------------------------------------
// Class Description: class Media is the parent class of movies class
// Give class Media's specification of data members and functions.
// -------------------------------------------------------------------------------------------


#ifndef media_h
#define media_h

#include <stdio.h>


enum MediaType
{
    DVDType
};


class Media
{
public:
    virtual ~Media();

    virtual int getStock() const;
    virtual void setStock(int stock);
    virtual void increaseStock(int add);
    virtual void decreaseStock();

    virtual MediaType getMediaType() const = 0; // pure virtual method will be override by its subclasses
    virtual void print() const = 0; // pure virtual method will be override by its subclasses

protected:
    int stock;
};

#endif /* media_h */


