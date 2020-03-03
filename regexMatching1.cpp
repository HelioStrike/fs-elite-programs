/*
Given an input string (s) and a pattern (p), 
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.


Example 1:
Input:  aa
        a
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
    Input:  aa
            a*
    Output: true
    Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input:  ab
        .*
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input:  aab
        c*a*b
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
    Input:  mississippi
            mis*is*p*.
    Output: false
*/

#include <bits/stdc++.h>
using namespace std;

int sp,pp,sl,nl;
string s,p;

bool match(string cs, string cp, int curadd)
{
    if(cs==cp || (cs.length()==cp.length() && cp.length()==1 && cp[0]=='.')) return 1;
    if(curadd+nl>sl) return 0;
    bool ret=0;
    if(cp.length()>1)
    {
        if(cp[1]=='*')
        {
            string cur="";
            char sv=cp[0];
            for(int i=0;i<=sl-nl-curadd;i++)
            {
                ret|=match(cs,cur+cp.substr(2,cp.length()-2),curadd+i);
                if(ret) break;
                cur+=sv;
            }
        }
    }
    if(ret) return ret;
    if(cs[0]==cp[0] || cp[0]=='.') ret|=match(cs.substr(1,cs.length()-1),cp.substr(1,cp.length()-1),curadd);

    return ret;
}

int main()
{
    cin>>s>>p; sl=s.length(); nl=p.length();
    for(char c: p) if(c=='*') nl-=2;
    cout<<(match(s,p,0)?"true":"false")<<'\n';
    
    return 0;
}