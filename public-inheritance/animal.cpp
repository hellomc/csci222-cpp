/* animal.cpp
 * Defining the Animal objects and methods.
 * 
 * @author  Michelle Adea
 * @version 03/25/2019
 */

#include "animal.h"

// default constructor
Animal::Animal() {
    age = 0;
    name = new char[1];     //name points to null string
    strcpy(name, "");
    sound = new char[1];    //sound points to null string
    strcpy(sound, "");
    weight = 0;
}

// destructor
Animal::~Animal() {
    delete [] name;         //unallocates memory
    delete [] sound;        //unallocates memory
}

// constructor
Animal::Animal(int a, const char *nm, const char *snd, int w) {
    age = a;

    name = new char[strlen(nm) + 1];    //allocate memory
    strcpy(name, nm);

    sound = new char[strlen(snd) + 1];  //allocate memory
    strcpy(sound, snd);

    weight = w;
}

// deep copy constructor
Animal::Animal(const Animal &a) {
    age = a.age;
    name = new char[strlen(a.name) + 1];
    strcpy(name, a.name);
    sound = new char[strlen(a.sound) + 1];
    strcpy(sound, a.sound);
    weight = a.weight;
}

// deep assignment operator
Animal & Animal::operator=(const Animal &a) {
    if (this == &a)     //handles a = a
        return *this;
    
    age = a.age;
    delete [] name;     //deletes old string name first
    name = new char[strlen(a.name) + 1];
    strcpy(name, a.name);
    delete [] sound;    //deletes old string sound first
    sound = new char[strlen(a.sound) + 1];
    strcpy(sound, a.sound);
    weight = a.weight;
    
    return *this;       //handles a = b = c
}

// friend functions
// overload << output operator
ostream &operator<<(ostream &os, const Animal &a) {
    os << a.getName()   << " says "
       << a.getSound()  << " I weigh "
       << a.getWeight() << " pounds, and I'm "
       << a.getAge()    << " years old!"
       << endl;

    return os;
}

// Returns the Animal object's age property.
int Animal::getAge() const {
    return age;
}

// Returns the Animal object's name property.
char * Animal::getName() const {
    return name;
}

// Returns the Animal object's sound property.
char * Animal::getSound() const {
    return sound;
}

// Returns the Animal object's weight property.
int Animal::getWeight() const {
    return weight;
}

// Updates the Animal objects age property to @param a.
void Animal::setAge(int a) {
    age = a;
}

// Updates the Animal object's name property to @param *nm.
void Animal::setName(const char *nm) {
    delete [] name;
    name = new char[strlen(nm) + 1];
    strcpy(name, nm);
}

// Updates the Animal object's sound property to @param *snd.
void Animal::setSound(char *snd) {
    delete [] sound;
    sound = new char[strlen(snd) + 1];
    strcpy(sound, snd);
}

// Updates the Animal object's weight property to @param w.
void Animal::setWeight(int w) {
    weight = w;
}

// Outputs the Animal object's name and sound.
void Animal::speak() {
    cout << getName() << " speaks: " << getSound() << endl;
}