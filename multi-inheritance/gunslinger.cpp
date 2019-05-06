/**
 * Contains the functions for creating and manipulating objects of
 * Gunslinger class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#include "gunslinger.h"

// protected member functions

// Sets the drawtime of the Gunslinger object.
double Gunslinger::draw() {
    double drawValue;
    srand(time(0));
    drawValue = (rand() % 100) + 1;
    drawValue /= 100;
    return drawValue;
}

// Sets the notches of the Gunslinger object.
int Gunslinger::notch() {
    int notchValue;
    notchValue = (rand() & 10) + 1;
    return notchValue;
}

// Sets the Gunslinger object's instance variables.
void Gunslinger::setInfo() {
    drawtime = Gunslinger::draw();
    notches = Gunslinger::notch();
}

// Shows the Gunslinger's instance variables.
void Gunslinger::showInfo() const {
    cout << "Drawtime: " << setprecision(2) << fixed << Gunslinger::getDraw() << endl;
    cout << "Notches: "  << Gunslinger::getNotches() << endl;
}

// public member functions

// Constructor for objects of Gunslinger.
Gunslinger::Gunslinger():Person() {
    drawtime = 0.00;
    notches = 0;
}

// Deep copy constructor for objects of Gunslinger.
Gunslinger::Gunslinger(const Gunslinger &gs):Person(gs) {
    drawtime = gs.drawtime;
    notches = gs.notches;
}

// Destructor for objects of Gunslinger.
Gunslinger::~Gunslinger() {}

// Returns the drawtime of the Gunslinger object.
double Gunslinger::getDraw() const {
    return drawtime;
}

// Returns the number of notches of the Gunslinger object.
int Gunslinger::getNotches() const {
    return notches;
}

// Shows the information of the Gunslinger object.
void Gunslinger::show() const {
    cout << endl;
    Person::show();
    Gunslinger::showInfo();
}

// Sets the Gunslinger object's information.
void Gunslinger::set() {
    Person::set();
    Gunslinger::setInfo();
}

//friend function

//overload output operator
ostream &operator<<(ostream &os, const Gunslinger &gs) {
    os << endl;
    os << "First Name: " << gs.Person::getFirstName() << endl;
    os << "Last Name: "  << gs.Person::getLastName()  << endl;
    os << "Drawtime: "   << setprecision(2) << fixed << gs.Gunslinger::getDraw() << endl;
    os << "Notches: "    << gs.Gunslinger::getNotches() << endl;
    return os;
}
