#ifndef AQUARIUM
#define AQUARIUM

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Fish
{
    string name;
    int gallons_required;
};

class Aquarium {
    private:
        string _aquarist;
        int _gallons_used;
        vector<Fish> _fish;
        int _tank_size;
        vector<Fish> _available;
        vector<Fish> _selected;
    bool compareStrings(string, string);
        
    public:

    Aquarium();
    Aquarium(string);
    Aquarium(string, int);

    void setAquaristName(string);
    string getAquaristName() const;

    void setGallonsUsed(int);
    int getGallonsUsed() const;

    bool loadFish(string);
    bool removeFish(string);

    int getTankSizeGallons();
    void setTankSizeGallons(int);
    vector<Fish> getSelectedFish();
    int addFish(string);

};
#endif