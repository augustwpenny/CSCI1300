#include<iostream>
#include<iomanip>
#include<cassert>


using namespace std;



bool isVowel(char letter)
{
    if(letter=='a' || letter=='e' || letter=='i' || letter=='o' || letter=='u' || letter=='A' || letter=='E' || letter=='I' || letter=='O' || letter=='U'){
        return true;
    }
    else
    {
        return false;
    }

}



double areaCircle(double radius)
{
    return 3.14*(radius*radius);
}




int main()
{
    assert(areaOfCircle(10)==314);

    
}


// Function to check if the input character is a vowel or not 
