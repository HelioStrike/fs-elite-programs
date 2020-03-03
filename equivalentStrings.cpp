/*
Given a list of pairs of equivalent words synonyms and a sentence text, output all possible synonymous sentences 
sorted lexicographically.
 

Example 1:

Input:
synonyms =3
happy joy
sad sorrow
joy cheerful
I am happy today but was sad yesterday

Output:
[I am cheerful today but was sad yesterday,
I am cheerful today but was sorrow yesterday,
I am happy today but was sad yesterday,
I am happy today but was sorrow yesterday,
I am joy today but was sad yesterday,
I am joy today but was sorrow yesterday]
*/

#include <bits/stdc++.h>
#define N 1000
using namespace std;

int n,l;
map<string,vector<string> > m;
string x,y;
vector<string> s;
set<string> ans;
map<pair<int,string>,bool> vis;

void rec(int pos, string wd, string cur)
{
    if(pos==l)
    {
        ans.insert(cur);
        return;
    }
    if(vis[{pos,wd}]) return;
    vis[{pos,wd}]=1;
    for(string c: m[wd])
    {
        if(!vis[{pos,c}]) rec(pos,c,cur);
    }
    if(pos+1==l) rec(pos+1,"",cur+" "+wd);
    else rec(pos+1,s[pos+1],cur+" "+wd);
    vis[{pos,wd}]=0;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    while(cin>>x) s.push_back(x);
    l=s.size();
    rec(0,s[0],"");
    for(string k: ans) cout<<k<<'\n';   
}