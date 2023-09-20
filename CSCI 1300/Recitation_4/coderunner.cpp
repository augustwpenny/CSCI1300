#include <iostream>
#include <cmath>
using namespace std;


double fertlilze(double stock, double amount)
{
    if (stock < 0 && amount < 0)
    {
        cout << "Amounts must be positive" << endl;
        return 0.0;
    }
    if (stock<amount)
    {
        cout << "This is not possible. Stock is too low" << endl;
    }

    double ret=stock-amount;
    return ret;
}


double restock(double stock, double amount)
{
    if (stock < 0 && amount < 0)
    {
        cout << "Amounts must be positive" << endl;
        return 0.0;
    }
    
    double ret=stock+amount;
    return ret;

}
