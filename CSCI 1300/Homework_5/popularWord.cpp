#include<iostream>
#include<array>
#include<string>

using namespace std;

void mostPopularWord(string words[], const int WORD_SIZE);


// int main()
// {
//     const int WORDS_SIZE = 6;
//     string words[WORDS_SIZE] = {"apple", "apple", "foo", "bar", "apple", "code"};
//     mostPopularWord(words, WORDS_SIZE);
// }



void mostPopularWord(string words[], const int WORD_SIZE)
{
    int popIndex=0;
    int mentions=0;
    
    
    for(int i=0;i<WORD_SIZE;i++)
    {
        int tm=0;
        for(int j=0;j<WORD_SIZE;j++)
        {
            if(words[i]==words[j])
            {
                tm++;
            }
            
        }
        if(tm>=mentions) 
        {
            popIndex=i;
            mentions=tm;
        }
    }
    cout << "The most popular word : " << words[popIndex] << "\nFrequency : " << mentions << "\nFound at pos :" << endl;
    
    
    for(int i=0;i<WORD_SIZE;i++)
    {
        if(words[i]==words[popIndex])
        {
            cout << i << endl;
        }
        
    }
    
}