#include <iostream>
using namespace std;

int main()
{
    int waterDrank=0;

    cout << "Enter how much water you have drank today? (fl oz)" << endl;

    cin >> waterDrank;

    if (waterDrank >= 64)
    {
        cout << "You’ve hit your goal for the day! Great job getting hydrated!" << endl;
    }
    else if(waterDrank > 32 && waterDrank < 64)
    {
        cout << "You’re doing great, but you’re still halfway to your goal! Get that water in! You have " << 64-waterDrank << " fl oz left to drink" << endl;
    }
    else 
    {
        cout <<    "You’re very, very dehydrated! Get that water in! You have " << 64-waterDrank << " fl oz left to drink." << endl;
    }



    return 0;
}


// #include <iostream>
// using namespace std;

// int main()
// {
//    double budget=0.0;
//    char seat='a';
   
//    cout << "What is your budget?" << endl;
//    cin >> budget;
   
//    cout << "Which of these seats would you like to take (G, B, P or O)?"
//    cin >> seat;
   
//    if(budget<0 || (seat !='G' && seat !='B' && seat !='P' && seat !='O'))
//    {
//        cout << "bad" << endl;
//    }

//     return 0;
// }