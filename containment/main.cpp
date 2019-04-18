/**
 * Controls the Rancher and Cow classes.
 * Tests that the objects have a 'has-a' relationship.
 * 
 * Originally written by Tony Smith
 * @author  Michelle Adea
 * @version 04/14/2019
 */

#include <iostream>
#include "rancher.h"
using namespace std;

int main(void) {
    //test all constructors
    Rancher r1;
    cout << "r1" << endl;
    cout << r1 << endl << endl;

    Rancher r2("John Wayne");
    cout << "r2" << endl;
    cout << r2 << endl << endl;

    List l;
    Cow c1("Cow c1", 11.11);

    l.add(c1);
    Rancher r3(l);
    cout << "r3" << endl;
    cout << r3 << endl << endl;

    Rancher r4("R4", l);
    cout << "r4" << endl;
    cout << r4 << endl << endl;

    //test some Rancher member functions
    if (r2.isEmpty())
        cout << "r2 has no cows" << endl;
    Cow c2("Cow c2", 22.22), c3("Cow c3", 33.33), c4("Cow c4", 44.44);
    r2.add(c1);
    r2.add(c2);
    r2.add(c3);
    cout << "r2 is now" << endl;
    cout << r2 << endl;
    cout << "# of cows: " << r2.countListItems() << endl << endl;

    //test Rancher deep copy constructor
    Rancher r5(r2);
    r5.add(c4);

    //test Rancher deep assignment operator
    r1 = r2;
    c1 = r1.remove();

    cout << "r1 is now" << endl;
    cout << r1 << endl << endl;
    cout << "r2 is now" << endl;
    cout << r2 << endl << endl;
    cout << "r5 is now" << endl;
    cout << r5 << endl << endl;

    cin.get();

    return 0;
}