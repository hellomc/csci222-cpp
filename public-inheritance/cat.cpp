/* cat.cpp
 * Defines Cat objects and manipulates methods.
 * 
 * @author  Michelle Adea
 * @version 03/31/2019
 */

#include "cat.h"

// default empty constructor
Cat::Cat() {
    this->lucky = false;
    this->owns = new char[1];
    strcpy(this->owns, ""); // initializes owns to empty char array
}

// destructor
Cat::~Cat() {
    delete [] this->owns;
}

// parameter constructor
Cat::Cat(int age, const char *name, const char *sound, int weight, bool lucky, const char *owns): Animal (age, name, sound, weight) {
    this->lucky = lucky;
    this->owns = new char[strlen(owns) + 1];
    strcpy(this->owns, owns);
}

// deep copy constructor
Cat::Cat(const Cat &c): Animal(c) {
    this->lucky = c.lucky;
    this->owns = new char[strlen(c.owns) + 1];
    strcpy(this->owns, c.owns);
}

// conversion constructor
Cat::Cat(const Animal &a, bool lucky, const char *owns): Animal (a) {
    this->lucky = lucky;
    this->owns = new char[strlen(owns) + 1];
    strcpy(this->owns, owns);
}

// deep assignment operator
Cat &Cat::operator=(const Cat &c) {
    if (this == &c)     // handles c = c
        return *this;
    
    Animal::operator=(c);   // invokes base class assignment
    this->lucky = c.lucky;
    delete [] this->owns;
    this->owns = new char[strlen(c.owns) + 1];
    strcpy(this->owns, c.owns);

    return *this;       // handles c1 = c2 = c3
}
/*
// assignment operator for Animal objects
Cat &Cat::operator=(const Animal &a) {
    if (this == &a)
        return *this;
    
    Cat::operator=(a);

}*/

// friend function
// overload << operator for Cat object
ostream &operator<<(ostream &os, const Cat &c) {
    operator<<(os, (const Animal &) c);
    c.speak();

    return os;
}

//getter and setter methods

//
bool Cat::getLucky() const {
    return this->lucky;
}
/*
char * boolLuckyCast(bool b) {
    char *luck = "lucky";
    char *noluck = "unlucky";
    return (b)? luck : noluck;
}*/

//
char * Cat::getOwns() const {
    return this->owns;
}

//
void Cat::setLucky(bool lucky) {
    this->lucky = lucky;
}

//
void Cat::setOwns(const char *owns) {
    delete [] this->owns;
    this->owns = new char[strlen(owns) + 1];
    strcpy(this->owns, owns);
}

/*
char * Cat::outLucky(bool lucky) const {
    char luck[] = "lucky";
    char noluck[] = "unlucky";
    if (lucky == 1) {
        return &luck;
    }

    return &noluck;
}*/

//
void Cat::speak() const {
    cout << Animal::getName() << " speaks: I'm a "
         << getLucky()        << " cat and I own "
         << getOwns()         << endl;
}