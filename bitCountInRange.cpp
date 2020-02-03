/*
Given two positive integer number start,end. (start ≤ end)
For every numbers i in the range start ≤ i ≤ end 
calculate the number of 1's in their binary representation 
and return them as an array.

Example 1:
    Input: 0 2
    Output: 0 1 1

Example 2:
    Input:3 7
    Output: 2 1 2 2 3

NOTE:
Do not use bitCount() or other default methods.

can you get the solution with linear time O(n)?
*/

#include <bits/stdc++.h>
#define N 1000
using namespace std;

int l,r,dp[N];

int main()
{
    cin>>l>>r;
    for(int i=1;i<=r;i++) dp[i]+=dp[i>>1]+(i&1);
    for(int i=l;i<=r;i++) cout<<dp[i]<<' ';
    cout<<'\n';
}