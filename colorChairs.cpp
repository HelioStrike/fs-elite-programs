/*
There are a row of n chairs, each chair can be painted with 
one of the three colors: red, blue or green. 

The cost of painting each chair with a certain color is different. 
You have to paint all the chairs such that no two adjacent chairs have the same color.

The cost of painting each chair with a certain color is represented by a n x 3 cost matrix. 
For example, costs[0][0] is the cost of painting chair 0 with color red; 
costs[1][2] is the cost of painting chair 1 with color green, and so on... 
Find the minimum cost to paint all chairs.

Note:
All costs are positive integers.

Example:

Input=	3
			17 2 17
			16 16 5
			14 3 19
Output= 10
Explanation: Paint chair 0 into blue, paint chair 1 into green, paint chair 2 into blue. 
 Minimum cost: 2 + 5 + 3 = 10.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n+1][3],dp[n+1][3];
    for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin>>a[i][j],dp[i][j]=INT_MAX;
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(j!=k) dp[i][j]=min(dp[i][j],dp[i-1][k]+a[i][j]);
            }
        }
    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<'\n';
    return 0;
}