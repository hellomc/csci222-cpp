/* main.cpp
 * Tests the newly created objects.
 * 
 * @author  Michelle Adea
 * @version 03/25/2019
 */

#include <iostream>
#include "animal.h"
#include "dog.h"
#include "cat.h"

int main(void)
{
    cout << "1.  test explicit initialization" << endl;
    Animal rhino(1000, "Neil", "Uuuuungh!", 10000);
    cout << rhino << endl << endl;

    cout << "2.  test copy constructor" << endl;
    Animal dino(rhino);
    dino.setName("Deano");
    cout << rhino << endl;
    cout << dino << endl << endl;

    cout << "3.  test assignment operator" << endl;
    Animal poco;
    poco = dino;
    poco.setName("Pokey");
    poco.setAge(10);
    cout << poco << endl << endl;

    cout << "4.  test copy constructor" << endl;
    Dog cockersp(5, "Spano", "Woof woof!", 35, 321, "Tom");
    Dog collie(cockersp);
    collie.setName("Collo");
    collie.setSound("Arf arf!");
    cout << cockersp << endl;
    cockersp.speak();
    cout << endl << collie << endl << endl;

    cout << "5.  test assignment operator" << endl;
    Cat persian(3, "Perry", "Purrrr!", 8, true, "John");
    Cat manx;
    manx = persian;
    manx.setName("Pinky");
    manx.setSound("Meoooowww!");
    manx.setOwns("Maxine");
    cout << persian << endl;
    cout << manx << endl;
    manx.speak();
    cout << endl << endl;

    cout << "6.  test dynamic binding" << endl;
    Animal * a1, * a2;
    a1 = &collie;
    a2 = &manx;
    a1->speak();
    cout << endl;
    a2->speak();
    cout << endl << endl;

    cout << "7.  test base = derived assignment" << endl;
    poco = manx;
    cout << poco << endl << endl;
/*
    cout << "8.  test derived = base assignment" << endl;
    Dog d1;
    d1 = rhino;
    cout << d1 << endl;
    Cat c1;
    c1 = rhino;
    cout << c1 << endl;
*/
    cin.get();

    return 0;
}
