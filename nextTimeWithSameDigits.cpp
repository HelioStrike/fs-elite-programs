/*

Given a String, represents the time in the format "HH:MM" which is 24 hours format, 
find the next nearest time by reusing the digits in the given string. 
There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. 
For example, 01:34, 12:09 are all valid. 1:34, 12:9 are all invalid.

Example 1:
	Input= 12:35
	Output= 12:51
    
    Explanation: The next nearest time choosing from digits 1, 2, 3, 5, is 12:51, which occurs 16 minutes later.  
    It is not 12:32, because this occurs 23 hours and 57 minutes later.

Example 2:
	Input= 16:56
	Output= 11:11
    Explanation: The next nearest time choosing from digits 1, 6, 5, 6 is 11:11. 
    It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
    Accepted

*/

#include <bits/stdc++.h>
using namespace std;

int x,c,cm;
string t,tt,ans;
map<char,bool> m;
set<string> s;

void rec(string cur,int pos)
{
    for(auto p: m)
    {
        if(pos==0)
        {
            if(p.first<='2') rec(cur+p.first,1);
        }
        else if(pos==1)
        {
            if(cur[0]<'2' || (cur[0]=='2' && p.first<'4')) rec(cur+p.first,2);
        }
        else if(pos==2)
        {
            if(p.first<='5') rec(cur+p.first,3);
        }
        else if(pos==3)
        {
            s.insert(cur+p.first);
        }
    }
}

int main()
{
    cin>>t; m[t[0]]=m[t[1]]=m[t[3]]=m[t[4]]=1;
    x=1000*(t[0]-'0')+100*(t[1]-'0')+10*(t[3]-'0')+1*(t[4]-'0');
    rec("",0); cm=999999; ans="";
    for(string k: s)
    {
        c=1000*(k[0]-'0')+100*(k[1]-'0')+10*(k[2]-'0')+1*(k[3]-'0');
        if(c<x) c+=2400;
        if(c<cm && c!=x)
        {
            ans=k;
            cm=c;
        }
    }
    cout<<ans[0];
    cout<<ans[1];
    cout<<':';
    cout<<ans[2];
    cout<<ans[3]<<'\n';
    
    return 0;
}