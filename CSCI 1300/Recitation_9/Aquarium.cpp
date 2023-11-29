#include "Aquarium.h"
#include<fstream>
#include<sstream>
#include<string>
#include <cctype> 


using namespace std;


Aquarium::Aquarium()
{
    _aquarist = "";
    _gallons_used = 0;
    _tank_size=12;

}
Aquarium::Aquarium(string name)
{
    _aquarist = name;
    _gallons_used = 0;
    _tank_size=12;
    
}
Aquarium::Aquarium(string name, int size)
{
    _aquarist = name;
    _gallons_used = 0;
    _tank_size=size;
    
}


void Aquarium::setAquaristName(string name)
{
    _aquarist = name;
}
string Aquarium::getAquaristName() const
{
    return _aquarist;
}


void Aquarium::setGallonsUsed(int gallons)
{
    _gallons_used = gallons;
}

int Aquarium::getGallonsUsed() const
{
    return _gallons_used;
}

bool Aquarium::loadFish(string filename)
{
    ifstream reader(filename);
    string line = "";
    if (reader.is_open())
    {
        while (getline(reader, line))
        {
            if(line=="\n" || line =="") continue;
            string fish_name, gal_req;
            stringstream ss(line);
            Fish current_fish;

            // use stringstream to split the name and the gallons_required
            getline(ss, fish_name, ',');
            getline(ss, gal_req);
            current_fish.name = fish_name;
            int gal = stoi(gal_req);
            current_fish.gallons_required = gal;
            _available.push_back(current_fish);
        }
        return true;
    }
    return false;
}


bool Aquarium::removeFish(string name)
{
    
    string line;
    int i=0;
    while(i<_fish.size())
    {
        if(_fish.at(i).name==name)
        {
            for(int j=i;j<_fish.size()-1;j++)
            {
                _fish.at(j)=_fish.at(j+1);

            }
            _fish.pop_back();
            return true;
        }
        i++;
    }
    return false;
}

int Aquarium::getTankSizeGallons()
{
    return _tank_size;
}
void Aquarium::setTankSizeGallons(int size)
{
    _tank_size = size;
}
vector<Fish> Aquarium::getSelectedFish()
{
    return _selected;

}
int Aquarium::addFish(string name)
{
    bool a = false;
    int index=-1;
    for(int i=0;i<_available.size();i++)
    {
        if(compareStrings(name, _available.at(i).name))
        {
            index=i;
            a=true;
            break;
        }
    }
    if(index==-1) return -1;
    if(_available.at(index).gallons_required>_tank_size) return 0;

    _gallons_used-=_available.at(index).gallons_required;
    _selected.push_back(_available.at(index));
    return 1;

}





bool Aquarium::compareStrings(string s1, string s2)
{
    int len=0;
    if(s2.length()!=s1.length()) return false;

    len = s1.size();

    int c1;
    int c2;
    bool same=true;
    for(int i=0;i<len;i++)
    {
        c1=int(s1.at(i));
        c2=int(s2.at(i));
        if(toupper(c1)!=toupper(c2))
        {
            same=false;
            break;
        }
    }
    return same;

}
