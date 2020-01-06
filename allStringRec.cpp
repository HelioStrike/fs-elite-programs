/*
Given a string 'S' represents a format.

In the given format, Each letter in the word has 1 or more options.  
If there is one option, the letter is represented as it is.  
If there is more than one option, then curly braces delimit the options.  

-> For example, {a,b,c} represents options a, b, c.
-> For example, {a,b}c{d,e} represents the list acd, ace, bcd, bce

Return all words that can be formed in this manner, in lexicographical order.

Example 1:
		input=	{b}c{e,g}k
		output=	bcek bcgk

Example 2:
		input=	{b,a}{d,c}
		output=	ac ad bc bd

Example 3:
		input=	{xyz}a{c,b}
		output= xyzab xyzac
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set<string> ss;

void rec(string cur,int pos) {
    if(pos==n)
    {
        ss.insert(cur);
        return;
    }

    while(pos<n && s[pos]!='{')
    {
        cur+=s[pos];
        pos++;
    }
    if(pos==n) rec(cur,pos);
    if(s[pos]=='{')
    {
        pos++;
    
        vector<string> ops;
    
        string rn="";
        while(s[pos]!='}')
        {
            if(s[pos]==',')
            {
                ops.push_back(rn);
                rn="";
                pos++;
                continue;
            }
            rn+=s[pos];
            pos++;       
        }        
    
        if(s[pos]=='}')
        {
            ops.push_back(rn);
            rn="";
            pos++;
        }
    
        for(string op: ops) {
            rec(cur+op,pos);
        }

    }
}

int main()
{
    cin>>s; n=s.length();
    rec("",0);
    for(string k: ss) cout<<k<<' ';
    cout<<'\n';
}