/*
Given N technologies, labelled from 1 to N.

We are given relations[i] = [A, B], representing a prerequisite relationship between technology A and technology B: 
technology A has to be Completed before learning technology B.

In one month you can learn any number of technologies as long as you have completed all the 
prerequisites for learning that technology.

Return the minimum number of months needed to learn all technologies.  
If there is no way to learn all the technologies, return -1.


Input Format:   an integerer n, in First line indicates no of technologies
                an integer k, second line  no.of. prerequisite relations.
                next 'k' lines indicates prerequisite relation of technology
Output Format:  no of months required to finish all technologies if possible, otherwise -1.
Example 1:

Input=  3       //no of technologies
        2       //no.of prerequisite relations
        1 3     //to learn technology-3 prerequisite is technology-1
        2 3     //to learn technology-3 prerequisite is technology-2
Output= 2
Explanation: 
In the first month, technology 1 and 2 are completed. In the second month, technology 3 is completed.


Example 2:

Input=  3       //no of technologies
        3       //no.of prerequisite relations
        1 2     //to learn technology-2 prerequisite is technology-1
        2 3     //to learn technology-3 prerequisite is technology-2
        3 1     //to learn technology-1 prerequisite is technology-3
Output= -1
Explanation: 
No technology can be learned because they depend on each other.
*/

#include <bits/stdc++.h>
#define pii pair<int,int>
#define N 100
using namespace std;

int n,e,x,y,sn,ans,vis[N],rnk[N];
vector<int> g[N];
queue<pii> q;

int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y; rnk[y]++;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++) if(!rnk[i]) q.push({i,1});
    while(!q.empty())
    {
        pii i=q.front(); q.pop();
        if(vis[i.first]) continue;
        vis[i.first]=1; sn++;
        for(int v: g[i.first]) 
        {
            rnk[v]--;
            if(!vis[v] && rnk[v]==0) q.push({v,i.second+1});        
        }
        ans=max(ans,i.second);
    }
    cout<<(sn==n?ans:-1)<<'\n';
}