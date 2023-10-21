#include<iostream>
#include<array>
#include<cmath>

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// Question 2
using namespace std;

double temperatureMean(double new_temperature[], const int TEMP_SIZE);
double temperatureRange(double new_temperature[], const int TEMP_SIZE);
void temperatureDelta(double new_temperature[], double old_temperature[], double data[], const int TEMP_SIZE);

// int main()
// {
// const int TEMP_SIZE = 6;
// double old_temperature[TEMP_SIZE] = {-0.2, 14, 19, -5, 12.98, -13.57};
// double new_temperature[TEMP_SIZE] = {-1, -4, -2, -9, -12.34, -19.45};
// cout << temperatureRange(new_temperature, TEMP_SIZE);


// }

double temperatureMean(double new_temperature[], const int TEMP_SIZE)
{
    double ret=0;;
    for(int i=0;i<TEMP_SIZE;i++)
    {
        ret+=new_temperature[i];
    }
    return ret/TEMP_SIZE;
}

double temperatureRange(double new_temperature[], const int TEMP_SIZE)
{
    double m=new_temperature[1];
    double n=new_temperature[1];
    double d=0;

    for(int i=0;i<TEMP_SIZE;i++)
    {
        if(new_temperature[i]>m){
            m=new_temperature[i];
        }
        if(new_temperature[i]<n) {
            n=new_temperature[i];
        }
    }

 

    if(TEMP_SIZE==1)
    {
        d=0.000;
    }
    else if(n<0 && m>=0)
    {
        d=m+abs(n);
    } else if ((n<=0 && m<=0) || (n>=0 && m>=0))
    {
        d=abs(m)-abs(n);
    }
    return abs(d);
}

void temperatureDelta(double new_temperature[], double old_temperature[], double data[], const int TEMP_SIZE)
{
    for(int i=0;i<TEMP_SIZE;i++)
    {
        data[i]=old_temperature[i]-new_temperature[i];
    }
}

