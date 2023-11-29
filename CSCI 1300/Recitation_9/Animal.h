#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;

class Animal
{
    // data member
    private:  
        string _name;
        int _age;

    public:
        Animal();
        Animal(string, int);

        string getName() const;
        int getAge() const;

        void setName(string);
        void setAge(int);
};
#endif