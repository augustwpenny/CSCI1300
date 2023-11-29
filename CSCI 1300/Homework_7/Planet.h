#ifndef PLANET_H
#define PLANET_H

using namespace std;
#include<string>


class Planet
{
    public:
    Planet();
    Planet(string, double);
    string getName();
    void setName(string);
    double getRadius();
    void setRadius(double);
    double getVolume();

    

    private:

    string _planet_name;
    double _planet_radius;

};

#endif