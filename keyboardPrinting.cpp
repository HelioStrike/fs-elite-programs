/*
There is a keyboard consists of following keys only,

Key 1: (S): Print one 'S' on screen.
Key 2: (Ctrl-S): Select the whole screen.
Key 3: (Ctrl-C): Copy selection to buffer.
Key 4: (Ctrl-P): Print buffer on screen appending it after what has already been printed.

Now, you can only press the keyboard for N times (with the above four keys), 
find out the maximum numbers of 'S' you can print on screen.

Example 1:
Input:3
Output: 3
Explanation: 
We can at most get 3 S's on screen by pressing following key sequence:
S, S, S

Example 2:
Input: 7
Output: 9
Explanation: 
We can at most get 9 S's on screen by pressing following key sequence:
S, S, S, Ctrl-S, Ctrl-C, Ctrl-P, Ctrl-P
*/


#include <bits/stdc++.h>
#define N 200
using namespace std;

/*
//Passes 4/6 cases

int n,ans,dp[N][N];

int main()
{
    cin>>n;
   
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dp[i][j]=-1;
    dp[0][0]=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<N;j++) 
        {
            if(dp[i][j]>-1)
            {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+j);
                dp[i+2][dp[i][j]]=max(dp[i+2][dp[i][j]],dp[i][j]);
            }
        }
    }
    
    for(int i=0;i<N;i++) ans=max(ans,dp[n][i]);
    cout<<ans<<'\n';
}
*/

//Solution by Mohit!!!

int n,dp[N];

int rec(int x)
{
    if(x<=6) return x;
    if(dp[x]) return dp[x];
    int ret=0;
    for(int i=n-3;i>=1;i--) ret=max(ret,(n-i-1)*rec(i));
    return (dp[x]=ret);
}

int main()
{
    cin>>n;
    cout<<rec(n)<<'\n';
}