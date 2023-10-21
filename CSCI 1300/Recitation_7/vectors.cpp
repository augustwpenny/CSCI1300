#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<double> addVals();
double calculateAverage(vector<double> inpV);
vector<double> removeBelowAverage(vector<double> inpV);

int main()
{
    vector<double> v = addVals();
    vector<double> toPrint = removeBelowAverage(v);
    

    for(int i=0;i<toPrint.size();i++)
    {
        cout << toPrint[i] << " ";
    }
}

vector<double> addVals()
{
    vector<double> inpV;
    cout << "Enter 15 values for the vector, one by one:" << endl;
    for(int i=0;i<15;i++)
    {
        double inp;
        cin >> inp;
        inpV.push_back(inp);
    }
    cout << "Values added. " << endl;
    return inpV;
}

double calculateAverage(vector<double> inpV)
{
    double sum=0;
    for(int i=0;i<15;i++)
    {
        sum += inpV[i];
    }
    return sum/15.0;
}

vector<double> removeBelowAverage(vector<double> vectorInput)
{
    
    vector<double> inpV=vectorInput;
    double avg = calculateAverage(inpV);
    for(int i=0;i<inpV.size();i++)
    {
        if(inpV[i]<avg)
        {
            int k=inpV.size();
            for(int j=i;j<k;j++)
            {
                double temp=inpV[j+1];
                inpV[j]=temp;
            }
            inpV.pop_back();
        }
    }
    cout << inpV.size();
    return inpV;
}