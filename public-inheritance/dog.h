/* dog.h
 * Creates Dog objects and manipulates methods.
 * 
 * @author  Michelle Adea
 * @version 03/30/2019
 */

#ifndef _DOG_H_
#define _DOG_H_
#include <iostream>
using namespace std;
#include "animal.h"

//declares public inheritance, Dog object is a Animal object
class Dog : public Animal {
    private:
        int AKCno;
        char *owner;
    public:
        Dog();
        ~Dog();
        Dog(int a, const char *nm, const char *snd, int w, int AKCno, const char *owner);
        Dog(const Dog &d);
        Dog &operator=(const Dog &d);
        Dog &operator=(const Animal &a);
        friend ostream &operator<<(ostream &os, const Dog &d);
        int getAKC() const;
        char * getOwner() const;
        void setAKC(int AKCno);
        void setOwner(char *owner);
        void speak() const;
};

#endif /* _DOG_H_ */