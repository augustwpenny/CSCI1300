#include<iostream>

using namespace std;



// Use upper camel case to differentiate from a function
// Ex: Groceries
// For each item: Price -> double, Name -> string, Weight -> double.
struct Product 
{ 
    string name;
    string category;
    double price;

};
// name, price, and category are attributes/data members of the Product struct

Product inflationUpdate(Product p)
{
    p.price*=1.3
    return p; // Need to return p to make the changes update in main. 
}

int main()
{
    // Define the variable like any other type like "int x;" or "double price;"
    Product apple;
    apple.price = 2.25;
    apple.category = "Fruit";
    apple.name = "Apple";
    

    // Apple exists in main
    Product fruits[3] = {apple};

    // Pear only exists inside the fruits array because it is declared and intialized in the fruits. 
    fruits[1] = {"Pear", "Fruit", 2.50};

    return 0;
}