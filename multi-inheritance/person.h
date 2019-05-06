/**
 * Contains the function declarations for objects of Person class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
using namespace std;

class Person // virtual base class
{
    private:
        char * firstName;
        char * lastName;
    public:
        Person();
        Person(const Person &p);
        virtual ~Person();
        Person &operator=(const Person &p);
        char * getFirstName() const;
        char * getLastName() const;
        virtual void show() const;
        virtual void set();
        friend ostream &operator<<(ostream &os, const Person &p);
};

#endif /* _PERSON_H_ */