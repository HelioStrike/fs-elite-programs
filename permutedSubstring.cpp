/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.


Example 1:
    Input: ab
    eidbaooo
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
    Input:ab
    eidboaoo
    Output: false
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10000].
*/

#include <bits/stdc++.h>
using namespace std;

int i,sl,tl,cc,ccc;
string s,t;
map<int,int> sc;
map<int,bool> cm;

int main()
{
    cin>>s>>t; sl=s.length(),tl=t.length();
    if(sl>tl)
    {
        cout<<"false"<<'\n';
        return 0;
    }
    for(char c: s) sc[c]++,cm[c]=1;
    for(auto p: sc) cc++;
    while(i<tl)
    {
        sc[t[i]]--;
        if(cm[t[i]] && sc[t[i]]==0) ccc++;
        if(i>=sl)
        {
            if(i>sl)
            {
                sc[t[i-sl]]++;
                if(cm[t[i-sl]] && sc[t[i-sl]]==1) ccc--;
            }
            if(ccc==cc)
            {
                cout<<"true"<<'\n';
                return 0;
            }
        }
        i++;
    }
    cout<<"false"<<'\n';
    return 0;
}