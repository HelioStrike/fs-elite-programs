/*
 * 
 Given a R * C matrix of integers, sort matrix diagonally in ascending order from the top-left 
 to the bottom-right then return the sorted array.

 

Example 1:


Input:4 4
6 5 7 8 
1 2 3 4
5 6 7 8
9 6 3 2

Output: 
2 3 4 8 
1 2 5 7 
5 3 6 8 
9 6 6 7

==========================================================

Explanation
A[i][j] on the same diagonal have same value of i - j
For each diagonal,
put its elements together, sort, and set them back.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r,c,cur; cin>>r>>c;
    int a[r][c]; for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>a[i][j];
    for(int i=0;i<r;i++)
    {
        int i1=i,j=0;
        vector<int> v;
        while(i1<r && j<c)
        {
            v.push_back(a[i1][j]);
            i1++,j++;
        }
        sort(v.begin(),v.end());
        i1=i,j=0,cur=0;
        while(i1<r && j<c)
        {
            a[i1][j]=v[cur++];
            i1++,j++;
        }
    }
    for(int i=0;i<c;i++)
    {
        int i1=i,j=0;
        vector<int> v;
        while(i1<c && j<r)
        {
            v.push_back(a[j][i1]);
            i1++,j++;
        }
        sort(v.begin(),v.end());
        i1=i,j=0,cur=0;
        while(i1<c && j<r)
        {
            a[j][i1]=v[cur++];
            i1++,j++;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    
}