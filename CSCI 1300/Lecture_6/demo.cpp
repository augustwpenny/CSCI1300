#include<iostream>
#include<iomanip>


using namespace std;

int main()
{
    double score=23;

    cout << fixed << setprecision(4); //sets the nunber of decimal values displayed. 
    // can be put in the same cout as the score/3 if it is put before

    cout << score/3 << endl;



    return 0;
}