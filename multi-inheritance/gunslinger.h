/**
 * Contains the function declarations for objects of Gunslinger class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#ifndef _GUNSLINGER_H_
#define _GUNSLINGER_H_
#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>
#include "person.h"

class Gunslinger: virtual public Person {
    private:
        double drawtime;    // how fast the gunslinger draws their gun
        int notches;        // the number of notches on the gunslinger's gun
    protected:
        double draw();
        int notch();
        void showInfo() const;
        void setInfo();
    public:
        Gunslinger();
        Gunslinger(const Gunslinger &gs);
        ~Gunslinger();
        Gunslinger &operator=(const Gunslinger &s);
        double getDraw() const;
        int getNotches() const;
        void show() const;
        void set();
        friend ostream &operator<<(ostream &os, const Gunslinger &gs);
};

#endif /* _GUNSLINGER_H_ */