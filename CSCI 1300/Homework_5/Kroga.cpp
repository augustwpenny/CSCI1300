#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

string addItem();
vector<string> removeItem(vector<string> cart, string s);
void checkout(vector<string> cart, double total);

int main()
{
    cout << fixed << setprecision(3);
    cout << "Welcome to Kroga Gas Station!" << endl;
    double budget;
    double total=0;
    cout << "Enter your budget:"<< endl;
    cin >> budget;
    if(budget<=0)
    {
        cout << "Invalid input. Balance must be a non-negative value." << endl;
        return 0;
    }
    int choice=0;
    vector<string> cart;
    do {
        cout << "Please input 1-4 followed by enter to navigate the menu:" << endl;
        cout << "1) Add Product" << endl;
        cout << "2) Remove Product" << endl;
        cout << "3) Checkout" << endl;
        cout << "4) Exit" << endl;
        
        
        if (cin >> choice) {
            
            if (choice >= 1 && choice <= 4) {
                switch (choice) {
                    case 1:{
                        if(budget<2.99)
                        {
                            cout << "Your budget is insufficient to add more products." << endl;
                            break;
                        }
                        
                    
                        string select = addItem();
                        if(select=="Cheetos")
                        { 
                            budget -=2.99*1.09;
                            total+=(2.99*1.09);
                            cart.push_back(select);
                        cout << select << " added to cart." << endl;
                        }
                        if(select=="Oreos")
                        {
                            budget -=3.39*1.09;
                            total+=(3.39*1.09);
                            cart.push_back(select);
                        cout << select << " added to cart." << endl;
                        }
                        if(select=="Coffee") 
                        {
                            budget -=3.79*1.09;
                            total+=(3.79*1.09);
                            cart.push_back(select);
                        cout << select << " added to cart." << endl;
                        }
                        if(select=="Slurpee")
                        {
                            budget -=4.29*1.09;
                            total+=(4.29*1.09);
                            cart.push_back(select);
                        cout << select << " added to cart." << endl;
                        }
                        
                        break;
                    }
                    case 2:{
                        string s;
                        cout << "Enter the product name to be removed from the cart:" << endl;
                        cin >> s;
                        if(cart.size()==0) 
                        {
                            cout << "Cart is empty." << endl;
                            break;
                        }
                        cart=removeItem(cart, s);
                        if(s=="Cheetos") 
                        {
                            budget+=2.99*1.09;
                            total-=2.99*1.09;
                        }
                        if(s=="Oreos") 
                        {
                            budget+=3.39*1.09;
                            total-=3.39*1.09;
                        }
                        if(s=="Coffee") 
                        {
                            budget+=3.79*1.09;
                            total-=3.79*1.09;
                        }
                        if(s=="Slurpee") 
                        {
                            budget+=4.29*1.09;
                            total-=4.29*1.09;
                        }
                        break;
                    }
                    
                    case 3:{
                        if(cart.size()==0)
                        {
                            cout << "Cart is empty." << endl;
                            break;
                        }
                        checkout(cart, total);
                        cout << "Thank you! Please visit again." <<endl;
                        return 0;
                        break;
                    }
                }
            } else {
                cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 4);
    cout << "Thank you! Please visit again." <<endl;
    
    return 0;
}


string addItem()
{
    cout << fixed << setprecision(3);
    char choice;

    cout << "Add Product:" << endl;
    cout << "A) Cheetos" << endl;
    cout << "B) Oreos" << endl;
    cout << "C) Coffee" << endl;
    cout << "D) Slurpee" << endl;
    cin >> choice;

    // Validate user input
    

    // Blank switch statement with options
    switch (choice) {
        case 'A':
            return "Cheetos";
            break;
        case 'B':
            return "Oreos";
            break;
        case 'C':
            return "Coffee";
            break;
        case 'D':
            return "Slurpee";
            break;
        default:
            cout << "Invalid input." << endl;
    }

    return "";
}
vector<string> removeItem(vector<string> cart, string s)
{
    
    cout << fixed << setprecision(3);
    vector<string> cart1 = cart;
    for(int i=0;i<cart.size();i++)
    {
        
        if(cart1.at(i)==s)
        {
            
            for(int j=i;j<cart1.size()-1; j++)
            {
                cart.at(j)=cart1.at(j+1);
            }
            cart1.pop_back();
            cout << s << " removed from cart." << endl;
            return cart1;
        }
    }
    cout << "Product Name not found." << endl;
    return cart1;
}
void checkout(vector<string> cart, double total)
{
    cout << fixed << setprecision(3);
cout << "Your cart has the following products:" << endl;
for(int i=0;i<cart.size();i++)
{
    cout << cart.at(i) << endl;
}
cout << "Total amount: $" << total << endl;
}


// if(s=="Cheetos") money=2.99*1.09;
// if(s=="Oreos") money=3.39*1.09;
// if(s=="Coffee") money=3.79*1.09;
// if(s=="Slurpee") money==4.29*1.09;