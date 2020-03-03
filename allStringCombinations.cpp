/*
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  
Return the number of possible non-empty sequences of letters you can make.


Example 1:
Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: "AAABBC"
Output: 188

 
Note:
    1 <= tiles.length <= 7
    tiles consists of uppercase English letters.

*/

#include <bits/stdc++.h>
#define N 100
using namespace std;

int tl;
string t;
set<string> s;
bool vis[N];

void rec(int cur, string curs)
{
    if(cur==tl)
    {
        s.insert(curs);
        return;
    }
    rec(cur+1,curs);
    for(int i=0;i<tl;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            rec(cur+1,curs+t[i]);
            vis[i]=0;        
        }
    }
}

int main()
{
    cin>>t; tl=t.length();
    rec(0,"");
    cout<<s.size()-1<<'\n';
    
    return 0;
}
