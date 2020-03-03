/*
You have given a task,
to count number of substrings which are pallindromes from a given String.

Example 1:
    Input= abc
    Output= 3
    Explanation= Three substrings are pallindrome: "a", "b", "c".
 

Example 2:
    Input= aaa
    Output= 6
    Explanation= Six substrings are pallindrome: "a", "a", "a", "aa", "aa", "aaa".

NOTE:
The substrings with different start indexes or end indexes are counted as 
different substrings even they consist of same characters.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;
    int n=s.length(),l,ans=0;
    for(int i=0;i<n;i++)
    {
        l=1; ans++;
        while(i-l>=0 && i+l<n && s[i-l]==s[i+l]) ans++,l++;
        if(i+1<n && s[i]==s[i+1])
        {
            l=1; ans++;
            while(i-l>=0 && i+l+1<n && s[i-l]==s[i+l+1]) ans++,l++;
        }
    }
    cout<<ans<<'\n';
}