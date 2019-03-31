/* dog.cpp
 * Defining the Dog objects and methods.
 * 
 * @author  Michelle Adea
 * @version 03/30/2019
 */

#include "dog.h"

// default empty constructor
Dog::Dog() {
    this->AKCno = 0;
    this->owner = new char[1];
    strcpy(owner, "");
}

// destructor
Dog::~Dog() {
    delete [] owner;
}

// param constructor
Dog::Dog(int age, const char *name, const char *sound, int weight, int AKCno, const char *owner): Animal(age, name, sound, weight) {
    this->AKCno = AKCno;
    this->owner = new char[strlen(owner) + 1];
    strcpy(this->owner, owner);
}

// deep copy constructor
Dog::Dog(const Dog &d) : Animal(d) {
    this->AKCno = d.AKCno;
    this->owner = new char[strlen(d.owner) + 1];
    strcpy(owner, d.owner);
}

// deep assignment operator
Dog &Dog::operator=(const Dog &d) {
    if (this == &d)     // handles d = d
        return *this;

    //how to do delete animal constructor part
    //~Animal();
    this->AKCno = d.AKCno;
    delete [] owner;
    this->owner = new char[strlen(d.owner) + 1];
    strcpy(owner, d.owner);

    return *this;       // handles d1 = d2 = d3
}

// friend function
// overload << output operator
ostream &operator<<(ostream &os, const Dog &d) {
    os << (const Animal &) d << endl;
    d.speak();
    
    return os;
}

// getter and setter methods
// Returns the AKC number of the Dog object.
int Dog::getAKC() const {
    return this->AKCno;
}

// Returns the name of the owner of the Dog object.
char * Dog::getOwner() const {
    return this->owner;
}

// Assigns the AKC number of the Dog object to parameter int AKCno.
void Dog::setAKC(int AKCno) {
    this->AKCno = AKCno;
}

// Assigns the name of the owner of the Dog object to parameter char *owner.
void Dog::setOwner(char *owner) {
    this->owner = owner;
}

// Outputs the Dog object's name and sound.
void Dog::speak() const {
    cout << Animal::getName() << " speaks: I'm a dog, my AKC # is "
         << getAKC() << " and my owner is " << getOwner() << endl;
}