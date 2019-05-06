/**
 * Contains the function declarations for objects of BadDude class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#ifndef _BADDUDE_H_
#define _BADDUDE_H_
#include "gunslinger.h"
#include "pokerplayer.h"

class BadDude: public Gunslinger, public PokerPlayer {
    public:
        BadDude();
        BadDude(const BadDude &bd);
        ~BadDude();
        BadDude &operator=(const BadDude &bd);
        double gdraw();
        int cdraw();
        void show() const;
        void set();
        friend ostream &operator<<(ostream &os, const BadDude &bd);
};

#endif /* _BADDUDE_H_ */