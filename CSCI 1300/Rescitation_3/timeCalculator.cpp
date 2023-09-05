#include <iostream>

using namespace std;

int main()
{
    int input=0;
    int days=0;
    int hrs=0;
    int mins=0;
    int seconds=0;

    cout << "Enter seconds: " << endl;
    cin >>input;


    days=input/86400;
   int daysR= days%86400;

   hrs = daysR/3600;
   int hoursR = daysR%3600;

   mins = hoursR/60;
   seconds = daysR%60;


   cout << days << " Days " << hrs << " Hours " << mins << " Minutes " << seconds << " Seconds" << endl;


    return 0;
}