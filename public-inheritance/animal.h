/* animal.h
 * Creates Animal objects and manipulates methods.
 * 
 * @author  Michelle Adea
 * @version 03/25/2019
 */

#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
using namespace std;

class Animal {
    private:
        int age;
        char *name;
        char *sound;
    protected:
        int weight;
    public:
        Animal();
        ~Animal();
        Animal(int a, const char *nm, const char *snd, int w);
        Animal(const Animal &a);
        Animal &operator=(const Animal &a);
        friend ostream &operator<<(ostream &os, const Animal &a);
        int getAge() const;
        char * getName() const;
        char * getSound() const;
        int getWeight() const;
        void setAge(int a);
        void setName(const char *nm);
        void setSound(char *snd);
        void setWeight(int w);
        void speak();
};


#endif /* _ANIMAL_H_ */