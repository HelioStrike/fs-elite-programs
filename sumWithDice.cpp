/*

Given you few dices (c) , and each die has 'n' faces numbered 1, 2, ..., n.

You have to find the number of possible ways, when you roll all the dices, 
the sum of the face up numbers equals to given target.

You have to return the output as, possible ways (out of POW(n,c) total ways) modulo 10^9 + 7 

Input Format: enter 3 integers, indicates dicecount, no.of.faces and target
Output Format: an integer, indicates possible ways

Example 1:
		Input=	1	6	3
		Output=1
		Explanation: 
		You throw one dice with 6 faces.  There is only one way to get a sum of 3.

Example 2:

		Input=	2	6	7
		Output=6
		Explanation: 
		You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
		1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:

		Input=	2	5	10
		Output=1
		Explanation: 
		You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.

Example 4:
		Input=	1	2	3
		Output=0
		Explanation: 
		You throw one dice with 2 faces.  There is no way to get a sum of 3.
*/

#include <bits/stdc++.h>
#define T 100
using namespace std;

int n,f,t,c;
int dp[2][T];

int main()
{
    cin>>n>>f>>t;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        c=i%2;
        memset(dp[c],0,sizeof(dp[c]));
        for(int j=1;j<=t;j++)
        {
            for(int k=1;k<=f;k++) 
            {
                if(j<k) break;
                dp[c][j]+=dp[c^1][j-k];
            }
        }
    }
    
    cout<<dp[n%2][t]<<'\n';
}