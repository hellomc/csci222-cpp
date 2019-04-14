/**
 * Declares all functions for the Rancher class.
 * 
 * @author  Michelle Adea
 * @version 04/14/2019
 */

#ifndef _RANCHER_H_
#define _RANCHER_H_
#include <iostream>
#include "list.h"
using namespace std;

class Rancher {
    private:
        char *name; //Use of dynamic memory allocation
        List cows;  //List contained within Rancher
    public:
        // default constructor, default argument for List class
        Rancher(const char *n = "", const List &l = List());
        Rancher(const List &animals); //construct Rancher from List
        Rancher(const Rancher &r); //deep copy constructor
        ~Rancher();
        //getter and setter
        char * getName() const;
        List getList() const;
        void add(const Cow &c);
        Cow remove() const;
        int count() const;
        bool isEmpty() const;
        Rancher &operator=(const Rancher &r);
        friend ostream & operator <<(ostream &os, const Rancher &r);
};

#endif /* _RANCHER_H_ */