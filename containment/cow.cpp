/**
 * Creates objects of class Cow and contains methods that
 * manipulate Cow objects.
 * 
 * Originally written by Tony Smith
 * @author  Michelle Adea
 * @version 04/14/2019
 */

#include <iostream>
using namespace std;
#include "cow.h"

//default constructor
Cow::Cow()
{
    name = new char[1]; //make name point to null string
    strcpy(name, "");
    weight = 0.0;
}

Cow::Cow(const char * n, double w)
{
    name = new char[strlen(n) + 1]; //allocate memory
    strcpy(name, n);
    weight = w;
}

//new copy constructor to do deep copy
Cow::Cow(const Cow & c)
{
    name = new char[strlen(c.name) + 1]; //allocate memory
    strcpy(name, c.name);
    weight = c.weight;
}

//destructor
Cow::~Cow()
{
    delete [] name;	//delete [] to match constructors
}

void Cow::set(const char * n, double w)
{
    delete [] name; //careful to delete old string first
    name = new char[strlen(n) + 1]; //allocate memory
    strcpy(name, n);
    weight = w;
}

//overloading = to do deep assignment
Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)     //handle a = a
        return *this;
    delete [] name;     //delete old string first
    name = new char[strlen(c.name) + 1]; //allocate memory
    strcpy(name, c.name);
    weight = c.weight;
    return *this;       //handle a = b = c
}

//friends
ostream & operator<<(ostream & os, const Cow & c)
{
    os << c.name << "/" << c.weight;
    return os;
}
