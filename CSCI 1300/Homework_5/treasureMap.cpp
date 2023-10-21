#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
using namespace std;



const int CLUE_ROWS;
const int CLUE_COLS = 2;
const int REG_ROWS = 3;
const int REG_COLS = 2;






double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void calculateDistanceMatrix(double distance[][3], double clue [][2], double region[3][2], const int CLUE_ROWS, const int CLUE_COLS, const int REG_ROWS, const int REG_COLS)
{
    cout << fixed << setprecision(3);
    for(int i=0;i<CLUE_ROWS; i++)
    {
        for(int j=0;j<REG_ROWS; j++)
            distance[i][j] = calculateDistance(clue[i][0], clue[i][1], region[j][0], region[j][1]);
    }
    // for (int i = 0; i < CLUE_ROWS; i++) {
    //     for (int j = 0; j < REG_ROWS; j++) {
    //         cout << distance[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void findClueRegion(double distance[][3], int clue_regions[], const int DISTANCE_ROWS, const int DISTANCE_COLS)
{
    
    for(int i=0;i<DISTANCE_ROWS; i++)
    {
        int min=1;
        for(int j=0;j<DISTANCE_COLS; j++)
        {
            if(distance[i][j]<distance[i][min])
            {
                min=j;
            }
        }
        clue_regions[i]=min+1;
    }
    
}


void findTreasure(int clue_regions[], double region[][2], const int CLUE_REGIONS_SIZE, const int REG_ROWS, const int REG_COLS)
{   
    int r1=0;
    int r2=0;
    int r3=0;
    int midInd=0;
    int minVal=0;
    for(int i=0;i<CLUE_REGIONS_SIZE;i++)
    {
        if(clue_regions[i]==1) r1++;
        if(clue_regions[i]==2) r2++;
        if(clue_regions[i]==3) r3++;
    }
    if(r1<=r2 && r1<=r3) 
    {
        midInd=1;
    
        minVal=r1;
    }
    else if(r2<=r1 && r2<=r3) 
    {
        midInd=2;
    
        minVal=r2;
    }
    else if(r3<=r2 && r3<=r1) 
    {
        midInd=3;
    
        minVal=r3;
    }

    cout << "Region " << midInd << " had the least number of clues : " << minVal << endl;
    cout << "Treasure must be buried in the coordinates ( " << region[midInd-1][0] << ", " << region[midInd-1][1] << " )" << endl;
}