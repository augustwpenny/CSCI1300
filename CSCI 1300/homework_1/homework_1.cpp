#include <iostream>
using namespace std;

int main()
{
    int numIronCoins;
    cout << " Enter the number of iron coins:" << endl;
    cin >> numIronCoins;

    int gold = numIronCoins/897;
    int goldR = numIronCoins%897;
    
    int silver = goldR/39;
    int silverR = goldR%39;

    int bronze = silverR/3;
    int bronzeR = silverR%3;

    cout << gold  << " gold coin(s) " << silver << " silver coin(s) " << bronze << " bronze coin(s) " << bronzeR << " iron coin(s) " << endl;



  
    return 0;
}