/**
 * Declares all functions for the Cow class.
 * 
 * Originally Written by Tony Smith
 * Commented by Michelle Adea
 * @version 04/13/2019
 */

#ifndef _COW_H_
#define _COW_H_
#include <iostream>
using namespace std;

class Cow
{
private:
    char * name;
    double weight;
public:
    Cow();
    Cow(const char * n, double w = 0.0);
    Cow(const Cow & c);
    ~Cow();
    void set(const char * n, double w = 0.0);
    Cow & operator=(const Cow & c);
    friend ostream & operator<<(ostream & os, const Cow & c);
};

#endif /* _COW_H */