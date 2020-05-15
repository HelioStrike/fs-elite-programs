/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, 
 where in each step you can delete one character in either string.

Example 1:
Input:sea
eat
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t; cin>>s>>t;
    int n=s.length(),m=t.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<(n+m-2*dp[n][m])<<'\n';
    return 0;
}