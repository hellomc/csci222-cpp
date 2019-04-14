/**
 * Creates objects of the Rancher class and contains methods
 * that manipulate Rancher objects.
 * 
 * @author  Michelle Adea
 * @version 04/14/2019
 */

#include "rancher.h"

Rancher::Rancher(const char *n, const List & animals) : cows(animals) {
    this->name = new char[strlen(n) + 1];
    strcpy(this->name, n);
}

Rancher::Rancher(const List &animals) : cows(animals) {
    this->name = new char[1];
    strcpy(this->name, "");
}

Rancher::Rancher(const Rancher &r) {
    this->name = new char[strlen(r.name + 1)];
    strcpy(this->name, r.name);
    this->cows = r.cows; // uses List deep assignment operator
}

Rancher::~Rancher() {
    delete [] this->name;
    // List object auto destroyed
}

char * Rancher::getName() const {
    return this->name;
}

List Rancher::getList() const{
    return this->cows;
}

void Rancher::add(const Cow &c) {
    this->cows.add(c);
}

Cow Rancher::remove() const {
    return this->cows.remove();
}

int Rancher::count() const {
    return this->cows.countTotal();
}

bool Rancher::isEmpty() const {
    return this->cows.isEmpty();
}

Rancher &Rancher::operator=(const Rancher &r) {
    if (this == &r)     //handles r = r
        return *this;
    //delete old name, allocates new memory, copies
    delete [] this->name;
    this->name = new char[strlen(r.name) + 1];
    strcpy(this->name, r.name);

    return *this;       //handles r1 = r2 = r3
}

ostream & operator <<(ostream &os, const Rancher &r) {
    os << "Rancher: " << r.name << "\n"
       << "Cows: "    << r.cows << endl;

    return os;
}