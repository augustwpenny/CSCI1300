#include<cmath>
#include<string>
#include<iostream>
#include"Planet.h"

using namespace std;

int maxRadius(Planet planetArr[], const int SIZE);

// int main()
// {
//     Planet p1 = Planet();
//     cout << "Name: " << p1.getName() << " Radius: " << p1.getRadius() << " Volume: " << p1.getVolume() << endl;
//     p1.setName("Mars");
//     p1.setRadius(6378);
//     cout << "Name: " << p1.getName() << " Radius: " << p1.getRadius() << " Volume: " << p1.getVolume() << endl;
//     Planet Mars = Planet("Mars", 3390);
//     Planet Earth = Planet("Earth",6378);
//     Planet planets[4] = {Earth, Mars,p1};
//     cout << maxRadius(planets, 3);


// }
int maxRadius(Planet planetArr[], const int SIZE)
{
    if(SIZE<=0) return -1;
    int index=0;
    double max=planetArr[0].getRadius();
    for(int i=0;i<SIZE;i++)
    {
        if(planetArr[i].getRadius()>max)
        {
            index=i;
            max=planetArr[i].getRadius();
        }
    }
    return index;
}

