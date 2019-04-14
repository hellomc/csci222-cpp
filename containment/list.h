/**
 * Declares all functions for the List class.
 * 
 * @author  Michelle Adea
 * @version 04/14/2019
 */

#ifndef _LIST_H_
#define _LIST_H_
#include "cow.h"
typedef Cow Item;
 
//List of Items implemented as linked list of Recs,
//each Rec contains an item of type Item
struct record {
    Item item;
    record * next;
};

class List
{
private:
    record * front;     //pointer to front of List
    record * rear;
    void copy_list(const List &l);
    void delete_list();
public:
    //List *cows; // declares cows as a pointer to a List
    List();
    List(const List &l);
    ~List();
    //getterandsetter
    void add(const Cow &c);
    Cow remove() const;
    int countTotal() const;
    bool isEmpty() const;
    List & operator=(const List &l);
    friend ostream & operator<<(ostream &os, const List &l);
};

#endif /* _LIST_H_ */
