/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary 

Example 1:
	Input: 3
		9 9 4
		6 6 8
		2 1 1
	Output: 4 
	Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
	Input: nums = 3
			3 4 5
			3 2 6
			2 2 1
	Output: 4 
	Explanation: The longest increasing path is [3, 4, 5, 6]. 
	Moving diagonally is not allowed.
*/

#include <bits/stdc++.h>
#define N 10
using namespace std;

int n,m[N][N],vis[N][N];

int dfs(int i,int j)
{
    if(vis[i][j]) return vis[i][j];
    vis[i][j]=1;
    if(i>0 && m[i-1][j]>m[i][j]) vis[i][j]=max(vis[i][j],dfs(i-1,j)+1);
    if(j>0 && m[i][j-1]>m[i][j]) vis[i][j]=max(vis[i][j],dfs(i,j-1)+1);
    if(i<n-1 && m[i+1][j]>m[i][j]) vis[i][j]=max(vis[i][j],dfs(i+1,j)+1);
    if(j<n-1 && m[i][j+1]>m[i][j]) vis[i][j]=max(vis[i][j],dfs(i,j+1)+1);
    return vis[i][j];
}

int main()
{
    cin>>n; int ans=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>m[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) ans=max(ans,dfs(i,j));
    cout<<ans<<'\n';
    return 0;
}