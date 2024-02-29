// -------------------------------------------------------------------------------------------
// Class Description: To store customer data based as a data structure 
// Give template class HashTable's specification of data members and functions.
// Give template class HashTable's implementation of data members and functions.
// Assumptions: Uses chain model hashing. Duplicate customer is not allowed
// -------------------------------------------------------------------------------------------


#ifndef hashtable_h
#define hashtable_h

#include <stdio.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
using namespace std;

template < class item_type>
class HashTable {
public:
    // ------------------------------------default constructor--------------------------
    // Description: calls buildTable() creates an empty hastable
    HashTable()
    {
        buildTable();
    }

    // ------------------------------------destructor----------------------------
    // Description: calls makeEmpty() function. destructs Hashtable
    ~HashTable()
    {
        makeEmpty();
    }
    // ------------------------------------getItem()----------------------------------------------
    // Description: if found, returns the item being searched , otherwise returns null
    item_type* getItem(int key) const
    {
        int hash = (key % SIZE); // assign hash

        if (table[hash] == NULL)
        {         
            return NULL;  // no customer stored in hash table
        }
        else
        {
            ItemList* node = table[hash]; // travers linked list until found
            while (node != NULL)
            {
                if (key == node->key)
                    return node->data;

                node = node->next;
            }
        }
        return NULL; // not found
    }

    // ------------------------------------addItem------------------------------------------------
    // Description: add new item into hastable. Checks for duplicates
    void addItem(int key, item_type* item)
    {
        int hash = (key % SIZE);  // assign hash

        ItemList* node = new ItemList;  // node that hold customer
        node->data = item;  // point to customer
        node->key = key;  // point to key
        node->next = NULL;  

        
        if (table[hash] == NULL)  // check if the index is empty
        {
            node->next = table[hash];
            table[hash] = node;
        } 
        else  // if table[hash] is not NULL
        {
            ItemList* current = table[hash];
            while (current->next != NULL)
            {
                // check if duplicate
                if (key == current->key)
                {
                    delete node->data;      // delete customer
                    delete node;            // delete pointer
                    throw logic_error("Can't add same key twice!");
                }
                current = current->next;
            }
            current->next = node; // add to the list
        }
    }

private:
    static const int SIZE = 29; // prime number and larger than twice size of customer base

    // ------------------------------------makeEmpty()--------------------------------------------
    // Description: deletes all items in the table
    void makeEmpty()
    {
        for (int i = 0; i < SIZE; ++i) {
            if (table[i] != NULL) {
                ItemList* del = table[i];  // hold del at head
                // loop until the last node
                while (table[i] != NULL) {
                    table[i] = table[i]->next;   // moove head
                    delete del->data;   // delete customer
                    delete del;   // delete node
                    del = NULL;
                    del = table[i];	 // assing del to head
                }
            }
        }
    }

    // ------------------------------------buildTable()-------------------------------------------
    // Description: creates an empty table
    void buildTable()
    {
        for (int i = 0; i < SIZE; ++i) {
            table[i] = NULL;
        }
    }

    struct ItemList   // linked list that attached to index of table
    {
        item_type* data;   //  hold customer
        int key;           // hold ID  (key)
        ItemList* next;   // next
    };

    ItemList* table[SIZE];   // hastable array
};

#endif /* hashtable_h */

