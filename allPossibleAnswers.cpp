/*
Given a string of numbers and operators, 
return all possible results from computing all the different 
possible ways to group numbers and operators. 
The valid operators are +, - and *.

Example 1:
	Input: 2-1-1
	Output: [0, 2]
	Explanation: 
	((2-1)-1) = 0 
	(2-(1-1)) = 2

Example 2:
	Input: 2*3-4*5
	Output: [-34, -14, -10, -10, 10]
	Explanation: 
	(2*(3-(4*5))) = -34 
	((2*3)-(4*5)) = -14 
	((2*(3-4))*5) = -10 
	(2*((3-4)*5)) = -10 
	(((2*3)-4)*5) = 10
*/

#include <bits/stdc++.h>
using namespace std;

string s;
map<string,vector<int> > vis;

bool isop(char c)
{
    return (c=='*' || c=='-' || c=='+');
}

void rec(string s)
{
    if(vis[s].size()>0) return;
    int cur=0,curn=0;
    while(cur<s.length() && !isop(s[cur])) curn*=10,curn+=s[cur]-'0',cur++;
    if(cur==s.length()) 
    {
        vis[s].push_back(curn);
        return;
    }
    
    cur=0;
    while(cur<s.length())
    {
        curn=0;
        while(cur<s.length() && !isop(s[cur]))
        {
            curn*=10;
            curn+=s[cur]-'0';
            cur++;
        }

        if(cur==s.length()) break;

        rec(s.substr(0,cur));
        rec(s.substr(cur+1,s.length()-cur-1));
        for(int x: vis[s.substr(0,cur)])
        {
            for(int y: vis[s.substr(cur+1,s.length()-cur-1)])
            {
                if(s[cur]=='*') vis[s].push_back(x*y);
                else if(s[cur]=='+') vis[s].push_back(x+y);
                else if(s[cur]=='-') vis[s].push_back(x-y);
            }
        }
        cur++;
    }
}

int main()
{
    cin>>s;
    rec(s);
    sort(vis[s].begin(),vis[s].end());
    for(int x: vis[s]) cout<<x<<' ';
    cout<<'\n';
   
    return 0;
}