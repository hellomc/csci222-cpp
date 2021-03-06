/* animal.h
 * Creates Animal objects and manipulates methods.
 * 
 * @author  Michelle Adea
 * @version 03/31/2019
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
        virtual ~Animal();
        Animal(int a, const char *nm, const char *snd, int w);
        Animal(const Animal &a);
        Animal &operator=(const Animal &a);
        friend ostream &operator<<(ostream &os, const Animal &a);
        int getAge() const;
        char * getName() const;
        char * getSound() const;
        int getWeight() const;
        void setAge(int age);
        void setName(const char *name);
        void setSound(const char *sound);
        void setWeight(int w);
        virtual void speak();
};


#endif /* _ANIMAL_H_ */