/*
Given two strings s and t, determine if they are both one edit distance apart.

Note:

There are 3 possiblities to satisify one edit distance apart:
    1. Insert a character into s to get t
    2. Delete a character from s to get t
    3. Replace a character of s to get t

Example 1:
    Input:  ab 
            acb
    Output: true
    
    Explanation: We can insert 'c' into s to get t.

Example 2:
    Input:  cab
            ad
    Output: false
    
    Explanation: We cannot get t from s by only one step.

Example 3:
    Input:  1203
            1213
    Output: true
    Explanation: We can replace '0' with '1' to get t.
    
NOTE: Read 2 lines input.
*/

//Keep 2 points. If 2 chars at pointer locations are same, increment them both
//else increment as seen fit and register a change.
//If both pointers reach their end and there's only 1 change, kaboom!
//Time Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t; int n,m;
    getline(cin,s); n=s.length();
    getline(cin,t); m=t.length();
    
    int ch=0,ps=0,pt=0;
    while(ps<n && pt<m && ch<2)
    {
        if(s[ps]==t[pt]) ps++,pt++;
        else
        {
            if(n<m) pt++;
            else if(n>m) ps++;
            else ps++,pt++;
            ch++;
        }
    }
    if(ps==n && pt==m-1) pt++,ch++;
    if(ps==n-1 && pt==m) ps++,ch++;

    cout<<((ch==1 && ps==n && pt==m)? "true":"false")<<'\n';
}