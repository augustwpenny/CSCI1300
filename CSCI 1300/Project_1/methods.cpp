#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<limits>
#include<climits>

using namespace std;

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav




char shiftChar(char c, int i);
int getMethod2ShiftAmount(string key);
int getMethod3ShiftAmount(string key1, string key2);
char encryptChar(char c, int choice, string key1, string key2);
char decryptChar(char c, int choice, string key1, string key2);
string encryptMessage(string msg, int choice, string key1, string key2);
string decryptMessage(string msg, int choice, string key1, string key2);
void callMenu();

int main(){


int encryptMethod=0;
string k1="";
string k2="";
int menuChoice=0;

cout << "Please input 1-6 followed by enter to navigate the menu:\n1. Set Encryption Key 1\n2. Set Encryption Key 2\n3. Select Encryption Method\n4. Encrypt Message\n5. Decrypt Message\n6. Exit Program" << endl; 
while(menuChoice!=6)
{
    
    cin >> menuChoice;
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    

    if(menuChoice<1 || menuChoice>6)
    {
        cout << "Invalid input" << endl;
        continue;
    }else if(menuChoice == 1)
    {
       do
        {
            cout << "Enter key: " << endl;
            getline(cin, k1);
            
            if(k1.length()<1)
            {
                cout << "Invalid key" << endl;
                continue;
            }
            
        }while(k1.length()<1);
        cout << "Successfully set encryption key1 to " << k1 << endl;
        callMenu();
        continue;
    }else if(menuChoice == 2)
    {
         
        do
        {
            cout << "Enter key: " << endl;
            getline(cin, k2);
            
            if(k2.length()<1)
            {
                cout << "Invalid key" << endl;
                continue;
            }
            
        }while(k2.length()<1);
        cout << "Successfully set encryption key2 to " << k2 <<endl;
        callMenu();
        continue;
    }else if(menuChoice == 3)
    {
        int temp=0;   
        cout << "Please input 1-4 to decide encryption technique.\n1. Method1 only (shift by 1)\n2. Method2 only (shift by first key)\n3. Method3 only (shift by both keys)\n4. Mix of Method1, Method2, Method3" << endl;
        do
        {
            cin >> temp;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            
            if(temp<=4 && temp>=1)
            {
                break;
            } else {
                cout << "Invalid encryption choice" << endl;
                continue;
            }
        }while(temp<1 || temp>4);
        encryptMethod=temp;
        cout << "Successfully set encryption type to " << encryptMethod << endl;
        callMenu();
        continue;
    }else if(menuChoice==4)
    {
        string enc;
        if(k1.length()<1 || k2.length()<1 || encryptMethod < 1 || encryptMethod > 4)
        {
            cout << "You cannot do this until you set both keys and choose an encryption method" << endl;
        } else 
        {
            cout << "Enter your message to encrypt:" << endl;
            getline(cin, enc);
            
        }
        if(encryptMethod==1){
            cout << encryptMessage(enc, 1, k1, k2)<< endl;;
        }
        if(encryptMethod==2){
            cout << encryptMessage(enc, 2, k1, k2)<< endl;;
        }
        if(encryptMethod==3){
            cout << encryptMessage(enc, 3, k1, k2)<< endl;;
        }
        if(encryptMethod==4){
            cout << encryptMessage(enc, 4, k1, k2)<< endl;;
        }
        callMenu();
    }else if(menuChoice==5)
    {
        string dec;
        if(k1.length()<1 || k2.length()<1 || encryptMethod < 1 || encryptMethod > 4)
        {
            cout << "You cannot do this until you set both keys and choose an encryption method" << endl;
        } else 
        {
            cout << "Enter your message to decrypt:" << endl;
            getline(cin, dec);
            
        }
        if(encryptMethod==1){
            cout << decryptMessage(dec, 1, k1, k2)<< endl;;
        }
        if(encryptMethod==2){
            cout << decryptMessage(dec, 2, k1, k2)<< endl;;
        }
        if(encryptMethod==3){
            cout << decryptMessage(dec, 3, k1, k2)<< endl;;
        }
        if(encryptMethod==4){
            cout << decryptMessage(dec, 4, k1, k2)<< endl;;
        }
        if(menuChoice==6) 
        {
        
        }
        callMenu();
    } 
    if(menuChoice==6)
        {
            break;
        }
   
} while (menuChoice!=6);
cout << "Goodbye." << endl;



}


void callMenu()
{
    cout << "Please input 1-6 followed by enter to navigate the menu:\n1. Set Encryption Key 1\n2. Set Encryption Key 2\n3. Select Encryption Method\n4. Encrypt Message\n5. Decrypt Message\n6. Exit Program" << endl; 
}

string decryptMessage(string msg, int choice, string key1, string key2)
{
    if(choice<1 || choice>4)
    {
        cout << "Invalid decryption method" << endl;
    }

    if(choice==1)
    {
        int l = msg.length();
        string ret="";
        
        for(int i=0;i<l;i++)
        {
            ret+=shiftChar(msg[i], -1);
        }
        return ret;
    }
    if(choice==2)
    {
        int l = msg.length();
        string ret="";
        
        for(int i=0;i<l;i++)
        {
            ret+=shiftChar(msg[i], -1*getMethod2ShiftAmount(key1));
        }
        return ret;
    }
    if(choice==3)
    {
        int l = msg.length();
        string ret="";
        
        for(int i=0;i<l;i++)
        {
            ret+=shiftChar(msg[i], -1*getMethod3ShiftAmount(key1, key2));
        }
        return ret;
    }
    if(choice==4)
    {
        int l=msg.length();
        string ret="";

        for(int i=0;i<l;i++)
        {
            if(i%3==0)
            {
                ret+=shiftChar(msg[i], -1);
            }
            if(i%3==1)
            {
                ret+=shiftChar(msg[i], -1*getMethod2ShiftAmount(key1));
                
            }
            if(i%3==2)
            {
                ret+=shiftChar(msg[i], -1*getMethod3ShiftAmount(key1, key2));
            }

        }
        return ret;
    }
    return msg;
}

string encryptMessage(string msg, int choice, string key1, string key2)
{
    if(choice<1 || choice>4)
    {
        cout << "Invalid encryption method" << endl;
    }

    if(choice==1)
    {
        int l = msg.length();
        string ret="";
        
        for(int i=0;i<l;i++)
        {
            ret+=shiftChar(msg[i], 1);
        }
        return ret;
    }
    if(choice==2)
    {
        int l = msg.length();
        string ret="";
        
        for(int i=0;i<l;i++)
        {
            ret+=shiftChar(msg[i], getMethod2ShiftAmount(key1));
        }
        return ret;
    }
    if(choice==3)
    {
        int l = msg.length();
        string ret="";
        
        for(int i=0;i<l;i++)
        {
            ret+=shiftChar(msg[i], getMethod3ShiftAmount(key1, key2));
        }
        return ret;
    }
    if(choice==4)
    {
        int l=msg.length();
        string ret="";

        for(int i=0;i<l;i++)
        {
            if(i%3==0)
            {
                ret+=shiftChar(msg[i], 1);
            }
            if(i%3==1)
            {
                ret+=shiftChar(msg[i], getMethod2ShiftAmount(key1));
                
            }
            if(i%3==2)
            {
                ret+=shiftChar(msg[i], getMethod3ShiftAmount(key1, key2));
            }

        }
        return ret;
    }
    return msg;
}

char decryptChar(char c, int choice, string key1, string key2)
{
     if(choice<1 || choice>3)
    {
        cout << "Invalid decryption method" << endl;
        return c;
    }

    if(choice==1)
    {
        return shiftChar(c, -1);
    }
    if(choice==2)
    {
        return shiftChar(c, -1*getMethod2ShiftAmount(key1));
    }
    if(choice==3)
    {
        return shiftChar(c, -1*getMethod3ShiftAmount(key1, key2));
    }
    return c;
}

char encryptChar(char c, int choice, string key1, string key2)
{
    if(choice<1 || choice>3)
    {
        cout << "Invalid encryption method" << endl;
        return c;
    }

    if(choice==1)
    {
        return shiftChar(c, 1);
    }
    if(choice==2)
    {
        return shiftChar(c, getMethod2ShiftAmount(key1));
    }
    if(choice==3)
    {
        return shiftChar(c, getMethod3ShiftAmount(key1, key2));
    }
    return c;
}

int getMethod3ShiftAmount(string key1, string key2)
{
    int l1=key1.length();
    int l2=key2.length();
    int count=0;

    for(int i=0;i<l1;i++)
    {
        char m = key1[i];
        for(int k=0;k<l2;k++)
        {
            if(key2[k]==m)
            {
                count++;
            }
        }
    }
    return count%26;
}

int getMethod2ShiftAmount(string key)
{
    int l=key.length();
    int v=0;

    for(int i=0;i<l;i++)
    {
        if(key[i]=='a' || key[i]=='e' || key[i]=='i' || key[i]=='o' || key[i]=='u' || key[i]=='y')
        {
            v++;
        }
    }
    
    return (v+l)%26;
}

char shiftChar(char c, int i)
{
    int f = int(c);

    
    if(f>=97 && f<=122)
    {
        bool b = true;

        if(f+i<123 && f+i>96){
            return char(f+i);
        } 
        if(i>0)
        {
            if(f+i>122)
            {
                while(b==true)
            {
            if(f+i<122){
                return char(f+i);
            }
            i=i-26;

            }
            }
        }
       
        if(i<0){
            i=abs(i);
            if(f-i<97){
            while(b==true)
            {
            if(f-i>96){
                return char(f-i);
            }
            i=i-26;

            }
        }
        }
        
    }
    return char(f);
}