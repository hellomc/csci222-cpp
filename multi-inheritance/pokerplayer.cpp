/**
 * Contains the functions for creating and manipulating
 * objects of PokerPlayer class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#include "pokerplayer.h"

// protected member functions

// Determines the card value of the PokerPlayer object.
int PokerPlayer::draw() {
    int cardNum;
    srand(time(0)); // sets time seed to random number
    cardNum = (rand() % 52) + 1;
    cardValue = cardNum;
    return cardValue;
}

// Shows the PokerPlayer's instance variable cardValue.
void PokerPlayer::showInfo() const {
    cout << "Card Value: " << PokerPlayer::getCard() << endl;
}

// Sets the PokerPlayer's private variable cardValue.
void PokerPlayer::setInfo() {
    cardValue = PokerPlayer::draw();
}

// public member functions

// Constructor for objects of PokerPlayer.
PokerPlayer::PokerPlayer():Person() {
    cardValue = PokerPlayer::draw();
}

// Deep copy constructor for objects of PokerPlayer.
PokerPlayer::PokerPlayer(const PokerPlayer &pp):Person(pp) {
    cardValue = pp.cardValue;
}

// Destructor for objects of class PokerPlayer.
PokerPlayer::~PokerPlayer() {}

// Deep assignment operator
PokerPlayer & PokerPlayer::operator=(const PokerPlayer &pp) {
    if (this == &pp)        // handles pp = pp
        return *this;
    
    Person::operator=(pp);  // invokes base class assignment
    cardValue = pp.cardValue;

    return *this;           // handles pp1 = pp2 = pp3
}

// Returns the card value of the PokerPlayer object.
int PokerPlayer::getCard() const {
    return cardValue;
}

// Shows the information of the object PokerPlayer.
void PokerPlayer::show() const {
    cout << endl;
    Person::show();
    PokerPlayer::showInfo();
}

// Sets the PokerPlayer object's instance variables.
void PokerPlayer::set() {
    Person::set();
    PokerPlayer::setInfo();
}

// friend function

// Overloads output operator.
ostream &operator<<(ostream &os, const PokerPlayer &pp) {
    os << endl;
    os << "First Name: " << pp.Person::getFirstName() << endl;
    os << "Last Name: "  << pp.Person::getLastName()  << endl;
    os << "Card Value: " << pp.PokerPlayer::getCard() << endl;
    return os;
}
