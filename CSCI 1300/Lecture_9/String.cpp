#include<iostream>
#include<iomanip>


using namespace std;

bool isValid2(int input)
{
    if (!(input==1 || input==2))
    {
        cout << "Please enter a valid input" << endl;
        return false;
    }
    return true;
}

bool isValid3(int input)
{
    if (!(input==1 || input==2 || input == 3))
    {
        cout << "Please enter a valid input" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int genre, author, title;
    cout << "Select the genre: (1) Mystery (2) Science" << endl;
    cin >> genre;
    
    // cout << "Select the Author: (1) Agatha Christie (2) Arthur Conan Doyle (3) Stephen King" << endl;
    // cin >> author; 
    
    // cout << "Select the Book Title: (1) The Memoirs of Sherlock Holmes (2) Tales of Terror and Mystery" << endl;
    // cin >> title;
    
    
    
    bool b1 = isValid2(genre) 
    if (b1 ==false)
    {
        break;
    }
    else 
    {
    if (genre == 1)
    {
       cout << "Select the Author: (1) Agatha Christie (2) Arthur Conan Doyle (3) Stephen King" << endl;
       cin >> author; 
       
       bool b2 = isValid3(author);
        
        if (author == 1)
        {
            cout << "Select the Book Title: (1) Hercule Poirot (2) Miss Marple Detective" << endl;
            cin >> title;
            
            switch(title)
            {
                case 1:
                {
                    cout << "You have ordered Hercule Poirot" << endl;
                    break;
                }
                case 2:
                {
                    cout << "You have ordered Miss Marple Detective" << endl;
                    break;
                }
                
            }
            
             
        }
        
        if (author == 2)
        {
            cout << "Select the Book Title: (1) The Memoirs of Sherlock Holmes (2) Tales of Terror and Mystery" << endl;
            cin >> title;
            
            switch(title)
            {
                case 1:
                {
                    cout << "You have ordered The Memoirs of Sherlock Holmes" << endl;
                    break;
                }
                case 2:
                {
                    cout << "You have ordered Tales of Terror and Mystery" << endl;
                    break;
                }
                
            }
            
             
        }
        
        
        if (author == 3)
        {
            cout << "Select the Book Title: (1) The Institute (2) Misery" << endl;
            cin >> title;
            
            switch(title)
            {
                case 1:
                {
                    cout << "You have ordered The Institute" << endl;
                    break;
                }
                case 2:
                {
                    cout << "You have ordered Misery" << endl;
                    break;
                }
                
            }
            
             
        }
    }
    
    
    
    
    if (genre == 2)
    {
        cout << "Select the Author: (1) Stephen Hawking (2) Carl Sagan (3) Mary Roach" << endl;
       cin >> author; 
       
       bool b3 = isValid3(author);
        
        if (author == 1)
        {
            cout << "Select the Book Title: (1) A Brief History of Time (2) The Universe in a Nutshell" << endl;
            cin >> title;
            
            switch(title)
            {
                case 1:
                {
                    cout << "You have ordered A Brief History of Time" << endl;
                    break;
                }
                case 2:
                {
                    cout << "You have ordered The Universe in a Nutshell" << endl;
                    break;
                }
                
            }
            
             
        }
        
        if (author == 2)
        {
            cout << "Select the Book Title: (1) Cosmos (2) Pale Blue Dot" << endl;
            cin >> title;
            
            switch(title)
            {
                case 1:
                {
                    cout << "You have ordered Cosmos" << endl;
                    break;
                }
                case 2:
                {
                    cout << "You have ordered Pale Blue Dot" << endl;
                    break;
                }
                
            }
            
             
        }
        
        
        if (author == 3)
        {
            cout << "Select the Book Title: (1) Stiff: The Curious Lives of Human Cadavers (2) Gulp: Adventures on the Alimentary Canal" << endl;
            cin >> title;
            
            switch(title)
            {
                case 1:
                {
                    cout << "You have ordered Stiff: The Curious Lives of Human Cadavers" << endl;
                    break;
                }
                case 2:
                {
                    cout << "You have ordered Gulp: Adventures on the Alimentary Canal" << endl;
                    break;
                }
                
            }
            
             
        }
    }
    
    
    
    
    }
}