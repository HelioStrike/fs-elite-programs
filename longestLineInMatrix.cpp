/*
Given a matrix consists of only 0's and 1's s 
Find the longest line of consecutive one in the matrix. 
The line could be horizontal, vertical, or any diagonal.

Example:
Input:3 3
0 1 1 0
0 1 1 0
0 0 0 1
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    int mp[n][m]; for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mp[i][j];
    int ans=0,cur;
    for(int i=0;i<n;i++) 
    {
        cur=0;
        for(int j=0;j<m;j++) 
        {
            if(mp[i][j]==0) {
                cur=0;
                continue;
            }
            cur++;
            ans=max(ans,cur);
        }
    }
    for(int i=0;i<m;i++) 
    {
        cur=0;
        for(int j=0;j<n;j++) 
        {
            if(mp[j][i]==0) {
                cur=0;
                continue;
            }
            cur++;
            ans=max(ans,cur);
        }
    }
    for(int i=0;i<n;i++)
    {
        int k=i; int j=0; cur=0;
        while(k<n && j<m)
        {
            if(mp[k][j]==0) cur=0;
            else {
                cur++;
                ans=max(ans,cur);
            }
            k++; j++;
        }
    }
    for(int i=0;i<m;i++)
    {
        int k=i; int j=0; cur=0;
        while(k<m && j<n)
        {
            if(mp[j][k]==0) cur=0;
            else {
                cur++;
                ans=max(ans,cur);
            }
            k++; j++;
        }
    }
    for(int i=0;i<n;i++)
    {
        int k=i; int j=0; cur=0;
        while(k>=0 && j<m)
        {
            if(mp[k][j]==0) cur=0;
            else {
                cur++;
                ans=max(ans,cur);
            }
            k--; j++;
        }
    }
    for(int i=0;i<m;i++)
    {
        int k=i; int j=0; cur=0;
        while(k>=0 && j<n)
        {
            if(mp[j][k]==0) cur=0;
            else {
                cur++;
                ans=max(ans,cur);
            }
            k--; j++;
        }
    }
    cout<<ans<<'\n';
}