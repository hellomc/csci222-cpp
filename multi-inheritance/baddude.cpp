/**
 * Contains the functions for creating and manipulating
 * objects of BadDude class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#include "baddude.h"

// public member functions

// Constructor for objects of BadDude
BadDude::BadDude():Gunslinger(), PokerPlayer() {}

// Deep copy constructor for objects of BadDude
BadDude::BadDude(const BadDude &bd):Gunslinger(bd), PokerPlayer(bd) {}

// Destructor for objects of BadDude.
BadDude::~BadDude() {}

// Returns the drawtime of the BadDude object.
double BadDude::gdraw() {
    return Gunslinger::draw();
}

// Returns the card value drawn for the BadDude object.
int BadDude::cdraw() {
    return PokerPlayer::draw();
}

// Shows the information of the BadDude object.
void BadDude::show() const {
    cout << endl;
    Person::show();
    Gunslinger::showInfo();
    PokerPlayer::showInfo();
}

// Sets the information of the BadDude object.
void BadDude::set() {
    Person::set();
    Gunslinger::setInfo();
    PokerPlayer::setInfo();
}

//friend function

//overload output operator
ostream &operator<<(ostream &os, const BadDude &bd) {
    os << endl;
    os << "First Name: " << bd.Person::getFirstName() << endl;
    os << "Last Name: "  << bd.Person::getLastName()  << endl;
    os << "Drawtime: "   << setprecision(2) << fixed << bd.Gunslinger::getDraw() << endl;
    os << "Notches: "    << bd.Gunslinger::getNotches() << endl;
    os << "Card Value: " << bd.PokerPlayer::getCard() << endl;
    return os;
}
