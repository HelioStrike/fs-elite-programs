/*
There is a new language which uses the latin alphabet. 
However, the order among letters are unknown to you. 
You receive a list of non-empty words from the dictionary, 
where words are sorted lexicographically by the rules of this new language. 
Derive the order of letters in this language.

Example 1:
	Input=  wrt wrf er ett rftt
	Output= wertf

Example 2:
	Input=	z x
	Output= zx

Example 3:
	Input=  z x z
	Output= -1 

Explanation: The order is invalid, so return -1.

Note:
You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

#include <bits/stdc++.h>
using namespace std;

int n,cnt;
map<char,vector<char> > g;
map<char,int> deg;
vector<string> words;
string s;
vector<char> ord;
map<char,int> vis;
bool boo;

bool dfs(char c)
{
    vis[c]=1;
    for(char nxt: g[c])
    {
        if(vis[nxt]==2) continue;
        if(vis[nxt]==1 || dfs(nxt)) return 1;
    }
    ord.push_back(c);
    vis[c]=2;
    return 0;
}

int main()
{
    while(cin>>s) 
    {
        words.push_back(s);
        for(char c: s) deg[c]=0; 
    }
    n=words.size();
    for(int i=0;i<n-1;i++)
    {
        int x=0,y=0;
        while(x<words[i].length() && y<words[i+1].length())
        {
            if(words[i][x]!=words[i+1][y])
            {
                g[words[i][x]].push_back(words[i+1][y]);
                deg[words[i+1][y]]++;
                break;
            }
            x++,y++;
        }
    }

    for(auto p: deg)
    {
        if(!deg[p.first])
        {
            boo=dfs(p.first);
            if(boo) break;
            cnt++;
        }
    }
    
    if(boo || cnt==0) { cout<<"-1"; }
    else
    {
        reverse(ord.begin(), ord.end());
        for(char c: ord) { cout<<c; }
    }
    cout<<'\n';

    return 0;
}