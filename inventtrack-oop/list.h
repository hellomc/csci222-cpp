//list.h
//Declares the private and public members of the List class.
//
//author    Michelle Adea
//version   03/14/2019

#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
using namespace std;

// declare struct item with properties
struct item {
    int numId;
    char name[21];
    int quantity;
    int categoryCode;
    char supplierCode[1];
    float unitCost;
    float unitPrice;
    item *next;
};

class List {
    private:
        item * first;
        item * last;
    public:
        List();     // default constructor
        ~List();    // destructor
        void append(item *p);   // append member function
        void showHeader() const;      // show member function
        friend std::ostream &operator<<(std::ostream &os, const List &l);
};

#endif
