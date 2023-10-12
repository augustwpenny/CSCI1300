#include<cassert>
#include<iostream>

using namespace std;

void swap(char letters[], int e1, int e2);
void reverseArray(char letters[], int l);

int main()
{
    char letters[10];
   cout << "Please enter 10 characters for the array:" << endl;
   for(int i=0;i<10;i++)
   {
    char t;
    cin >> t;
    letters[i]=t;
   }

reverseArray(letters, 10);
cout <<"here";

   cout << "The reversed array is:   " ;
   
   for(int i=0;i<10;i++)
   {
    cout << letters[i] << " " ;
   }

}


void swap(char letters[], int e1, int e2)
{
    char t = letters[e1];
    letters[e1]=letters[e2];
    letters[e2]=t;
    cout << letters;
}

void reverseArray(char letters[], int l)
{
    int i=0;
    while(i<=(l/2))
    {
        swap(letters, i, l-1-i);
        i++;
    }
    
}
