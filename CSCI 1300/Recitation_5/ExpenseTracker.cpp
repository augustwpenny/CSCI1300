#include <iostream>

using namespace std;

int expenseTracker();

int main()
{
    int ret = expenseTracker();
    cout << "Total Expenses for the Day: $" << ret << endl;

    return 0;
}


int expenseTracker()
{
    int g=0, ent=0, edu=0;
    string input;
    int amnt;

    do
    {
        
        cout << "Enter a category (Groceries, Entertainment, Education or 'exit'):" << endl;
        cin >> input;
        if(input != "Groceries" && input != "Entertainment" && input != "Education" && input != "exit"){
            cout << "Invalid category. Please enter a valid category" << endl;
            continue;
        }
        if(input == "exit")
        {
            break;
        }
        cout << "Enter the expense amount:" << endl;
        cin >> amnt;

        if(input == "Groceries")
        {
            g = g + amnt;
        }
        if(input == "Entertainment")
        {
            ent = ent + amnt;
        }
        if(input == "Education")
        {
            edu = edu + amnt;
        }

    } while(input != "exit");

    cout << "Category-wise Expenses:\nGroceries: $" << g << "\nEntertainment: $" << ent << "\nEducation: $" << edu << endl;

    return g + ent + edu;

}