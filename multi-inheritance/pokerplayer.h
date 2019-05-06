/**
 * Contains the function declarations for objects of PokerPlayer class.
 * 
 * @author  Michelle Adea
 * @version 05/05/2019
 */

#ifndef _POKERPLAYER_H_
#define _POKERPLAYER_H_
#include <iostream>
#include <ctime>
#include <math.h>
#include "person.h"

class PokerPlayer: virtual public Person {
    private:
        int cardValue;
    protected:
        int draw();
        void showInfo() const;
        void setInfo();
    public:
        PokerPlayer();
        PokerPlayer(const PokerPlayer &pp);
        ~PokerPlayer();
        PokerPlayer &operator=(const PokerPlayer &pp);
        int getCard() const;
        void show() const;
        void set();
        friend ostream &operator<<(ostream &os, const PokerPlayer &pp);
};

#endif /* _POKERPLAYER_H_ */