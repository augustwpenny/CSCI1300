#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int keywordThreshold(string wordFile, string frequency[][2]);
bool countFilter(string emailName, string keywordThreshold[][2], int keywordCount[], int keywordSize);
bool checkSpam(int keywordCount[], string keywordThreshold[][2], int keywordSize);

int main()
{
    string freq[10][2];
    int kwC[10];
    int count = keywordThreshold("key1.txt", freq);
    if(countFilter("e1.txt", freq, kwC, count)==false)
    {
        cout << "Fail" << endl;
        return 0;
    }
    if(checkSpam(kwC, freq, count)==false)
    {
        cout << "good" << endl;
        return 0;
    }
    else cout << "spam" << endl;
    return 0;
    

}

int keywordThreshold(string wordFile, string frequency[][2])
{
    ifstream filein;
    stringstream ss;
    filein.open(wordFile);

    if(filein.fail())
    {
        cout << "Failed to open keyword file" << endl;
        return 0;
    }
    
    string word;
    int i=0;
    while(!filein.eof())
    {
    getline(filein, word);
    stringstream ss(word);
    ss >> frequency[i][0] >> frequency[i][1];
    i++;
    }
    return i++;

}

bool countFilter(string emailName, string keywordThreshold[][2], int keywordCount[], int keywordSize)
{
    ifstream filein;
    filein.open(emailName);
    string word;
    if(filein.fail())
    {
        return false;
        cout << "Failed to open email file" << endl;
    }
    
    while(!filein.eof())
    {
        getline(filein, word); // takes in a whole line of the file
        stringstream ss(word); // makes that line into a stringstream
        string wordToCompare;
        while(!ss.fail())
        { // Can use ss.clear()
            ss >> wordToCompare;
            for(int i=0;i<keywordSize;i++)
            {
                
                if(wordToCompare==keywordThreshold[i][0])
                {
                    keywordCount[i]++;
                }
            }
        }
    } 

    
    return true;
}

bool checkSpam(int keywordCount[], string keywordThreshold[][2], int keywordSize)
{
    string t;
    for(int i=0;i<keywordSize;i++)
    {
        t=keywordThreshold[i][1];
        if(stoi(t)>keywordCount[i])
        {
            
            return false;
        }
    }
    return true;
}









