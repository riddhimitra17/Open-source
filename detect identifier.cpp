#include<bits/stdc++.h>
#include <stdio.h>
#include<iostream>
using namespace std;

bool isIdentifier(string s)
{
    
    if(
  	!((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z') || s[0]=='_')
  	) return false;
    
        for( int i = 1; i <s.length(); i++ )
            if(!
            ((s[i]>='a' && s[i] <='z') || 
            (s[i]>='A' && s[i]<='Z') ||
            (s[i]>='0' && s[i]<='9') ||
            s[i]=='_')
            ) return false;
            
        return true;
    
}
int main()
{
    string c;
    cout<<"Enter the string: "<<endl;
    cin>>c;
    if(isIdentifier(c))
    {
        cout<<c<<" is valid identifier";
    }
    else
    {
        cout<<c<<" is not valid identifier";
    }
    
}
//test cases
//_
//_name
//NaM_e
//name$
//$name_
//name12
//12name

