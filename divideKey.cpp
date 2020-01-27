/*
You are given a key represented as a string S which consists only alphanumeric 
character and dashes. The string is separated into N+1 groups by N dashes.

Given a number K, we want you to reformat the strings such that, 
each group contains exactly K characters, except for the first group 
which could be shorter than K, but still must contain at least one character.
Furthermore, there must be a dash inserted between two groups 
and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, 
format the string according to the rules described above.

Example 1:
	Input=  5F3Z-2e-9-w
	        4
	Output= 5F3Z-2E9W
	Explanation: The string S has been split into two parts, each part has 4 characters.	
	Note that the two extra dashes are not needed and can be removed.

Example 2:
	Input=  2-5g-3-J
	        2
	Output= 2-5G-3J
	Explanation: The string S has been split into three parts, each part has 2 characters 
	except the first part as it could be shorter as mentioned above.
*/

#include <bits/stdc++.h>
using namespace std;

int n,x,k,i;
string s,t,ans;
queue<string> toks;

int main()
{
    cin>>s>>k; n=s.length();
    t="";
    while(i<n)
    {
        if(s[i]=='-')
        {
            toks.push(t);
            t=""; i++;
            continue;
        }
        if(s[i]>='a' && s[i]<='z') s[i]+='A'-'a';
        t+=s[i];
        i++;
    }
    toks.push(t);
    ans=t="";
    while(!toks.empty())
    {
        if(t.length()+toks.front().length()>k)
        {
            ans+=t+"-";
            t="";
        }
        else 
        {
            t+=toks.front();
            toks.pop();
        }
    }
    ans+=t;
    cout<<ans<<'\n';
}