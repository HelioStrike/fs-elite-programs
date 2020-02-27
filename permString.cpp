/*
Write a program to print all permutations of a given string

Example-1:
    Input=  ABC
    Output= ABC ACB BAC BCA CBA CAB

Example-2:
    Input=  aaa                                                                                                                     
    Output= aaa aaa aaa aaa aaa aaa                                                                                                 
   
Note:
input String contains [A-Za-z]
print output in lexicographic order
*/

#include <bits/stdc++.h>
#define N 20
using namespace std;

int n;
string s;
bool vis[N];
vector<string> ans;

void perm(string curs,int cur) 
{
    if(cur==n)
    {
        ans.push_back(curs);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            perm(curs+s[i],cur+1);
            vis[i]=0;
        }
    }
}

int main()
{
    cin>>s; n=s.length();
    perm("",0);
    sort(ans.begin(),ans.end());
    for(string x: ans) cout<<x<<' ';
    cout<<'\n';
}