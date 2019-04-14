/* animal.cpp
 * Defining the Animal objects and methods.
 * 
 * @author  Michelle Adea
 * @version 03/30/2019
 */

#include "animal.h"

// default empty constructor
Animal::Animal() {
    this->age = 0;
    this->name = new char[1];     //name points to null string
    strcpy(name, "");
    this->sound = new char[1];    //sound points to null string
    strcpy(sound, "");
    this->weight = 0;
}

// destructor
Animal::~Animal() {
    delete [] this->name;         //unallocates memory
    delete [] this->sound;        //unallocates memory
}

// default params constructor
Animal::Animal(int age, const char *name, const char *sound, int weight) {
    this->age = age;
    this->name = new char[strlen(name) + 1];    //allocate memory
    strcpy(this->name, name);
    this->sound = new char[strlen(sound) + 1];  //allocate memory
    strcpy(this->sound, sound);
    this->weight = weight;
}

// deep copy constructor
Animal::Animal(const Animal &a) {
    this->age = a.age;
    this->name = new char[strlen(a.name) + 1];
    strcpy(name, a.name);
    this->sound = new char[strlen(a.sound) + 1];
    strcpy(sound, a.sound);
    this->weight = a.weight;
}

// deep assignment operator
Animal & Animal::operator=(const Animal &a) {
    if (this == &a)     //handles a = a
        return *this;
    
    this->age = a.age;
    delete [] this->name;     //deletes old string name first
    this->name = new char[strlen(a.name) + 1];
    strcpy(name, a.name);
    delete [] this->sound;    //deletes old string sound first
    this->sound = new char[strlen(a.sound) + 1];
    strcpy(sound, a.sound);
    this->weight = a.weight;
    
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

// getter and setter methods

// Returns the Animal object's age property.
int Animal::getAge() const {
    return this->age;
}

// Returns the Animal object's name property.
char * Animal::getName() const {
    return this->name;
}

// Returns the Animal object's sound property.
char * Animal::getSound() const {
    return this->sound;
}

// Returns the Animal object's weight property.
int Animal::getWeight() const {
    return this->weight;
}

// Updates the Animal objects age property to parameter int a.
void Animal::setAge(int age) {
    this->age = age;
}

// Updates the Animal object's name property to parameter char *name.
void Animal::setName(const char *name) {
    delete [] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Updates the Animal object's sound property to @param *snd.
void Animal::setSound(const char *sound) {
    delete [] this->sound;
    this->sound = new char[strlen(sound) + 1];
    strcpy(this->sound, sound);
}

// Updates the Animal object's weight property to @param w.
void Animal::setWeight(int weight) {
    this->weight = weight;
}

// Outputs the Animal object's name and sound.
void Animal::speak() {
    cout << getName() << " speaks: " << getSound() << endl;
}