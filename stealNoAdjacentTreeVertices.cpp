/*
The robber has found himself a new place for his robbery again. 
There is only one entrance to this area, called the "root." 

Besides the root, each shop has one and only one parent shop. 
After a tour, the smart robber realized that "all shops in this place forms a binary tree". 
It will automatically contact the police if two directly-linked shops were broken into on the same night.

Determine the maximum amount of money the robber can rob tonight without alerting the police.



Note: -1 represents "no node"

Sample Input 1:     
7
13 12 13 -1 13 -1 11

Sample Output 1: 
37

Explanation: 
     13
    / \
   12  13
    \   \ 
     13  11
Maximum amount of money the robber can rob = 13 (root)+ 13(leaf) + 11 (leaf) = 37.

================================================================================

Sample Input 2: 
7
13 14 15 11 13 -11 11

Sample Output 2: 
29

Explanation: 

     13
    / \
  14   15
  / \   \ 
 11 13   11

Maximum amount of money the robber can rob = 14 + 15  = 29.
*/

#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define N 1010
using namespace std;

int n,a[N],dp[N][2];

void rec(int u)
{
    if(u>=n || a[u]==-1) return;
    rec(2*u+1); rec(2*u+2);
    dp[u][0]=max(dp[2*u+1][0],dp[2*u+1][1])+max(dp[2*u+2][0],dp[2*u+2][1]);
    dp[u][1]=a[u]+dp[2*u+1][0]+dp[2*u+2][0];
}

int main()
{
    cin>>n; FOR(i,0,n) cin>>a[i];
    rec(0);
    cout<<max(dp[0][0],dp[0][1])<<'\n';
}