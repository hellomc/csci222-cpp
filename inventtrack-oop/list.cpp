//list.cpp
//Defines the functions for the List class.
//
//author    Michelle Adea
//version   03/10/2019

#include <iostream>
#include <iomanip>
using namespace std;
#include "list.h"

//default constructor
List::List() {
    first = last = 0; // initializes the list to empty
}

//destructor traverses list and frees items
List::~List() {
    item *current = first, *next;

    while (current != 0) {
        next = current->next;
        delete current;
        current = next;
    }
}

void List::append(item *p) {
    if (last == 0)
        first = p;
    else
        last->next = p;

    last = p; 
}

void List::show() const {
    item *p = first;

    if (p != 0) {
        cout << "\n*********Inventory List*********" << endl;
        cout << setw(10) << left << "Item No."
             << setw(25) << left << "Item Description"
             << setw(10) << left << "Quantity"
             << setw(15) << "Category Code"
             << setw(15) << "Supplier Code"
             << setw(10) << right << "Unit Cost"
             << setw(15) << right << "Unit Price" << endl;
        // shows any trailing zeroes, floating point, fixed at 2 decimal places
        cout << showpoint << setprecision(2) << fixed;
    }

    while (p != 0) {
        cout << setw(10) << left << p->numId
             << setw(25) << left << p->name
             << setw(10) << left << p->quantity
             << setw(15) << p->categoryCode
             << setw(15) << p->supplierCode
             << setw(10) << right << p->unitCost
             << setw(15) << right << p->unitPrice
             << endl;
        p = p->next;
    }
}