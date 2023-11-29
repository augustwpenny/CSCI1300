#include <iostream>
#include "Animal.h"
using namespace std;

// default constructor
Animal::Animal()
{
    _name = "unknown";
    _age = 0;
}

// parameterized constructor
Animal::Animal(string name, int age)
{
    _name = name;
    _age = age;
}

// getter for name
string Animal::getName() const
{
    return _name;
}

// getter for age
int Animal::getAge() const
{
    return _age;
}

// setter for name
void Animal::setName(string name)
{
    _name = name;
}

// setter for age
void Animal::setAge(int age)
{
    _age = age;
}