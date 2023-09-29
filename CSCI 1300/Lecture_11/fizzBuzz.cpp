#include<iostream>
#include<cassert>

using namespace std;

string fizzBuzz(int number)
{
    

    if(number%3==0 && number%5==0)
    {
        return "fizzbuzz";
    }
    if(number%3==0)
    {
        return "fizz";
    }
    if(number%5==0)
    {
        return "buzz";
    }

    return to_string(number);
    
}


int main()
{
    assert(fizzBuzz(15)=="fizzbuzz");
    cout << "15" << endl;

    assert(fizzBuzz(3)=="fizz");
    cout << "3" << endl;

    assert(fizzBuzz(5)=="buzz");
    cout << "5" << endl;

    assert(fizzBuzz(7)=="7");
    cout << "7" << endl;
}