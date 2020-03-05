
/*
 * 
Given a string S, remove all the consecutive duplicates. 
keep one character and remove all subsequent same characters.


Example-1:
Input=  rraabbccdf
Output= rabcdf

Example-2:
Input=  aabbbabb                                                                                                                
Output= abab
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t; cin>>s;
    t="";
    for(int i=1;i<s.size();i++) if(s[i]!=s[i-1]) t+=s[i-1];
    t+=s[s.length()-1];
    cout<<t<<'\n';
}