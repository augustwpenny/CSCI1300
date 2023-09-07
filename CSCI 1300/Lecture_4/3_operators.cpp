#include <iostream>
using namespace std;

int main()
{
    double time = 0.0;
    cout << "enter the time: " << endl;
    cin >> time;


    if (time >= 3.20)
    {
        cout << "class is over!" << endl;
        
    }
    else
    {
        // do something else
        cout << "class is not over" << endl;
    }

    return 0;
    
}