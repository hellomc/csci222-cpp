/**
 * Controls the multiple inheritance tests of the Person, Gunslinger,
 * PokerPlayer, and BadDude classes.
 * 
 * @author  Michelle Adea
 * @id      008184070
 * @version 05/05/2019
 */

#include "person.h"
#include "gunslinger.h"
#include "pokerplayer.h"
#include "baddude.h"

const int MAX = 5;

//Lab 5.cpp - multiple inheritance
int main()
{
    Person * gang[MAX];	//array of pointers-to-base-class

    char choice;
	int count;
    for (count = 0; count < MAX; ++count) {
        cout << "Enter the gang category" << endl
             << "o: ordinary person  g: gunslinger" << endl
             << "p: poker player     b: bad dude    q: quit" << endl;
        cout << "Enter o, g, p, b or q: ";
        cin >> choice;
        
        //validate choice
        while (strchr("ogpbq", choice) == NULL) {
            cout << "Enter o, g, p, b or q: ";
            cin >> choice;
        }
        
        if (choice == 'q') {
			cin.get();  //discard Enter key from stdin
            break;
		}
        
        switch (choice) {
        case 'o' :
            gang[count] = new Person;
            break;
        case 'g' :
            gang[count] = new Gunslinger;
            break;
        case 'p' :
            gang[count] = new PokerPlayer;
            break;
        case 'b' :
            gang[count] = new BadDude;
            break;
        }

        cin.get();  //discard Enter key from stdin
        gang[count]->set();
    }

    cout << endl << "Here is your gang:" << endl;
	int i;
    for (i = 0; i < count; ++i)
        gang[i]->show();
    
    //temp
    for (i = 0; i < count; ++i)
        cout << gang[i];

    for (i = 0; i < count; ++i)
        delete gang[i];

    cin.get();

    return 0;
}
