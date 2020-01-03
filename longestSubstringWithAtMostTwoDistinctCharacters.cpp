/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:
    Input:  eceba
    Output: 3
    
    Explanation: t is "ece" which its length is 3.

Example 2:
    Input: ccaabbb
    Output: 5
    
    Explanation: t is "aabbb" which its length is 5.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s; int n=s.length();
    map<char,int> m;
    int p1=0,p2=0,cur=0,ans=0;
    while(p2<n)
    {
        if(m[s[p2]]==0 && cur==2)
        {
            while(true)
            {
                m[s[p1]]--;
                if(m[s[p1]]==0) 
                {
                    p1++;
                    cur--;
                    break;
                }
                p1++;
            }
            continue;
        }
        else if(m[s[p2]]==0) { cur++; }
        m[s[p2]]++;
        ans=max(ans,p2-p1+1);
        p2++;
    }
    cout<<ans<<'\n';    
}