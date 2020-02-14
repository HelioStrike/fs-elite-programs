/*
 * 
 You are given coins of different denominations and a total amount of money amount. 
 Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: 1 2 5
11
Output: 3 

Explanation: 11 = 5 + 5 + 1

Example 2:

Input: 2
3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.





 */

#include <bits/stdc++.h>
#define D 1000
using namespace std;

int x,d,dp[D];
vector<int> v;

int main()
{
      while(cin>>x) v.push_back(x);
      d=x; v.pop_back();
        int inf=999999;
        for(int i=1;i<D;i++) dp[i]=inf;
        
      dp[0]=0;
      for(int i=1;i<=d;i++)
      {
          for(int k: v)
          {
              if(i-k>=0) dp[i]=min(dp[i],dp[i-k]+1);
          }
      }
      cout<<(dp[d]==inf?-1:dp[d])<<'\n';
}