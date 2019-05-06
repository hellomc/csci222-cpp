/**
 * Contains the functions for creating and manipulating objects of
 * Person class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#include <iostream>
#include <string.h>
using namespace std;
#include "person.h"

// public member functions

// Default constructor for objects of class Person.
Person::Person() {
    firstName = new char[100];
    lastName = new char[100];
}

// Deep copy constructor for objects of class Person.
Person::Person(const Person &p) {
    firstName = p.firstName;
    lastName = p.lastName;
}

// Deep assignment operator for objects of class Person.
Person & Person::operator=(const Person &p) {
    if (this == &p)     // handles p = p
        return *this;
    
    delete firstName;
    firstName = p.firstName;
    delete lastName;
    lastName = p.lastName;

    return *this;       // handles p1 = p2 = p3
}

// Destructor for objects of class Person.
Person::~Person() {
    delete firstName;
    delete lastName;
}

// Returns the first name of the Person object.
char * Person::getFirstName() const {
    return firstName;
}

// Returns the last name of the Person object.
char * Person::getLastName() const {
    return lastName;
}

// Returns the last name of the Person object.

// Shows the first and last names of Person object.
void Person::show() const {
    cout << "First Name: " << Person::getFirstName() << endl;
    cout << "Last Name: "  << Person::getLastName()  << endl;
}

// Sets the first and last names of Person object.
void Person::set() {
    cout << "Enter their first name: ";
    cin.getline(firstName, 100);

    cout << "Enter their last name: ";
    cin.getline(lastName, 100);
}

//friend function

//overload output operator
ostream &operator<<(ostream &os, const Person &p) {
    os << endl;
    os << p.firstName << endl
       << p.lastName  << endl;

    return os;
}
