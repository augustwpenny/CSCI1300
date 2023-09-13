#include <iostream>
using namespace std;

int main()
{
    int temperature = 50; 

    if (temperature >= 85) {
        cout << "It's a hot day!";
    }
    else if (temperature > 60 && temperature < 85) {
        cout << "It's a pleasant day.";
    }
    // Fill in the below line
    else if (temperature <= 60 && temperature >= 40){
        cout << "It's a cool day.";
    }
    else {
        cout << "It's a cold day.";
    }

    return 0;
}