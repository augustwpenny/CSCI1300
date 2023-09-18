#include<iostream>
#include<iomanip>


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

bool isValidInt(int I)
{   //sample if statement but can be changed for any condition
    if(I < 0){
        return true;
    }
    else{
        return false;
    }
}



int main()
{
    char v1;
    char v2;
    char v3;
    char v4;

    cin >> v1;
    cin >> v2;
    cin >> v3;
    cin >> v4;

    bool v1t=isVowel(v1);
    bool v2t=isVowel(v2);
    bool v3t=isVowel(v3);
    bool v4t=isVowel(v4);




    cout << v1t << v2t << v3t <<  v4t << endl;

}


// Function to check if the input character is a vowel or not 
