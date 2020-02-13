/*
 * 
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak 
such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers 
as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: 1 2 3 4

Output: False

Explanation: There is no  pattern in the sequence.
Example 2:
Input: 3 1 4 2

Output: True

Explanation: There is a pattern in the sequence: [1, 4, 2].
Example 3:
Input: -1 3 2 0

Output: True

Explanation: There are three patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

 */

#include <bits/stdc++.h>
#define N 100
using namespace std;

int n,x,ans,a[N];

int main()
{
    while(cin>>x) a[n++]=x;
    int minm=INT_MAX,pminm=INT_MAX,maxm=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]<maxm && a[i]>pminm) { ans=1; break; }
        if(a[i]>maxm)
        {
            maxm=a[i];
            pminm=minm;
        }
        minm=min(minm,a[i]);
    }
    cout<<(ans?"True":"False")<<'\n';
}