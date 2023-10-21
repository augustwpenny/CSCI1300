#include<array>
#include<iostream>

using namespace std;


void matrixSum(int a[2][3], int b[2][3]);

int main()
{
    int array1[2][3];
    int array2[2][3];

    cout << "Enter values for matrix 1, one row at a time:" << endl;
    cin >> array1[0][0] >> array1[0][1] >> array1[0][2];
    cin >> array1[1][0] >> array1[1][1] >> array1[1][2];

    cout << "Enter values for matrix 1, one row at a time:" << endl;
    cin >> array2[0][0] >> array2[0][1] >> array2[0][2];
    cin >> array2[1][0] >> array2[1][1] >> array2[1][2];

    matrixSum(array1, array2);
}




void matrixSum(int a[2][3], int b[2][3])
{
    int ret[2][3];
    for(int y=0;y<2;y++)
    {
        for(int x=0;x<3;x++)
        {
            ret[y][x]=a[y][x]+b[y][x];
        }
    }
    cout << "The sum is:" << endl;
    for(int y=0;y<2;y++)
    {
        for(int x=0;x<3;x++)
        {
            cout << ret[y][x] << " ";
        }
        cout << endl; 
    }
}