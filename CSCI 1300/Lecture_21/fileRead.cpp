#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;



int main()
{
    // 1. Create filestream object
    ifstream file_in;

    // 2. Associate a file with the filestream
    string filename = "data.txt";
    file_in.open(filename);

    // 3. read from the file and store to a variable.
    int x;
    file_in >> x;
    cout << x;
    // By default, it prints the first line then moves to next and waits to be called again
    // To process a header (such as a string variable), store the first line as a string then the rest as an int.

    // 4. do what you want with the file. usually loops to read it and such

    // 5. close the file
    file_in.close();
    

    // To write to file, use:
    ofstream=file.out;
    file_out.open(filename2)
    // This will add onto the end of a file instead of overwrite it
    file_out.open(filename2, ios::app)
    file_out.

    // This will write into the file.
    file_out << "This will be printed in the new file" << endl;






}
