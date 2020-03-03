/*
Given a positive integer n, 
find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) 
which sum to n.

Example 1:
    Input: 12
    Output: 3 
    Explanation: 12 = 4 + 4 + 4.

Example 2:
    Input: 13
    Output: 2
    Explanation: 13 = 4 + 9.
*/

#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

int main()
{
    int n; cin>>n;
    int dp[n+1]; for(int i=1;i<=n;i++) dp[i]=INF; dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int c=1;
        while(i-c*c>=0) dp[i]=min(dp[i],dp[i-c*c]+1),c++;
    }
    cout<<dp[n]<<'\n';
}