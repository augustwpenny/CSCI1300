#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

char shiftChar(char c, int i);
int getMethod2ShiftAmount(string key);
int getMethod3ShiftAmount(string key1, string key2);
char encryptChar(char c, int choice, string key1, string key2);
char decryptChar(char c, int choice, string key1, string key2);
string encryptMessage(string msg, int choice, string key1, string key2);

int main(){

    // shiftChar method:
    
    // char a;
    // int p;
    // cout << " enter char:" << endl;
    // cin >> a;
    // cout << " enter num:" << endl;
    // cin >> p;
    // cout << shiftChar(a,p);

    // getMethod2ShiftAmount

    // string s;
    // cout << "Enter String" << endl;
    // cin >> s;
    // cout << getMethod2ShiftAmount(s) << endl;

    // getMethod3ShiftAmount

    // string s1;
    // string s2;
    // cout << "input string 1:" << endl;
    // cin >> s1;
    // cout << "input string 2:" << endl;
    // cin >> s2;
    // cout << getMethod3ShiftAmount(s1,s2);


    // char c;
    // string k1;
    // string k2;
    // int m;
    // cout << "Enter character:" << endl;
    // cin >> c;
    // cout << "Enter key 1:" << endl;
    // cin >> k1;
    // cout << "Enter key 2:" << endl;
    // cin >> k2;
    // cout << "Enter method:" << endl;
    // cin >> m;
    // cout << encryptChar(c, m, k1, k2) << endl;

    // char c;
    // string k1;
    // string k2;
    // int m;
    // cout << "Enter character:" << endl;
    // cin >> c;
    // cout << "Enter key 1:" << endl;
    // cin >> k1;
    // cout << "Enter key 2:" << endl;
    // cin >> k2;
    // cout << "Enter method:" << endl;
    // cin >> m;

    // cout << decryptChar(c, m, k1, k2) << endl;



    // string s = "";
    // string k1 = "";
    // string k2 = "";
    // int i=0;


    // cout << "enter message";
    // cin >> s;
    // cout << endl;

    // cout << "enter key1";
    // cin >> k1;
    // cout << endl;

    // cout << "enter key2";
    // cin >>k2;
    // cout << endl;

    // cout << "method" << endl;
    // cin >>i;

    // cout << encryptMessage(s, i, k1, k2) << endl;
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