/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing only 1's  and return its area.

Example:
    Input: 4
    5
    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    Output: 4
*/

#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main()
{
    int n,ans; cin>>r>>c ans=0;
    int m[r][c],dp[r][c];
    FOR(i,0,r) FOR(j,0,c) cin>>m[i][j];
    FOR(i,0,r)
    {
        FOR(j,0,c)
        {
            dp[i][j]=m[i][j];
            if(i>0 && j>0) dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans*ans<<'\n';
}