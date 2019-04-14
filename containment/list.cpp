/**
 * Creates objects of the List class and contains methods
 * that manipulate List objects.
 * 
 * @author  Michelle Adea
 * @version 04/14/2019
 */

#include "list.h"
#include <iostream>
using namespace std;

//private

//traverse the list and copy to *this. *this list guaranteed to be empty
void List::copy_list(const List &l) {
    record * p = l.front; // list's first node
    record * q;
    while (p) {
        q = new record;
        q->item = p->item;
        q->next = 0;
        // checks if list is empty
        if (front == 0)
            front = q;
        else
            rear->next = q; // assigns the last node of the list to point to q
        rear = q;
        p = p->next; // assigns the next node in the list to p
    }
}

void List::delete_list() {
    record *p;
    while (front) {
        p = front;
        front = front->next;
        delete p;
    }
    rear = 0; // assigns 0 to last node in list
}

//public

List::List() {
    front = rear = 0;
}

// deep copy ctor
List::List(const List &l) {
    front = rear = 0;
    copy_list(l);
}

List::~List() {
    delete_list();
}

// Creates a new record and adds it to the rear of the list.
void List::add(const Cow &c) {
    //initialize new record node
    record *p = new record;
    // assigns values to info and next fields of node
    p->item = c;
    p->next = 0;
    //appends new record p to the rear of the list
    if (front == 0)
        front = p;
    else
        rear->next = p;
    rear = p;
}

Cow List::remove() const {
    if (isEmpty()) {
        cerr << "WARNING: Cannot remove from an empty list." << endl;
        return Cow();
    }
    else {
        record *p = front;
        p = front->next;
        Cow temp = p->item;
        delete p;
        return temp;
    }
}

int List::countTotal() const {
    int count = 0;
    record *p = front;
    while (p) {
        ++count;
        p = p->next;
    }
    return count;
}

bool List::isEmpty() const {
    return front == 0;
}

List & List::operator=(const List &l) {
    if (this == &l)     // handles l = l
        return *this;
    
    delete_list();
    copy_list(l);
    return *this;   // handles l1 = l2 =l3
}

ostream & operator<<(ostream &os, const List &l) {
    record *p = l.front;
    while (p) {
        os << p->item << ' ';
        p = p->next;
    }

    return os;
}