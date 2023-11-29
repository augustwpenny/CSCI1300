#include<cmath>
#include<string>
#include<iostream>
#include"Planet.h"
#include<math.h>
#include<cmath>

using namespace std;


    Planet::Planet()
    {
        _planet_name = "";
        _planet_radius = 0.0;
    }
    Planet::Planet(string name, double radius)
    {
        _planet_name = name;
        _planet_radius = radius;
    }
    string Planet::getName()
    {
        return _planet_name;
    }
    void Planet::setName(string name)
    {
        _planet_name=name;
    }
    double Planet::getRadius()
    {
        return _planet_radius;
    }
    void Planet::setRadius(double radius)
    {
        _planet_radius = radius;
    }
    double Planet::getVolume()
    {
        double a = 4.0/3.0;
        double c = pow(_planet_radius, 3);
        return a*M_PI*c;
    }
