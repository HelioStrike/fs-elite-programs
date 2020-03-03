/*
Given a non-empty string, check if the given string can be constructed
by taking a substring of it and appending multiple copies of the substring together. 

You may assume the given string consists of lowercase English letters only and 
its length will not exceed 10000.

Example 1:
    Input=  abab
    Output= true
    Explanation: It's the substring "ab" twice.

Example 2:
    Input=  aba
    Output= false

Example 3:
    Input=  abcabcabcabc
    Output= true
    Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;
    int n=s.length();
    string cur="";
    bool yee=false;
    for(int i=0;i<n/2;i++)
    {
        cur+=s[i];
        if(n%(i+1)) continue;
        int ok=0;
        for(int j=0;j<n/(i+1);j++)
        {
            int ok2=0;
            for(int k=0; k<=i; k++) ok2+=(cur[k]==s[k+j*(i+1)]);
            ok+=ok2==(i+1);
        }
        if(ok==n/(i+1)) { yee=true; break; } 
    }
    cout<<(yee?"true":"false")<<'\n';
}