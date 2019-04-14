/* cat.h
 * Creates Cat objects and manipulates methods.
 * 
 * @author  Michelle Adea
 * @version 03/31/2019
 */

#ifndef _CAT_H_
#define _CAT_H_
#include <iostream>
#include <stdbool.h>
using namespace std;
#include "animal.h"

//declares public inheritance, Cat object is a Animal object
class Cat : public Animal {
    private:
        bool lucky;
        char *owns;
    public:
        Cat();
        ~Cat();
        Cat(int age, const char *name, const char *sound, int weight, bool lucky, const char *owns);
        Cat(const Cat &c);
        Cat(const Animal &c, bool lucky = false, const char *owns = "");
        Cat &operator=(const Cat &c);
        //Cat &operator=(const Animal &a);
        friend ostream &operator<<(ostream &os, const Cat &c);
        bool getLucky() const;
        //char * boolLuckyCast(bool b);
        char * getOwns() const;
        void setLucky(bool lucky);
        void setOwns(const char *owns);
        char * outLucky(bool lucky) const;
        void speak() const;
};

#endif /* _CAT_H_ */